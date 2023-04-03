#include"Map.h"
#include"Reference.h"

using namespace Lib;

namespace App
{
	Map::Map()
	{
		mGraphHandle = LoadGraph("data/Graph/MapBase.png");
		mModelHandle = MV1LoadModel("data/Model/MapBlock.mv1");
		MV1SetScale(mModelHandle, VGet(0.5f, 0.5f, 0.5f));
		MV1SetMaterialEmiColor(mModelHandle, 0, GetColorF(0.6f, 1.0f, 0.3f, 0.5f));		// êFÇê¬êFÇ…
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
		//DrawBillboard3D(VGet(960.0f, 540.0f, 0.0f), 0.5f, 0.5f, 1950.0f, 0.0f, mGraphHandle, TRUE);

		//for (int i = 0; i < baseBlockNumY; i++)
		//{
		//	for (int j = 0; j < baseBlockNumX; j++)
		//	{
		//		mPos.x = 50.0f * j;
		//		mPos.y = 50.0f * i;
		//		mPos.z = 0.0f;
		//		MV1SetPosition(mModelHandle, mPos);
		//		MV1DrawModel(mModelHandle);	// ÉÇÉfÉãÇï`âÊ
		//	}
		//}

		// äiéqê¸ÇÃï`âÊ
		for (float x = 0.0f; x <= 1920.0f; x += 40.0f)
		{
			DrawLine3D(VGet(x, 0.0f, 0.0f), VGet(x, 1000.0f, 0.0f), GetColor(255, 255, 255));
		}

		for (float y = 0.0f; y <= 1000.0f; y += 40.0f)
		{
			DrawLine3D(VGet(0.0f, y, 0.0f), VGet(1920.0f, y, 0.0f), GetColor(255, 255, 255));
		}

		for (float z = 0.0f; z <= 0.0f; z += 40.0f)
		{
			DrawLine3D(VGet(0.0f, 0.0f, z), VGet(1920.0f, 0.0f, z), GetColor(255, 255, 255));
			DrawLine3D(VGet(0.0f, 0.0f, z), VGet(0.0f, 1000.0f, z), GetColor(255, 255, 255));
		}
	}
}