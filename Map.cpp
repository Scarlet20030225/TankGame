#include"Map.h"

namespace App
{
	Map::Map()
	{
		mModelHandle = MV1LoadModel("data/Model/MapBlock.mv1");
		MV1SetScale(mModelHandle, VGet(0.3f, 0.3f, 0.3f));
		mPos = VGet(0.0f, 0.0f, 0.0f);

		blockNumX = 10;
		blockNumY = 10;
	}

	Map::~Map()
	{
	}

	void Map::Update()
	{
	}

	void Map::Draw()
	{
		for (int i = 0; i < blockNumY; i++)
		{
			for (int j = 0; j < blockNumX; j++)
			{
				mPos.x = 55.0f * j;
				mPos.y = 55.0f * i;
				mPos.z = 0.0f;
				MV1SetPosition(mModelHandle, mPos);
				MV1DrawModel(mModelHandle);	// ƒ‚ƒfƒ‹‚ð•`‰æ
			}
		}
	}
}