#pragma once
#include"DxLib.h"
#include"PlayerShot.h"

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

		void Update(float deltaTime, PlayerShot* playerShot[]);
		void Draw();

	private:
		/// <summary>
		/// �ړ��\�Ȕ͈�
		/// </summary>
		void MovableRange();

		VECTOR mPos;			// ���W
		int mBodyModelHandle;	// �{�f�B���f���n���h��
		int mHeadModelHandle;	// �C�g���f���n���h��
		float mSpeed;			// ���x
		float moveX;			// X�̈ړ���
		float moveY;			// Y�̈ړ���

		VECTOR mMousePoint;
		int getMousePointX;		// �}�E�X��X���W
		int getMousePointY;		// �}�E�X��Y���W
		int cursorGraphHandle;	// �}�E�X�J�[�\���̃O���t�n���h��
		float directionX;		// �v���C���[�ƃ}�E�X�J�[�\����X���W�̍�
		float directionY;		// �v���C���[�ƃ}�E�X�J�[�\����Y���W�̍�
		float radian;			// �p�x�Z�o
		float degree;

		float mShotInterval;
	};
}