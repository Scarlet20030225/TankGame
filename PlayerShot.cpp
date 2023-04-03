#include<math.h>
#include<cmath>
#include"PlayerShot.h"
#include"Reference.h"

using namespace Lib;

namespace App
{
	PlayerShot::PlayerShot()
	{
		mModelHandle = MV1LoadModel("data/Model/Bullet.mv1");
		MV1SetMaterialEmiColor(mModelHandle, 0, GetColorF(1.0f, 1.0f, 1.0f, 1.0f));		// 色を白色に
		activeBullet = false;
		mSpeed = bulletSpeed;

		SetMousePoint(setMousePointX, setMousePointY);
	}

	PlayerShot::~PlayerShot()
	{
	}

	void PlayerShot::Update(float deltaTime)
	{
		if (GetMouseInput() & MOUSE_INPUT_LEFT)
		{
			GetMousePoint(&getMousePointX, &getMousePointY);
			mMousePoint = ConvScreenPosToWorldPos(VGet((float)getMousePointX, (float)getMousePointY, 0.99949975f));
		}

		if (activeBullet)
		{
			direction.x = mMousePoint.x - mPos.x;
			direction.y = mMousePoint.y - mPos.y;
			distance = sqrt(direction.x * direction.x + direction.y * direction.y);
			moveX = direction.x / distance * mSpeed * deltaTime;
			moveY = direction.y / distance * mSpeed * deltaTime;

			mPos.x += moveX;
			mPos.y += moveY;
			
			MV1SetPosition(mModelHandle, mPos);
		}
	}

	void PlayerShot::Draw()
	{
		if (activeBullet)
		{
			MV1DrawModel(mModelHandle);
		}
		DrawFormatString(0, 40, GetColor(255, 255, 255), "マウスカーソル座標2： (%f, %f, %f)", mMousePoint.x, mMousePoint.y, mMousePoint.z);
	}

	void PlayerShot::OnShot(float playerX, float playerY, float playerZ)
	{
		mPos.x = playerX;
		mPos.y = playerY;
		mPos.z = playerZ;

		activeBullet = true;
	}

	const bool PlayerShot::IsActive()
	{
		return activeBullet;
	}
}