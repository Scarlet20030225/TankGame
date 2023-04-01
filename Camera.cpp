#include"DxLib.h"
#include"Camera.h"
#include"Reference.h"

using namespace Lib;

namespace App
{
	Camera::Camera()
	{
		SetCameraNearFar(cameraNear, cameraFar);
		SetCameraPositionAndTarget_UpVecY(VGet(0.0f, 0.0f, cameraPosZ), VGet(0.0f, 0.0f, cameraGazingPosZ));
	}

	Camera::~Camera() {}
}