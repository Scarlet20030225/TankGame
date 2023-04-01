#include"DxLib.h"
#include"ProcessingManager.h"

namespace App
{
	ProcessingManager::ProcessingManager()
	{
		camera = new App::Camera();
		map = new App::Map();
	}

	ProcessingManager::~ProcessingManager()
	{
	}

	void ProcessingManager::AllUpdate(float deltaTime)
	{
		map->Update();
	}

	void ProcessingManager::AllDraw()
	{
		map->Draw();
	}
}