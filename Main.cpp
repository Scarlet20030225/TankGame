#include"DxLib.h"

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
    // DxLib������
    ChangeWindowMode(TRUE);
    SetGraphMode(1440, 900, 16);
    DxLib_Init();


    // �Q�[�����[�v
    while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
    {
        //��ʍX�V����
        ClearDrawScreen();

        ScreenFlip();
    }

    DxLib_End();
    return 0;
}