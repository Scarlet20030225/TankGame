#pragma once

namespace Lib
{
//-------------------------------------------------------------------------
// ウィンドウ関係
//-------------------------------------------------------------------------
	/// <summary>
	/// スクリーン幅
	/// </summary>
	const int screenSizeX = 1920;

	/// <summary>
	/// スクリーン高さ
	/// </summary>
	const int screenSizeY = 1080;

	/// <summary>
	/// カラービット数
	/// </summary>
	const int colorBitDepth = 32;

//-------------------------------------------------------------------------
// フレーム関係
//-------------------------------------------------------------------------
	/// <summary>
	/// フレームレート
	/// </summary>
	const int fps = 60;

	/// <summary>
	/// 待ち時間
	/// </summary>
	const int deltaTime = 1000 / fps;

//-------------------------------------------------------------------------
// カメラ関係
//-------------------------------------------------------------------------
	/// <summary>
	/// 手前クリップ距離
	/// </summary>
	const float cameraNear = 1.0f;

	/// <summary>
	/// 奥クリップ距離
	/// </summary>
	const float cameraFar = 2000.0f;

	/// <summary>
	/// カメラのX座標
	/// </summary>
	const float cameraPosX = 960.0f;

	/// <summary>
	/// カメラのY座標
	/// </summary>
	const float cameraPosY = 540.0f;

	/// <summary>
	/// カメラのZ座標
	/// </summary>
	const float cameraPosZ = -1000.0f;

	/// <summary>
	/// カメラのX座標注視点
	/// </summary>
	const float cameraGazingPosX = 960.0f;

	/// <summary>
	/// カメラのY座標注視点
	/// </summary>
	const float cameraGazingPosY = 540.0f;

	/// <summary>
	/// カメラのZ座標注視点
	/// </summary>
	const float cameraGazingPosZ = 0.0f;
}