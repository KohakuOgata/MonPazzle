#include "System.h"
#include <DxLib.h>
#include "Time.h"
#include "SceneManager.h"

bool System::Initialize()
{
	//�E�B���h�E���m���A�N�e�B�u���Ɏ��s�𑱂��邩
	SetAlwaysRunFlag(TRUE);
	//�E�B���h�E�T�C�Y�����R�ɕύX�ł��邩
	SetWindowSizeChangeEnableFlag(TRUE);
	//���O�o�͂��邩
	SetOutApplicationLogValidFlag(FALSE);
	//�t���X�N���[�����ɏc������ێ����邩
	SetFullScreenResolutionMode(DX_FSRESOLUTIONMODE_DESKTOP);
	//�E�B���h�E�^�C�g��
	SetWindowText("MonPazzle");
	//�E�B���h�E���[�h���ǂ���
	ChangeWindowMode(TRUE);
	//�E�B���h�E�T�C�Y�̔{��
	SetWindowSizeExtendRate(0.5);
	//�F��bit���B�ʏ�32�ŗǂ����y������Ȃ�16�ɂ���
	const int COLOR_BIT = 32;
	//�Q�[����ʂ̉𑜓x
	SetGraphMode(1920, 1080, COLOR_BIT);
	//�w�i�F
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
