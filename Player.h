#pragma once
#include"DxLib.h"

namespace App
{
	/// <summary>
	/// �v���C���[
	/// </summary>
	class Player
	{
	public:
		Player();
		~Player();

		void Update(float deltaTime);
		void Draw();

	private:
		VECTOR mPos;			// ���W
		int mModelHandle[1];	// ���f���n���h��(0�F�{�f�B, 1�F�C�g)
		int getMousePointX;		// �}�E�X��X���W
		int getMousePointY;		// �}�E�X��Y���W
		float directionX;
		float directionY;
		float radian;
		float degree;
	};
}