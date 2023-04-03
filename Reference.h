#pragma once

namespace Lib
{
//-------------------------------------------------------------------------
// �E�B���h�E�֌W
//-------------------------------------------------------------------------
	/// <summary>
	/// �X�N���[����
	/// </summary>
	const int screenSizeX = 1920;

	/// <summary>
	/// �X�N���[������
	/// </summary>
	const int screenSizeY = 1080;

	/// <summary>
	/// �J���[�r�b�g��
	/// </summary>
	const int colorBitDepth = 32;

//-------------------------------------------------------------------------
// �t���[���֌W
//-------------------------------------------------------------------------
	/// <summary>
	/// �t���[�����[�g
	/// </summary>
	const int fps = 60;

	/// <summary>
	/// �҂�����
	/// </summary>
	const int deltaTime = 1000 / fps;

//-------------------------------------------------------------------------
// �J�����֌W
//-------------------------------------------------------------------------
	/// <summary>
	/// ��O�N���b�v����
	/// </summary>
	const float cameraNear = 1.0f;

	/// <summary>
	/// ���N���b�v����
	/// </summary>
	const float cameraFar = 2000.0f;

	/// <summary>
	/// �J������X���W
	/// </summary>
	const float cameraPosX = 960.0f;

	/// <summary>
	/// �J������Y���W
	/// </summary>
	const float cameraPosY = 540.0f;

	/// <summary>
	/// �J������Z���W
	/// </summary>
	const float cameraPosZ = -1000.0f;

	/// <summary>
	/// �J������X���W�����_
	/// </summary>
	const float cameraGazingPosX = 960.0f;

	/// <summary>
	/// �J������Y���W�����_
	/// </summary>
	const float cameraGazingPosY = 540.0f;

	/// <summary>
	/// �J������Z���W�����_
	/// </summary>
	const float cameraGazingPosZ = 0.0f;

//-------------------------------------------------------------------------
// �}�b�v�֌W
//-------------------------------------------------------------------------
	/// <summary>
	/// �x�[�X�ƂȂ�u���b�N�̐� X
	/// </summary>
	const int baseBlockX = 24;

	/// <summary>
	/// �x�[�X�ƂȂ�u���b�N�̐� Y
	/// </summary>
	const int baseBlockY = 10;

//-------------------------------------------------------------------------
// �R���g���[���[�֌W
//-------------------------------------------------------------------------
	/// <summary>
	/// �����̃}�E�XX���W
	/// </summary>
	const int setMousePointX = 960;

	/// <summary>
	/// �����̃}�E�XY���W
	/// </summary>
	const int setMousePointY = 540;

//-------------------------------------------------------------------------
// �X�e�[�^�X�֌W
//-------------------------------------------------------------------------
	/// <summary>
	/// �ړ����x
	/// </summary>
	const float speed = 1.0f;
}