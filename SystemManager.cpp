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
	// ����������
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
			// �����J�n����������
			auto start = std::chrono::system_clock::now();

		//---------------------------------------------------------------------------------------------------------
		// �X�V����
		//---------------------------------------------------------------------------------------------------------
			processingManager->AllUpdate(deltaTime);

			// ��ʍX�V
			ClearDrawScreen();

		//---------------------------------------------------------------------------------------------------------
		// �`�揈��
		//---------------------------------------------------------------------------------------------------------
			processingManager->AllDraw();

			// �`����m��
			ScreenFlip();

			// 1�t���[���ɂ����������Ԃ��v�Z
			auto end = std::chrono::system_clock::now();
			auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

			// 1�t���[���ɂ����������Ԃ��w��̎���(deltaTime)�ȉ��ł���Αҋ@����
			if (elapsed.count() < deltaTime)
			{
				std::this_thread::sleep_for(std::chrono::milliseconds(deltaTime - elapsed.count()));
			}

			// ESCAPE�L�[�������ꂽ�烋�[�v�𔲂���
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