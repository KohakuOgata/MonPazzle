#include <DxLib.h>
#include "System.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	if (System::Initialize())
		System::Loop();
	System::Finalize();
	return 0;
}