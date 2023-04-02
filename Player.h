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
		void MovableRange();

		VECTOR mPos;			// 座標
		int mBodyModelHandle;	// ボディモデルハンドル
		int mHeadModelHandle;	// 砲身モデルハンドル
		float mSpeed;			// 速度
		float moveX;	// Xの移動量
		float moveY;	// Yの移動量

		VECTOR mMousePoint;
		int getMousePointX;		// マウスのX座標
		int getMousePointY;		// マウスのY座標
		int cursorGraphHandle;	// マウスカーソルのグラフハンドル
		float directionX;
		float directionY;
		float radian;
		float degree;
	};
}