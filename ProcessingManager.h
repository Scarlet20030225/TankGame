#pragma once

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
		/// 全ての初期化処理
		/// </summary>
		void AllInit();

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

	};
}