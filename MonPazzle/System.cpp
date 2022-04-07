#include "System.h"
#include <DxLib.h>
#include "Time.h"
#include "SceneManager.h"

bool System::Initialize()
{
	//ウィンドウがノンアクティブ時に実行を続けるか
	SetAlwaysRunFlag(TRUE);
	//ウィンドウサイズを自由に変更できるか
	SetWindowSizeChangeEnableFlag(TRUE);
	//ログ出力するか
	SetOutApplicationLogValidFlag(FALSE);
	//フルスクリーン時に縦横比を維持するか
	SetFullScreenResolutionMode(DX_FSRESOLUTIONMODE_DESKTOP);
	//ウィンドウタイトル
	SetWindowText("MonPazzle");
	//ウィンドウモードかどうか
	ChangeWindowMode(TRUE);
	//ウィンドウサイズの倍率
	SetWindowSizeExtendRate(0.5);
	//色のbit数。通常32で良いが軽くするなら16にする
	const int COLOR_BIT = 32;
	//ゲーム画面の解像度
	SetGraphMode(1920, 1080, COLOR_BIT);
	//背景色
	SetBackgroundColor(0, 0, 0);
	if (DxLib_Init()) {
		return false;
	}
	SetDrawScreen(DX_SCREEN_BACK);
	SceneManager::Init();
	return true;
}

void System::Loop()
{
	while (1) {
		bool terminate = false;
		terminate |= static_cast<bool>(ClearDrawScreen());
		terminate |= static_cast<bool>(clsDx());
		Time::Update();
		terminate |= SceneManager::Update();
		SceneManager::Draw();
		terminate |= static_cast<bool>(ScreenFlip());
		terminate |= static_cast<bool>(ProcessMessage());
		if (terminate)
			return;
	}
}

void System::Finalize()
{
	DxLib_End();
}
