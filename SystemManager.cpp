#include<chrono>
#include<thread>
#include"SystemManager.h"
#include"Reference.h"

using namespace Lib;

namespace App
{
	SystemManager::SystemManager()
	{
		ChangeWindowMode(TRUE);
		SetGraphMode(screenSizeX, screenSizeY, colorBitDepth);
		DxLib_Init();

	//---------------------------------------------------------------------------------------------------------
	// 初期化処理
	//---------------------------------------------------------------------------------------------------------
		processingManager = new App::ProcessingManager();
	}

	SystemManager::~SystemManager()
	{
		processingManager->~ProcessingManager();

		delete processingManager;
		processingManager = nullptr;
	}

	void SystemManager::Loop()
	{
		while (ProcessMessage() == 0)
		{
			// 処理開始時刻を所得
			auto start = std::chrono::system_clock::now();

		//---------------------------------------------------------------------------------------------------------
		// 更新処理
		//---------------------------------------------------------------------------------------------------------
			processingManager->AllUpdate(deltaTime);

			// 画面更新
			ClearDrawScreen();

		//---------------------------------------------------------------------------------------------------------
		// 描画処理
		//---------------------------------------------------------------------------------------------------------
			processingManager->AllDraw();

			// 描画を確定
			ScreenFlip();

			// 1フレームにかかった時間を計算
			auto end = std::chrono::system_clock::now();
			auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

			// 1フレームにかかった時間が指定の時間(deltaTime)以下であれば待機する
			if (elapsed.count() < deltaTime)
			{
				std::this_thread::sleep_for(std::chrono::milliseconds(deltaTime - elapsed.count()));
			}

			// ESCAPEキーが押されたらループを抜ける
			if (GetAsyncKeyState(VK_ESCAPE) & 0x8000)
			{
				break;
			}
		}
	}

	void SystemManager::Finalize()
	{
		DxLib_End();
	}
}