#pragma once
#include <string>
class Button
{
public:
	Button();
	virtual ~Button();

	void Update(const bool isPushed);
	bool IsPressed() const;
	bool IsPressedFromNow() const;
	bool IsReleasedNow() const;
	double GetPressedTime() const;
	void PrintState(const std::string dispName) const;

protected:
	bool isPressed;
	bool isPressedFromNow;
	bool isReleasedNow;
	double pressedTime;
};

