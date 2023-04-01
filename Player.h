#pragma once
#include"DxLib.h"

namespace App
{
	/// <summary>
	/// プレイヤー
	/// </summary>
	class Player
	{
	public:
		Player();
		~Player();

		void Update(float deltaTime);
		void Draw();

	private:
		VECTOR mPos;			// 座標
		int mModelHandle[1];	// モデルハンドル(0：ボディ, 1：砲身)
		int getMousePointX;		// マウスのX座標
		int getMousePointY;		// マウスのY座標
		float directionX;
		float directionY;
		float radian;
		float degree;
	};
}