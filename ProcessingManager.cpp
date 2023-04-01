#include"DxLib.h"
#include"ProcessingManager.h"

namespace App
{
	ProcessingManager::ProcessingManager()
	{
		camera = new App::Camera();
		map    = new App::Map();
		player = new App::Player();
	}

	ProcessingManager::~ProcessingManager()
	{
	}

	void ProcessingManager::AllUpdate(float deltaTime)
	{
		map->Update();
		player->Update(deltaTime);
	}

	void ProcessingManager::AllDraw()
	{
		map->Draw();
		player->Draw();
	}
}