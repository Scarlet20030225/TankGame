#pragma once
#include"DxLib.h"

namespace App
{
	/// <summary>
	/// �}�b�v
	/// </summary>
	class Map
	{
	public:
		Map();
		~Map();

		void Update();
		void Draw();

	private:
		int mGraphHandle;

		int mModelHandle;
		VECTOR mPos;
		int baseBlockNumX;
		int baseBlockNumY;
	};
}