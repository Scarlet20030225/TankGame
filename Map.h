#pragma once
#include"DxLib.h"

namespace App
{
	/// <summary>
	/// ƒ}ƒbƒv
	/// </summary>
	class Map
	{
	public:
		Map();
		~Map();

		void Update();
		void Draw();

	private:
		int mModelHandle;
		VECTOR mPos;
		int blockNumX;
		int blockNumY;
	};
}