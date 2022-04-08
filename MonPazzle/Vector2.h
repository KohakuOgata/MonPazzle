#pragma once
#include "Vector.h"
#include <string>
class Vector2 :
    public Vector<double, 2>
{
public:
    Vector2();
    Vector2(const std::array<double, 2>& c);

    double GetAngle() const;
    void PrintState(const std::string& dispname = "") const;

    static double Dot(const Vector2& l, const Vector2& r);
    static double Cross(const Vector2& l, const Vector2& r);
    static double GetCosine(const Vector2& v1, const Vector2& v2);
    static double GetSine(const Vector2& v1, const Vector2& v2);
};

