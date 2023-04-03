#include<math.h>
#include<cmath>
#include"Player.h"
#include"Reference.h"

using namespace Lib;

namespace App
{
	Player::Player()
	{
		mBodyModelHandle = MV1LoadModel("data/Model/TankBody.mv1");
		mHeadModelHandle = MV1LoadModel("data/Model/TankHead.mv1");
		MV1SetScale(mBodyModelHandle, VGet(1.5f, 1.5f, 1.5f));
		MV1SetScale(mHeadModelHandle, VGet(1.5f, 1.5f, 1.5f));
		MV1SetMaterialEmiColor(mBodyModelHandle, 0, GetColorF(0.0f, 0.0f, 1.0f, 1.0f));		// 胴体の色を青色に
		MV1SetMaterialEmiColor(mHeadModelHandle, 0, GetColorF(0.0f, 0.0f, 1.0f, 1.0f));		// 砲身の色を青色に

		cursorGraphHandle = LoadGraph("data/Graph/Scope.png");

		mPos = VGet(960.0f, 540.0f, 0.0f);
		SetMousePoint(setMousePointX, setMousePointY);

		moveX = 0.0f;
		moveY = 0.0f;
		mSpeed = speed;

		mShotInterval = 0.0f;
	}

	Player::~Player()
	{
	}

	void Player::MovableRange()
	{
		if (mPos.x <= 110)
		{
			mPos.x = 110;
		}
		if (mPos.x >= 1805)
		{
			mPos.x = 1805;
		}
		if (mPos.y <= 120)
		{
			mPos.y = 120;
		}
		if (mPos.y >= 840)
		{
			mPos.y = 840;
		}
	}

	void Player::Update(float deltaTime, PlayerShot* playerShot[])
	{
		bool input = false;	// 移動キーの入力があるか？
		
		// 上移動
		if (GetAsyncKeyState(VK_UP) & 0x8000)
		{
			MV1SetRotationXYZ(mBodyModelHandle, VGet(0.0f, 0.0f, 90.0f * DX_PI_F / 180.0f));
			moveY = +mSpeed;
			input = true;
		}
		// 下移動
		if (GetAsyncKeyState(VK_DOWN) & 0x8000)
		{
			MV1SetRotationXYZ(mBodyModelHandle, VGet(0.0f, 0.0f, 270.0f * DX_PI_F / 180.0f));
			moveY = -mSpeed;
			input = true;
		}
		// 右移動
		if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
		{
			moveX = +mSpeed;
			input = true;
			MV1SetRotationXYZ(mBodyModelHandle, VGet(0.0f, 0.0f, 0.0f));
		}
		// 左移動
		if (GetAsyncKeyState(VK_LEFT) & 0x8000)
		{
			MV1SetRotationXYZ(mBodyModelHandle, VGet(0.0f, 0.0f, 180.0f * DX_PI_F / 180.0f));
			moveX = -mSpeed;
			input = true;
		}

		// 入力があった時
		if (input)
		{
			// 上下or左右の同時入力を確認すると入力をしなかったことにする
			if (GetAsyncKeyState(VK_RIGHT) & 0x8000 && GetAsyncKeyState(VK_LEFT) & 0x8000		// 左右同時入力時
				|| GetAsyncKeyState(VK_UP) & 0x8000 && GetAsyncKeyState(VK_DOWN) & 0x8000)	// 上下同時入力時
			{
				input = false;
			}

			// 斜め移動時のモデルの向きを調整
			if (GetAsyncKeyState(VK_UP) & 0x8000 && GetAsyncKeyState(VK_RIGHT) & 0x8000)	// 右斜め上移動時
			{
				MV1SetRotationXYZ(mBodyModelHandle, VGet(0.0f, 0.0f, 45.0f * DX_PI_F / 180.0f));
			}
			if (GetAsyncKeyState(VK_UP) & 0x8000 && GetAsyncKeyState(VK_LEFT) & 0x8000)		// 左斜め上移動時
			{
				MV1SetRotationXYZ(mBodyModelHandle, VGet(0.0f, 0.0f, 135.0f * DX_PI_F / 180.0f));
			}
			if (GetAsyncKeyState(VK_DOWN) & 0x8000 && GetAsyncKeyState(VK_RIGHT) & 0x8000)	// 右斜め下移動時
			{
				MV1SetRotationXYZ(mBodyModelHandle, VGet(0.0f, 0.0f, 315.0f * DX_PI_F / 180.0f));
			}
			if (GetAsyncKeyState(VK_DOWN) & 0x8000 && GetAsyncKeyState(VK_LEFT) & 0x8000)	// 左斜め下移動時
			{
				MV1SetRotationXYZ(mBodyModelHandle, VGet(0.0f, 0.0f, 225.0f * DX_PI_F / 180.0f));
			}

			float length = sqrtf(moveX * moveX + moveY * moveY);
			moveX /= length;
			moveY /= length;

			moveX *= deltaTime;
			moveY *= deltaTime;
		}
		else
		{
			moveX = 0.0f;
			moveY = 0.0f;
		}

		// 座標更新(プレイヤー本体)
		mPos.x += moveX;
		mPos.y += moveY;

		MovableRange();

		MV1SetPosition(mBodyModelHandle, mPos);
		MV1SetPosition(mHeadModelHandle, mPos);

		GetMousePoint(&getMousePointX, &getMousePointY);
		mMousePoint = ConvScreenPosToWorldPos(VGet((float)getMousePointX, (float)getMousePointY, 0.99949975f));

		directionX = mMousePoint.x - mPos.x;
		directionY = mMousePoint.y - mPos.y;
		radian = atan2f(directionY, directionX);

		MV1SetRotationXYZ(mHeadModelHandle, VGet(0.0f, 0.0f, radian));


		// 弾を発射
		if (GetMouseInput() & MOUSE_INPUT_LEFT)
		{
			if (mShotInterval == 0.0f)
			{
				for (int i = 0; i < bulletNum; i++)
				{
					if (!playerShot[i]->IsActive())
					{
						playerShot[i]->OnShot(mPos.x, mPos.y, mPos.z);

						break;
					}
				}
				mShotInterval = shotInterval;
			}
		}

		if (mShotInterval != 0.0f)
		{
			--mShotInterval;
		}
	}

	void Player::Draw()
	{
		DrawFormatString(0, 0, GetColor(255, 255, 255), "マウスカーソル座標： (%f, %f, %f)", mMousePoint.x, mMousePoint.y, mMousePoint.z);
		DrawFormatString(0, 20, GetColor(255, 255, 255), "プレイヤー座標：(%f, %f, %f)", mPos.x, mPos.y, mPos.z);

		DrawLine3D(mPos, mMousePoint, GetColor(0, 255, 192));

		MV1DrawModel(mBodyModelHandle);	// モデルを描画
		MV1DrawModel(mHeadModelHandle);	// モデルを描画

		DrawGraph3D(mMousePoint.x, mMousePoint.y, 0.0f, cursorGraphHandle, TRUE);
	}
}