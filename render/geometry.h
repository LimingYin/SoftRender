#pragma once

#include <cmath>
#include <iostream>

// From https://github.com/mmp/pbrt-v3/blob/master/src/core/geometry.h

// Vector Declarations
template <typename T>
class Vector2
{
public:
	// Vector2 Public Methods
	Vector2() { x = y = 0; }
	Vector2(T xx, T yy) : x(xx), y(yy) {}
	~Vector2() {}
	Vector2(const Vector2<T> &v)
	{
		x = v.x;
		y = v.y;
	}

	Vector2<T> &operator=(const Vector2<T> &v)
	{
		x = v.x;
		y = v.y;
		return *this;
	}

	Vector2<T> &operator+(const Vector2<T> &v) const
	{
		return Vector2(x + v.x, y + v.y);
	}

	Vector2<T> &operator+=(const Vector2<T> &v)
	{
		x += v.x;
		y += v.y;
		return *this;
	}

	Vector2<T> &operator-(const Vector2<T> &v) const
	{
		return Vector2(x - v.x, y - v.y);
	}

	Vector2<T> &operator-=(const Vector2<T> &v)
	{
		x -= v.x;
		y -= v.y;
		return *this;
	}

	Vector2<T> operator-() const
	{
		return Vector2<T>(-x, -y);
	}

	bool operator==(const Vector2<T> &v) const
	{
		return x == v.x && y == v.y;
	}

	bool operator!=(const Vector2<T> &v) const
	{
		return x != v.x || y != v.y;
	}

	template <typename U>
	Vector2<T> operator*(U f) const
	{
		return Vector2<T>(f*x, f*y);
	}

	template <typename U>
	Vector2<T> operator*=(U f)
	{
		x *= f;
		y *= f;
		return *this;
	}

	template <typename U>
	Vector2<T> operator/(U f) const
	{
		float inv = (float)1 / f;
		return Vector2<T>(x * inv, y * inv);
	}

	template <typename U>
	Vector2<T> operator/=(U f)
	{
		float inv = (float)1 / f;
		x *= inv;
		y *= inv;
		return *this;
	}

	float lengthSquared() const
	{
		return x * x + y * y;
	}

	float length() const
	{
		return std::sqrt(lengthSquared());
	}

	// Vector2 Public Data
	T x, y;
};

template <typename T>
inline std::ostream &operator<<(std::ostream &os, const Vector2<T> &v)
{
	os << "[ " << v.x << ", " << v.y << " ]";
	return os;
}


// Vector Declarations
template <typename T>
class Vector3
{
public:
	// Vector3 Public Methods
	Vector3() { x = y = z = 0; }
	Vector3(T xx, T yy, T zz) : x(xx), y(yy), z(zz) {}
	~Vector3() {}

	Vector3(const Vector3<T> &v)
	{
		x = v.x;
		y = v.y;
		z = v.z;
	}

	Vector3<T> &operator=(const Vector3<T> &v)
	{
		x = v.x;
		y = v.y;
		z = v.z;
		return *this;
	}

	Vector3<T> &operator+(const Vector3<T> &v) const
	{
		return Vector3(x + v.x, y + v.y + v.z);
	}

	Vector3<T> &operator+=(const Vector3<T> &v)
	{
		x += v.x;
		y += v.y;
		z += v.z;
		return *this;
	}

	Vector3<T> &operator-(const Vector3<T> &v) const
	{
		return Vector3(x - v.x, y - v.y, z - v.z);
	}

	Vector3<T> &operator-=(const Vector3<T> &v)
	{
		x -= v.x;
		y -= v.y;
		z -= v.z;
		return *this;
	}

	Vector3<T> operator-() const
	{
		return Vector3<T>(-x, -y, -z);
	}

	bool operator==(const Vector3<T> &v) const
	{
		return x == v.x && y == v.y && z == v.z;
	}

	bool operator!=(const Vector3<T> &v) const
	{
		return x != v.x || y != v.y || z != v.z;
	}

	template <typename U>
	Vector3<T> operator*(U f) const
	{
		return Vector3<T>(f*x, f*y, f*z);
	}

	template <typename U>
	Vector3<T> operator*=(U f)
	{
		x *= f;
		y *= f;
		z *= f;
		return *this;
	}

	template <typename U>
	Vector3<T> operator/(U f) const
	{
		float inv = (float)1 / f;
		return Vector3<T>(x * inv, y * inv, z * inv);
	}

	template <typename U>
	Vector3<T> operator/=(U f)
	{
		float inv = (float)1 / f;
		x *= inv;
		y *= inv;
		z *= inv;
		return *this;
	}

	float lengthSquared() const
	{
		return x * x + y * y + z * z;
	}

	float length() const
	{
		return std::sqrt(lengthSquared());
	}

	// Vector3 Public Data
	T x, y, z;
};

template <typename T>
inline std::ostream &operator<<(std::ostream &os, const Vector3<T> &v)
{
	os << "[ " << v.x << ", " << v.y << ", " << v.z << " ]";
	return os;
}

typedef Vector2<float> Vector2f;
typedef Vector2<int> Vector2i;
typedef Vector2<float> Vector2f;
typedef Vector2<int> Vector2i;

// Point Declarations
template <typename T>
class Point2
{
public:
	// Point2 Public Methods
	Point2() { x = y = 0; }
	Point2(T xx, T yy) : x(xx), y(yy) {}

	Point2(const Point2<T> &p)
	{
		x = p.x;
		y = p.y;
	}

	Point2<T> &operator=(const Point2<T> &p)
	{
		x = p.x;
		y = p.y;
		return *this;
	}

	Point2<T> operator+(const Vector2<T> &v) const
	{
		return Point2<T>(x + v.x, y + v.y);
	}

	Point2<T> operator+=(const Vector2<T> &v)
	{
		x += v.x;
		y += v.y;
	}

	Vector2<T> operator-(const Point2<T> &p) const
	{
		return Vector2<T>(x - p.x, y - p.y);
	}

	Point2<T> operator-(const Vector2<T> &p) const
	{
		return Point2<T>(x - p.x, y - p.y);
	}

	Point2<T> operator-() const
	{
		return Point2<T>(-x, -y);
	}

	Point2<T> &operator-=(const Vector2<T> &v)
	{
		x -= v.x;
		y -= v.y;
		return *this;
	}

	Point2<T> &operator+=(const Point2<T> &v)
	{
		x += v.x;
		y += v.y;
		return *this;
	}

	Point2<T> operator+(const Point2<T> &p) const
	{
		return Point2<T>(x + p.x, y + p.y);
	}

	template <typename U>
	Point2<T> operator*(U f) const
	{
		return Point2<T>(f*x, f*y);
	}

	template <typename U>
	Point2<T> &operator*=(U f)
	{
		x *= f;
		y *= f;
		return *this;
	}

	template <typename U>
	Point2<T> operator/(U f) const
	{
		float inv = (float)1 / f;
		return Point2<T>(inv *x, inv*y);
	}

	template <typename U>
	Point2<T> &operator/=(U f)
	{
		float inv = (float)1 / f;
		x *= inv;
		y *= inv;
		return *this;
	}

	bool operator==(const Point2<T> &p)const
	{
		return x == p.x && y == p.y;
	}

	bool operator!=(const Point2<T> &p) const
	{
		return x != p.x || y != p.y;
	}

	template <typename U>
	explicit Point2(const Point2<U> &p)
	{
		x = (T)p.x;
		y = (T)p.y;
	}

	template <typename U>
	explicit Point2(const Vector2<U> &p)
	{
		x = (T)p.x;
		y = (T)p.y;
	}

	template <typename U>
	explicit operator Vector2<U>() const
	{
		return Vector2<U>(x, y);
	}

	T x, y;
};

template <typename T>
inline std::ostream &operator<<(std::ostream &os, const Point2<T> &v)
{
	os << "[ " << v.x << ", " << v.y << " ]";
	return os;
}

// Point Declarations
template <typename T>
class Point3
{
public:
	// Point3 Public Methods
	Point3() { x = y = z = 0; }
	Point3(T xx, T yy, T zz) : x(xx), y(yy), z(zz) {}

	Point3(const Point3<T> &p)
	{
		x = p.x;
		y = p.y;
		z = p.z;
	}

	Point3<T> &operator=(const Point3<T> &p)
	{
		x = p.x;
		y = p.y;
		z = p.z;
	}

	Point3<T> operator+(const Vector3<T> &v) const
	{
		return Point2<T>(x + v.x, y + v.y, z + v.z);
	}

	Point3<T> operator+=(const Vector3<T> &v)
	{
		x += v.x;
		y += v.y;
		z += v.z;
	}

	Vector3<T> operator-(const Point3<T> &p) const
	{
		return Vector3<T>(x - p.x, y - p.y, z - p.z);
	}

	Point3<T> operator-(const Vector3<T> &p) const
	{
		return Point3<T>(x - p.x, y - p.y, z - p.z);
	}

	Point3<T> operator-() const
	{
		return Point3<T>(-x, -y, -z);
	}

	Point3<T> &operator-=(const Vector3<T> &v)
	{
		x -= v.x;
		y -= v.y;
		z -= v.z;
		return *this;
	}

	Point3<T> &operator+=(const Point3<T> &v)
	{
		x += v.x;
		y += v.y;
		z += v.z;
		return *this;
	}

	Point3<T> operator+(const Point3<T> &p) const
	{
		return Point3<T>(x + p.x, y + p.y, z + p.z);
	}

	template <typename U>
	Point3<T> operator*(U f) const
	{
		return Point3<T>(f*x, f*y, f*z);
	}

	template <typename U>
	Point3<T> &operator*=(U f)
	{
		x *= f;
		y *= f;
		z *= f;
		return *this;
	}

	template <typename U>
	Point3<T> operator/(U f) const
	{
		float inv = (float)1 / f;
		return Point3<T>(inv *x, inv*y, inv*z);
	}

	template <typename U>
	Point3<T> &operator/=(U f)
	{
		float inv = (float)1 / f;
		x *= inv;
		y *= inv;
		return *this;
	}

	bool operator==(const Point3<T> &p)const
	{
		return x == p.x && y == p.y && z == p.z;
	}

	bool operator!=(const Point3<T> &p) const
	{
		return x != p.x || y != p.y || z != p.z;
	}

	template <typename U>
	explicit Point3(const Point3<U> &p)
	{
		x = (T)p.x;
		y = (T)p.y;
		z = (T)p.z;
	}

	template <typename U>
	explicit Point3(const Vector3<U> &p)
	{
		x = (T)p.x;
		y = (T)p.y;
		z = (T)p.z;
	}

	template <typename U>
	explicit operator Vector3<U>() const
	{
		return Vector3<U>(x, y);
	}

	T x, y, z;
};

template <typename T>
inline std::ostream &operator<<(std::ostream &os, const Point3<T> &v)
{
	os << "[ " << v.x << ", " << v.y << ", " << v.z << " ]";
	return os;
}

typedef Point2<float> Point2f;
typedef Point2<int> Point2i;
typedef Point3<float> Point3f;
typedef Point3<int> Point3i;