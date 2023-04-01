#include"DxLib.h"
#include"Camera.h"
#include"Reference.h"

using namespace Lib;

namespace App
{
	Camera::Camera()
	{
		SetCameraNearFar(cameraNear, cameraFar);
		SetCameraPositionAndTarget_UpVecY(VGet(cameraPosX, cameraPosY, cameraPosZ), VGet(cameraGazingPosX, cameraGazingPosY, cameraGazingPosZ));
	}

	Camera::~Camera() {}
}