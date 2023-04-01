#include<math.h>
#include"Player.h"
#include"Reference.h"

using namespace Lib;

namespace App
{
	Player::Player()
	{
		SetMousePoint(setMousePointX, setMousePointY);

		mPos = VGet(960.0f, 540.0f, 0.0f);
	}

	Player::~Player()
	{
	}

	void Player::Update(float deltaTime)
	{
		GetMousePoint(&getMousePointX, &getMousePointY);

		directionX = getMousePointX - mPos.x;
		directionY = getMousePointY - mPos.y;
		radian = atan2f(directionY, directionX);
		degree = radian * 180 / DX_PI_F;
	}

	void Player::Draw()
	{
		DrawCircle(mPos.x, mPos.y, 10, GetColor(255, 255, 255));
		DrawLine(mPos.x, mPos.y, mPos.x + directionX, mPos.y + directionY, GetColor(255, 255, 255));
		DrawFormatString(0, 0, GetColor(255, 255, 255), "Mouse: (%d, %d)", getMousePointX, getMousePointY);
		DrawFormatString(0, 20, GetColor(255, 255, 255), "Player: (%d, %d)", mPos.x, mPos.y);
		DrawFormatString(0, 40, GetColor(255, 255, 255), "Degree: %.2f", degree);
	}
}