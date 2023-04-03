#pragma once
#include"DxLib.h"

namespace App
{
	/// <summary>
	/// プレイヤーの弾
	/// </summary>
	class PlayerShot
	{
	public:
		PlayerShot();
		~PlayerShot();

		void Update(float deltaTime);
		void Draw();

		void OnShot(float playerX, float playerY, float playerZ);
		const bool IsActive();

	private:
		VECTOR mPos;
		int mModelHandle;
		int bulletNum;
		float moveX;
		float moveY;
		float mSpeed;

		VECTOR mMousePoint;
		VECTOR direction;
		float distance;
		int getMousePointX;		// マウスのX座標
		int getMousePointY;		// マウスのY座標

		bool activeBullet;
	};
}