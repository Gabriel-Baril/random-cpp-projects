#pragma once
#include "Def.h"
#include <iostream>

template<class T>
class Vec2 final
{
public:
	Vec2() : x(0), y(0) {}
	Vec2(const T& x, const T& y) : x(x), y(y) {}
	Vec2(const Vec2& copy) { this->x = copy.x; this->y = copy.y; }
	~Vec2() {}

	T getX() const { return x; };
	T getY() const { return y;};

	double getMag() const {
		return x * x + y * y;
	}

	void set(T x, T y) {
		this->x = x;
		this->y = y;
	}

	Vec2 normalize() {
		double length = getMag();
		this->x /= length;
		this->y /= length;
	}

	double dist(const vec2& v) const {
		vec2 d(v.x - x, v.y - y);
		return d.length();
	}

	vec2 ortho() const {
		return vec2(y, -x);
	}

	static double dot(const vec2& v1, const vec2& v2) {
		return v1.x * v2.x + v1.y * v2.y;
	}

	static double cross(const vec2& v1, const vec2& v2) {
		return (v1.x * v2.y) - (v1.y * v2.x);
	}

	std::ostream& operator<<(std::ostream& os)
	{
		os << "(" << this->x << "," << this->y << ")" << std::endl;
		return os;
	}

	Vec2 operator+(const Vec2& v1) { return Vec2(this->x + v1.x, this->y + v1.y); }
	Vec2 operator-(const Vec2& v1) { return Vec2(this->x - v1.x, this->y - v1.y); }
	Vec2 operator*(const Vec2& v1) { return Vec2(this->x * v1.x, this->y * v1.y); }
	Vec2 operator/(const Vec2& v1) { return Vec2(this->x / v1.x, this->y / v1.y); }

	Vec2 operator+=(const Vec2& v1) {
		this->x = this->x + v1.x;
		this->y = this->y + v1.y;
		return *this; 
	}

	Vec2 operator-=(const Vec2& v1) {
		this->x = this->x - v1.x;
		this->y = this->y - v1.y;
		return *this;
	}

	Vec2 operator*=(const Vec2& v1) {
		this->x = this->x * v1.x;
		this->y = this->y * v1.y;
		return *this;
	}

	Vec2 operator/=(const Vec2& v1) {
		this->x = this->x / v1.x;
		this->y = this->y / v1.y;
		return *this;
	}
private:
	T x;
	T y;
};
