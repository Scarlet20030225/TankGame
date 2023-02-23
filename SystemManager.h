#pragma once
#include"DxLib.h"

namespace App
{
	class SystemManager
	{
	public:
		/// <summary>
		/// コンストラクタ
		/// </summary>
		SystemManager();
		/// <summary>
		/// デストラクタ
		/// </summary>
		~SystemManager();
		/// <summary>
		/// ゲームループ
		/// </summary>
		void Loop();
		/// <summary>
		/// ファイナライズ
		/// </summary>
		void Finalize();

	private:

	};
}