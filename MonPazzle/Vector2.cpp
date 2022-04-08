#include "Vector2.h"
#include <DxLib.h>

Vector2::Vector2()
{
}

Vector2::Vector2(const std::array<double, 2>& c):
	Vector<double, 2>(c)
{
}

double Vector2::GetAngle() const
{
	return atan2((*this)[1], (*this)[0]);
}

void Vector2::PrintState(const std::string& dispname) const
{
	printfDx("%s(x : %.2f, y : %.2f)", dispname, (*this)[0], (*this)[1]);
}

double Vector2::Dot(const Vector2& l, const Vector2& r)
{
	return l[0] * r[0] + l[1] * r[1];
}

double Vector2::Cross(const Vector2& l, const Vector2& r)
{
	return l[0] * r[1] - l[1] * r[0];
}

double Vector2::GetCosine(const Vector2& v1, const Vector2& v2)
{
	return Dot(v1, v2) / v1.GetLengthD() / v2.GetLengthD();
}

double Vector2::GetSine(const Vector2& v1, const Vector2& v2)
{
	return Cross(v1, v2) / v1.GetLengthD() / v2.GetLengthD();
}
