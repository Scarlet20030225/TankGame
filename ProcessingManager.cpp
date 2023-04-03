#include"DxLib.h"
#include"ProcessingManager.h"

namespace App
{
	ProcessingManager::ProcessingManager()
	{
		camera		= new App::Camera();
		map			= new App::Map();
		player		= new App::Player();
		for (int i = 0; i < bulletNum; i++)
		{
			playerShot[i] = new App::PlayerShot();
		}
	}

	ProcessingManager::~ProcessingManager()
	{
		delete camera;
		camera = nullptr;

		delete map;
		map = nullptr;

		delete player;
		player = nullptr;

		for (int i = 0; i < bulletNum; i++)
		{
			delete playerShot[i];
			playerShot[i] = nullptr;
		}
	}

	void ProcessingManager::AllUpdate(float deltaTime)
	{
		map->Update();
		player->Update(deltaTime, playerShot);
		for (int i = 0; i < bulletNum; i++)
		{
			playerShot[i]->Update(deltaTime);
		}
	}

	void ProcessingManager::AllDraw()
	{
		map->Draw();
		player->Draw();
		for (int i = 0; i < bulletNum; i++)
		{
			playerShot[i]->Draw();
		}
	}
}