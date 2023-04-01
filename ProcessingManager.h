#pragma once
#include"Camera.h"
#include"Map.h"
#include"Player.h"

namespace App
{
	/// <summary>
	/// 処理のマネージャー
	/// </summary>
	class ProcessingManager
	{
	public:
		ProcessingManager();
		~ProcessingManager();

		/// <summary>
		/// 全ての更新処理
		/// </summary>
		/// <param name="deltaTime"></param>
		void AllUpdate(float deltaTime);

		/// <summary>
		/// 全ての描画処理
		/// </summary>
		void AllDraw();

	private:
		Camera* camera;
		Map* map;
		Player* player;
	};
}