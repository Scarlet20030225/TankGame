#pragma once

namespace Lib
{
	/// <summary>
	/// �X�N���[����
	/// </summary>
	const float screenSizeX = 1920.0f;

	/// <summary>
	/// �X�N���[������
	/// </summary>
	const float screenSizeY = 1080.0f;

	/// <summary>
	/// �J���[�r�b�g��
	/// </summary>
	const int colorBitDepth = 32;

	/// <summary>
	/// �t���[�����[�g
	/// </summary>
	const int fps = 60;

	/// <summary>
	/// �҂�����
	/// </summary>
	const int deltaTime = 1000 / fps;

	/// <summary>
	/// ��O�N���b�v����
	/// </summary>
	const float cameraNear = 1.0f;

	/// <summary>
	/// ���N���b�v����
	/// </summary>
	const float cameraFar = 2000.0f;

	/// <summary>
	/// �J������Z���W
	/// </summary>
	const float cameraPosZ = -1000.0f;

	/// <summary>
	/// �J������Z���W�����_
	/// </summary>
	const float cameraGazingPosZ = 0.0f;
}