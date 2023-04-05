#pragma once
#include"DxLib.h"
#include"PlayerShot.h"

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

		void Update(float deltaTime, PlayerShot* playerShot[]);
		void Draw();

	private:
		/// <summary>
		/// 移動可能な範囲
		/// </summary>
		void MovableRange();

		VECTOR mPos;			// 座標
		int mBodyModelHandle;	// ボディモデルハンドル
		int mHeadModelHandle;	// 砲身モデルハンドル
		float mSpeed;			// 速度
		float moveX;			// Xの移動量
		float moveY;			// Yの移動量

		VECTOR mMousePoint;
		int getMousePointX;		// マウスのX座標
		int getMousePointY;		// マウスのY座標
		int cursorGraphHandle;	// マウスカーソルのグラフハンドル
		float directionX;		// プレイヤーとマウスカーソルのX座標の差
		float directionY;		// プレイヤーとマウスカーソルのY座標の差
		float radian;			// 角度算出
		float degree;

		float mShotInterval;
	};
}