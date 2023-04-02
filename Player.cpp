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
		MV1SetMaterialEmiColor(mBodyModelHandle, 0, GetColorF(0.0f, 0.0f, 1.0f, 1.0f));		// 色を青色に
		MV1SetMaterialEmiColor(mHeadModelHandle, 0, GetColorF(0.0f, 0.0f, 1.0f, 1.0f));		// 色を青色に

		cursorGraphHandle = LoadGraph("data/Graph/Scope.png");

		mPos = VGet(960.0f, 540.0f, 0.0f);
		SetMousePoint(setMousePointX, setMousePointY);

		moveX = 0.0f;
		moveY = 0.0f;
		mSpeed = playerSpeed;
	}

	Player::~Player()
	{
	}
	
	void Player::Update(float deltaTime)
	{
		bool input = false;	// 移動キーの入力があるか？
		
		// 上移動
		if (GetAsyncKeyState(VK_UP) & 0x8000)
		{
			moveY = +mSpeed;
			input = true;
		}
		// 下移動
		if (GetAsyncKeyState(VK_DOWN) & 0x8000)
		{
			moveY = -mSpeed;
			input = true;
		}
		// 右移動
		if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
		{
			moveX = +mSpeed;
			input = true;
		}
		// 左移動
		if (GetAsyncKeyState(VK_LEFT) & 0x8000)
		{
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

		MV1SetPosition(mBodyModelHandle, mPos);
		MV1SetPosition(mHeadModelHandle, mPos);

		GetMousePoint(&getMousePointX, &getMousePointY);
		mMousePoint = ConvScreenPosToWorldPos(VGet((float)getMousePointX, (float)getMousePointY, 0.99949975f));

		directionX = mMousePoint.x - mPos.x;
		directionY = mMousePoint.y - mPos.y;
		radian = atan2f(directionY, directionX);
		degree = radian * 180 / DX_PI_F;
	}

	void Player::Draw()
	{
		DrawFormatString(0, 0, GetColor(255, 255, 255), "Mouse: (%f, %f, %f)", mMousePoint.x, mMousePoint.y, mMousePoint.z);
		DrawFormatString(0, 20, GetColor(255, 255, 255), "Player: (%f, %f, %f)", mPos.x, mPos.y, mPos.z);
		DrawFormatString(0, 40, GetColor(255, 255, 255), "Degree: %.2f", degree);

		DrawLine3D(mPos, mMousePoint, GetColor(0, 255, 192));

		MV1DrawModel(mBodyModelHandle);	// モデルを描画
		MV1DrawModel(mHeadModelHandle);	// モデルを描画

		DrawGraph3D(mMousePoint.x, mMousePoint.y, 0.0f, cursorGraphHandle, TRUE);
	}
}