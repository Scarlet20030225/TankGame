#pragma once
#include"DxLib.h"
#include"ProcessingManager.h"

namespace App
{
	/// <summary>
	/// �V�X�e���̃}�l�[�W���[
	/// </summary>
	class SystemManager
	{
	public:
		SystemManager();
		~SystemManager();

		/// <summary>
		/// �Q�[�����[�v
		/// </summary>
		void Loop();

		/// <summary>
		/// �I������
		/// </summary>
		void Finalize();

	private:
		ProcessingManager* processingManager;
	};
}