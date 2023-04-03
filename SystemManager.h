#pragma once
#include"DxLib.h"
#include"ProcessingManager.h"

namespace App
{
	/// <summary>
	/// システムのマネージャー
	/// </summary>
	class SystemManager
	{
	public:
		SystemManager();
		~SystemManager();

		/// <summary>
		/// ゲームループ
		/// </summary>
		void Loop();

		/// <summary>
		/// 終了処理
		/// </summary>
		void Finalize();

	private:
		ProcessingManager* processingManager;
	};
}