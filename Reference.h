#pragma once

namespace Lib
{
	/// <summary>
	/// スクリーン幅
	/// </summary>
	const float screenSizeX = 1920.0f;

	/// <summary>
	/// スクリーン高さ
	/// </summary>
	const float screenSizeY = 1080.0f;

	/// <summary>
	/// カラービット数
	/// </summary>
	const int colorBitDepth = 32;

	/// <summary>
	/// フレームレート
	/// </summary>
	const int fps = 60;

	/// <summary>
	/// 待ち時間
	/// </summary>
	const int deltaTime = 1000 / fps;

	/// <summary>
	/// 手前クリップ距離
	/// </summary>
	const float cameraNear = 1.0f;

	/// <summary>
	/// 奥クリップ距離
	/// </summary>
	const float cameraFar = 2000.0f;

	/// <summary>
	/// カメラのZ座標
	/// </summary>
	const float cameraPosZ = -1000.0f;

	/// <summary>
	/// カメラのZ座標注視点
	/// </summary>
	const float cameraGazingPosZ = 0.0f;
}