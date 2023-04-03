#include"Mouse.h"
#include"Reference.h"

namespace Lib
{
	Mouse::Mouse()
	{
		cursorGraphHandle = LoadGraph("data/Graph/Scope.png");
		SetMousePoint(setMousePointX, setMousePointY);
	}

	Mouse::~Mouse()
	{
	}

	void Mouse::Update()
	{
		GetMousePoint(&getMousePointX, &getMousePointY);
		mMousePoint = ConvScreenPosToWorldPos(VGet((float)getMousePointX, (float)getMousePointY, 0.99949975f));
	}

	void Mouse::Draw()
	{
		DrawGraph3D(mMousePoint.x, mMousePoint.y, 0.0f, cursorGraphHandle, TRUE);
	}
}