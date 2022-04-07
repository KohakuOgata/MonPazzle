#pragma once

namespace Time {
#ifdef SYSTEM_H
	void Update();
#endif // SYSTEM_H

	double DeltaTime();
	double NowTime();
}