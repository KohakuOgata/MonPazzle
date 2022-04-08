#pragma once
#include <array>
template<typename T, size_t N>
class Vector
{
public:
	Vector();
	Vector(const std::array<T, N>& c);

	T GetSqLength() const;
	double GetLengthD() const;
	T GetLength() const;
	Vector<T, N> GetNormalized() const;
	Vector<T, N>& Normalize();

	T& operator [](const size_t n);
	const T& operator [](const size_t n) const;

private:
	std::array<T, N> c;
};

template<typename T, size_t N>
const Vector<T, N> operator +(const Vector<T, N>& l, const Vector<T, N>& r)
{
	return { l[0] + r[0], l[1] + r[1] };
}

template<typename T, size_t N>
const Vector<T, N> operator -(const Vector<T, N>& l, const Vector<T, N>& r)
{
	return { l[0] - r[0], l[1] - r[1] };
}

template<typename T, size_t N>
const Vector<T, N> operator *(const Vector<T, N>& l, const Vector<T, N>& r)
{
	return { l[0] * r[0], l[1] * r[1] };
}

template<typename T, size_t N>
const Vector<T, N> operator /(const Vector<T, N>& l, const Vector<T, N>& r)
{
	return { l[0] / r[0], l[1] / r[1] };
}

template<typename T, size_t N>
Vector<T, N>& operator +=(Vector<T, N>& l, const Vector<T, N>& r)
{
	l = l + r;
	return l;
}

template<typename T, size_t N>
Vector<T, N>& operator -=(Vector<T, N>& l, const Vector<T, N>& r)
{
	l = l - r;
	return l;
}

template<typename T, size_t N>
Vector<T, N>& operator *=(Vector<T, N>& l, const Vector<T, N>& r)
{
	l = l * r;
	return l;
}

template<typename T, size_t N>
Vector<T, N>& operator /=(Vector<T, N>& l, const Vector<T, N>& r)
{
	l = l / r;
	return l;
}

template<typename T, size_t N>
const Vector<T, N> operator +(const Vector<T, N>& l, const T& r)
{
	return { l[0] + r, l[1] + r };
}

template<typename T, size_t N>
const Vector<T, N> operator -(const Vector<T, N>& l, const T& r)
{
	return { l[0] - r, l[1] - r };
}

template<typename T, size_t N>
const Vector<T, N> operator *(const Vector<T, N>& l, const T& r)
{
	return { l[0] * r, l[1] * r };
}

template<typename T, size_t N>
const Vector<T, N> operator /(const Vector<T, N>& l, const T& r)
{
	return { l[0] / r, l[1] / r };
}

template<typename T, size_t N>
const Vector<T, N> operator +(const T& l, const Vector<T, N>& r)
{
	return { l + r[0], l + r[1] };
}

template<typename T, size_t N>
const Vector<T, N> operator -(const T& l, const Vector<T, N>& r)
{
	return { l - r[0], l - r[1] };
}

template<typename T, size_t N>
const Vector<T, N> operator *(const T& l, const Vector<T, N>& r)
{
	return { l * r[0], l * r[1] };
}

template<typename T, size_t N>
const Vector<T, N> operator /(const T& l, const Vector<T, N>& r)
{
	return { l / r[0], l / r[1] };
}

template<typename T, size_t N>
Vector<T, N>& operator +=(Vector<T, N>& l, const T& r)
{
	l = l + r;
	return l;
}

template<typename T, size_t N>
Vector<T, N>& operator -=(Vector<T, N>& l, const T& r)
{
	l = l - r;
	return l;
}

template<typename T, size_t N>
Vector<T, N>& operator *=(Vector<T, N>& l, const T& r)
{
	l = l * r;
	return l;
}

template<typename T, size_t N>
Vector<T, N>& operator /=(Vector<T, N>& l, const T& r)
{
	l = l / r;
	return l;
}

template<typename T, size_t N>
inline Vector<T, N>::Vector()
{
}

template<typename T, size_t N>
inline Vector<T, N>::Vector(const std::array<T, N>& c):
	c(c)
{
}

template<typename T, size_t N>
inline T Vector<T, N>::GetSqLength() const
{
	return c[0] * c[0] + c[1] * c[1];
}

template<typename T, size_t N>
inline double Vector<T, N>::GetLengthD() const
{
	return sqrt(GetSqLength());
}

template<typename T, size_t N>
inline T Vector<T, N>::GetLength() const
{
	return static_cast<T>(GetLengthD());
}

template<typename T, size_t N>
inline Vector<T, N> Vector<T, N>::GetNormalized() const
{
	return *this / GetLengthD();
}

template<typename T, size_t N>
inline Vector<T, N>& Vector<T, N>::Normalize()
{
	*this = GetNormalized();
	return *this;
}

template<typename T, size_t N>
inline T& Vector<T, N>::operator[](const size_t n)
{
	return c[n];
}

template<typename T, size_t N>
inline const T& Vector<T, N>::operator[](const size_t n) const
{
	return c[n];
}
