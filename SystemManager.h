#pragma once
#include"DxLib.h"

namespace App
{
	class SystemManager
	{
	public:
		/// <summary>
		/// �R���X�g���N�^
		/// </summary>
		SystemManager();
		/// <summary>
		/// �f�X�g���N�^
		/// </summary>
		~SystemManager();
		/// <summary>
		/// �Q�[�����[�v
		/// </summary>
		void Loop();
		/// <summary>
		/// �t�@�C�i���C�Y
		/// </summary>
		void Finalize();

	private:

	};
}