#include "Button.h"
#include <DxLib.h>
#include "Time.h"
#undef max

Button::Button()
{
}

Button::~Button()
{
}

void Button::Update(const bool isPressed)
{
	if (isReleasedNow)
		pressedTime = 0;
	this->isPressed = isPressed;
	if (isPressed) {
		isPressedFromNow = (pressedTime == 0);
		isReleasedNow = false;
		if (std::numeric_limits<double>::max() - pressedTime > Time::DeltaTime())
			pressedTime += Time::DeltaTime();
		else
			pressedTime = std::numeric_limits<double>::max();
		return;
	}
	isReleasedNow = pressedTime;
	isPressedFromNow = false;
}

bool Button::IsPressed() const
{
	return isPressed;
}

bool Button::IsPressedFromNow() const
{
	return isPressedFromNow;
}

bool Button::IsReleasedNow() const
{
	return isReleasedNow;
}

double Button::GetPressedTime() const
{
	return pressedTime;
}

void Button::PrintState(const std::string dispName) const
{
	printfDx("%s(isPressed : %5s, isPressedFromNow : %5s, isReleasedNow : %5s, pressedTime : %.2f)\n", dispName.c_str(), isPressed, isPressedFromNow, isReleasedNow, pressedTime);
}
