#include"Map.h"
#include"Reference.h"

using namespace Lib;

namespace App
{
	Map::Map()
	{
		mGraphHandle = LoadGraph("data/Graph/MapBase.png");
		mModelHandle = MV1LoadModel("data/Model/MapBlock.mv1");
		MV1SetScale(mModelHandle, VGet(0.85f, 0.85f, 0.85f));
		MV1SetMaterialEmiColor(mModelHandle, 0, GetColorF(0.6f, 1.0f, 0.3f, 0.5f));		// �F��F��
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
		// �i�q���̕`��
		for (float x = 0.0f; x <= 1920.0f; x += 40.0f)
		{
			DrawLine3D(VGet(x, 0.0f, 0.0f), VGet(x, 960.0f, 0.0f), GetColor(255, 255, 255));
		}
		for (float y = 0.0f; y <= 960.0f; y += 40.0f)
		{
			DrawLine3D(VGet(0.0f, y, 0.0f), VGet(1920.0f, y, 0.0f), GetColor(255, 255, 255));
		}

		// �u���b�N�̕`��
		for (int i = 0; i < baseBlockNumX; i++)	// X���i�̕�
		{
			mPos.x = -80.0f + 86.8 * i;
			mPos.y = -3.0f;
			mPos.z = 0.0f;

			MV1SetPosition(mModelHandle, mPos);
			MV1DrawModel(mModelHandle);
		}
		for (int j = 0; j < baseBlockNumX; j++)	// X��i�̕�
		{
			mPos.x = -80.0f + 86.8 * j;
			mPos.y = 953.0f;
			mPos.z = 0.0f;

			MV1SetPosition(mModelHandle, mPos);
			MV1DrawModel(mModelHandle);
		}
		for (int k = 0; k < baseBlockNumY; k++)	// Y�����̕�
		{
			mPos.x = -80.0f;
			mPos.y = 85.0f + 86.8 * k;
			mPos.z = 0.0f;

			MV1SetPosition(mModelHandle, mPos);
			MV1DrawModel(mModelHandle);
		}
		for (int l = 0; l < baseBlockNumY; l++)	// Y�E���̕�
		{
			mPos.x = 1916.4f;
			mPos.y = 85.0f + 86.8 * l;
			mPos.z = 0.0f;

			MV1SetPosition(mModelHandle, mPos);
			MV1DrawModel(mModelHandle);
		}
	}
}