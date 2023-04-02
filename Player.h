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
		void MovableRange();

		VECTOR mPos;			// ���W
		int mBodyModelHandle;	// �{�f�B���f���n���h��
		int mHeadModelHandle;	// �C�g���f���n���h��
		float mSpeed;			// ���x
		float moveX;	// X�̈ړ���
		float moveY;	// Y�̈ړ���

		VECTOR mMousePoint;
		int getMousePointX;		// �}�E�X��X���W
		int getMousePointY;		// �}�E�X��Y���W
		int cursorGraphHandle;	// �}�E�X�J�[�\���̃O���t�n���h��
		float directionX;
		float directionY;
		float radian;
		float degree;
	};
}