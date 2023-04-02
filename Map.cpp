#include"Map.h"
#include"Reference.h"

using namespace Lib;

namespace App
{
	Map::Map()
	{
		mModelHandle = MV1LoadModel("data/Model/MapBlock.mv1");
		MV1SetScale(mModelHandle, VGet(0.5f, 0.5f, 0.5f));
		MV1SetMaterialEmiColor(mModelHandle, 0, GetColorF(0.6f, 1.0f, 0.3f, 0.5f));		// F‚ğÂF‚É
		mPos = VGet(0.0f, 0.0f, 0.0f);

		baseBlockNumX = baseBlockX;
		baseBlockNumY = baseBlockY;
	}

	Map::~Map()
	{
	}

	void Map::Update()
	{
	}

	void Map::Draw()
	{
		for (int i = 0; i < baseBlockNumY; i++)
		{
			for (int j = 0; j < baseBlockNumX; j++)
			{
				mPos.x = 50.0f * j;
				mPos.y = 50.0f * i;
				mPos.z = 0.0f;
				MV1SetPosition(mModelHandle, mPos);
				MV1DrawModel(mModelHandle);	// ƒ‚ƒfƒ‹‚ğ•`‰æ
			}
		}
	}
}