#pragma once

namespace App
{
	/// <summary>
	/// �����̃}�l�[�W���[
	/// </summary>
	class ProcessingManager
	{
	public:
		ProcessingManager();
		~ProcessingManager();

		/// <summary>
		/// �S�Ă̏���������
		/// </summary>
		void AllInit();

		/// <summary>
		/// �S�Ă̍X�V����
		/// </summary>
		/// <param name="deltaTime"></param>
		void AllUpdate(float deltaTime);

		/// <summary>
		/// �S�Ă̕`�揈��
		/// </summary>
		void AllDraw();

	private:

	};
}