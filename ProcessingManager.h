#pragma once
#include"Reference.h"
#include"Camera.h"
#include"Map.h"
#include"Player.h"

using namespace Lib;

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
		/// �S�Ă̍X�V����
		/// </summary>
		/// <param name="deltaTime"></param>
		void AllUpdate(float deltaTime);

		/// <summary>
		/// �S�Ă̕`�揈��
		/// </summary>
		void AllDraw();

	private:
		Camera* camera;
		Map* map;
		Player* player;
		PlayerShot* playerShot[bulletNum] = { nullptr };
	};
}