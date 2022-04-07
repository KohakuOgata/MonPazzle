#include "Time.h"
#include <DxLib.h>

namespace {
	double lastTime;
	double deltaTime = 0;
	bool initialized = false;
	double nowTime;
}

namespace Time {
	void Update()
	{
		nowTime = static_cast<double>(GetNowCount()) / 1000;
		deltaTime = nowTime - lastTime;
		lastTime = nowTime;
		if (initialized)
			return;
		deltaTime = 0;
		initialized = true;
	}

	double DeltaTime()
	{
		return deltaTime;
	}

	double NowTime()
	{
		return nowTime;
	}
}