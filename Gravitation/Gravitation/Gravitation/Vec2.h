#pragma once
#include <cmath>
#include <string>
#include <iostream>
#include <random>
#include <SFML/Graphics.hpp>

template<class T>
class Vec2
{
public:
	Vec2(); // Basic constructor : set to Vec2(0,0)
	Vec2(const T[]); // Set a Vec2 with an array
	explicit Vec2(const T&); // Set a Vec2 with a single value : set to Vec2(val,val)
	Vec2(const T&, const T&); // Set a Vec2 with 2 value : set to Vec2(x,y)
	Vec2(const Vec2&); // copy constructor
	Vec2(const Vec2&, const Vec2&); // Set a Vec2 with 2 point
	~Vec2(); // Destructor

	Vec2 add(const Vec2&); // Add a Vec2 to the current Vec2
	Vec2 add(const T&, const T&); // Add 2 value to the current Vec2 
	Vec2 add(const T&); // Add a single value to the current Vec2
	static Vec2 add(const Vec2&, const Vec2&); // Add a Vec2 to a other
	static Vec2 add(const Vec2&, const T&, const T&);
	static Vec2 add(const T&, const T&, const Vec2&);
	static Vec2 add(const T& x1, const T& y1, const T& x2, const T& y2); // Add 2 value to 2 value

	Vec2 sub(const Vec2&); // Substract a Vec2 to the current Vec2
	Vec2 sub(const T&, const T&); // Substract 2 value to the current Vec2 
	Vec2 sub(const T&); // Substract a single value to the current Vec2
	static Vec2 sub(const Vec2&, const Vec2&); // Sub a Vec2 to a other
	static Vec2 sub(const Vec2&, const T&, const T&);
	static Vec2 sub(const T&, const T&, const Vec2&);
	static Vec2 sub(const T& x1, const T& y1, const T& x2, const T& y2); // Add 2 value to 2 value

	Vec2 mult(const Vec2&); // Multiplie a Vec2 to the current Vec2
	Vec2 mult(const T&, const T&); // Multiplie 2 value to the current Vec2 
	Vec2 mult(const T&); // Multiplie a single value to the current Vec2
	static Vec2 mult(const Vec2&, const Vec2&);
	static Vec2 mult(const Vec2&, const T&, const T&);
	static Vec2 mult(const T&, const T&, const Vec2&);
	static Vec2 mult(const T& x1, const T& y1, const T& x2, const T& y2);

	Vec2 div(const Vec2&); // Divide a Vec2 to the current Vec2
	Vec2 div(const T&, const T&); // Divide 2 value to the current Vec2 
	Vec2 div(const T&); // Divide a single value to the current Vec2
	static Vec2 div(const Vec2&, const Vec2&);
	static Vec2 div(const Vec2&, const T&, const T&);
	static Vec2 div(const T&, const T&, const Vec2&);
	static Vec2 div(const T& x1, const T& y1, const T& x2, const T& y2);

	double cross(const Vec2&) const;
	double cross(const T&, const T&) const;
	double cross(const T&) const;
	static double cross(const Vec2&, const Vec2&);
	static double cross(const Vec2&, const T&, const T&);
	static double cross(const T&, const T&, const Vec2&);
	static double cross(const T&, const T&, const T&, const T&);

	double dot(const Vec2&) const;
	double dot(const T&, const T&) const;
	double dot(const T&) const;
	static double dot(const Vec2&, const Vec2&);
	static double dot(const Vec2&, const T&, const T&);
	static double dot(const T&, const T&, const Vec2&);
	static double dot(const T&, const T&, const T&, const T&);

	double angleBetween(const Vec2&) const;
	double angleBetween(const T&, const T&) const;
	double angleBetween(const T&) const;
	static double angleBetween(const Vec2&, const Vec2&);
	static double angleBetween(const Vec2&, const T&, const T&);
	static double angleBetween(const T&, const T&, const Vec2&);
	static double angleBetween(const T&, const T&, const T&, const T&);

	double distanceBetween(const Vec2&) const;
	double distanceBetween(const T&, const T&) const;
	double distanceBetween(const T&) const;
	static double distanceBetween(const Vec2&, const Vec2&);
	static double distanceBetween(const Vec2&, const T&, const T&);
	static double distanceBetween(const T&, const T&, const Vec2&);
	static double distanceBetween(const T&, const T&, const T&, const T&);

	Vec2 expand(const double&);
	Vec2 setMag(const double&);
	Vec2 limit(const double&);
	double getMag() const;
	double getMagSq() const;

	Vec2 rotate(const double&);
	Vec2 setAngle(const double&);
	double getAngle() const;

	Vec2 normalize();
	Vec2 negate();
	Vec2 reset();
	Vec2 revert();
	static Vec2 lerp(const Vec2&, const Vec2&, double);

	Vec2 getOrtho() const;
	Vec2 getOrthoCounter() const;

	static Vec2 getMaxOf(const Vec2&, const Vec2&);
	static Vec2 getMinOf(const Vec2&, const Vec2&);

	static Vec2 randomize(const T&);
	static Vec2 randomize(const T&, const T&);
	static Vec2 randomize(const T&, const T&, const T&, const T&);
	Vec2 mutate(const T&);
	Vec2 mutate(const T&, const T&);

	std::string toString() const;
	bool equals(const Vec2&) const;
	bool fuzzyEquals(const Vec2&, const T&) const;
	bool fuzzyEquals(const Vec2&, const T&, const T&) const;
	bool isZero() const;
	bool isOne() const;
	Vec2 copy() const;

	static sf::Vector2<T> toSfVec2(const Vec2&);

	T getX() const;
	T getY() const;

	void setX(const T&);
	void setY(const T&);
	void set(const T&, const T&);
	void set(const T&);
	void set(const Vec2&);

	template<class T> friend std::ostream& operator<<(std::ostream& os, const Vec2&);

	template<class T> friend bool operator==(const Vec2&, const Vec2&);
	template<class T> friend bool operator!=(const Vec2&, const Vec2&);
	template<class T> friend bool operator>(const Vec2&, const Vec2&);
	template<class T> friend bool operator<(const Vec2&, const Vec2&);
	template<class T> friend bool operator>=(const Vec2&, const Vec2&);
	template<class T> friend bool operator<=(const Vec2&, const Vec2&);

	template<class T> friend Vec2& operator+(const Vec2&, const Vec2&);
	template<class T> friend Vec2& operator-(const Vec2&, const Vec2&);
	template<class T> friend Vec2& operator*(const Vec2&, const Vec2&);
	template<class T> friend Vec2& operator/(const Vec2&, const Vec2&);

	template<class T> friend Vec2 operator+=(Vec2&, const Vec2&);
	template<class T> friend Vec2 operator-=(Vec2&, const Vec2&);
	template<class T> friend Vec2 operator*=(Vec2&, const Vec2&);
	template<class T> friend Vec2 operator/=(Vec2&, const Vec2&);
private:
	T x;
	T y;
};

typedef Vec2<float>  Vec2f;
typedef Vec2<int>	 Vec2i;
typedef Vec2<double> Vec2d;
typedef Vec2<short>  Vec2s;
typedef Vec2<long>   Vec2l;

template<typename T>
T RandNum(const T& min, const T& max)
{
	std::random_device rseed;
	std::mt19937 rng(rseed());
	std::uniform_real_distribution<T> dist(min, max);
	return dist(rng); 
}

template<>
long long RandNum<long long>(const long long& min, const long long& max)
{
	std::random_device rseed;
	std::mt19937 rng(rseed());
	std::uniform_int_distribution<long long> dist(min, max);
	return dist(rng);
}

template<>
long RandNum<long>(const long& min, const long& max)
{
	std::random_device rseed;
	std::mt19937 rng(rseed());
	std::uniform_int_distribution<long> dist(min, max);
	return dist(rng);
}


template<>
int RandNum<int>(const int& min, const int& max)
{
	std::random_device rseed;
	std::mt19937 rng(rseed());
	std::uniform_int_distribution<int> dist(min, max);
	return dist(rng);
}

template<>
short RandNum<short>(const short& min, const short& max)
{
	std::random_device rseed;
	std::mt19937 rng(rseed());
	std::uniform_int_distribution<short> dist(min, max);
	return dist(rng);
}


double to_rad(double deg) {
	return deg * 3.141592653589793238463 / 180;
}

double to_deg(double rad) {
	return rad * 180 / 3.141592653589793238463;
}


template<class T>
inline Vec2<T>::Vec2() : x(0), y(0) {}

template<class T>
inline Vec2<T>::Vec2(const T arr[])
{
	this->x = arr[0];
	this->y = arr[1];
}

template<class T>
inline Vec2<T>::Vec2(const T& val)
{
	this->x = val;
	this->y = val;
}

template<class T>
inline Vec2<T>::Vec2(const T& x, const T& y) : x(x), y(y) {}

template<class T>
inline Vec2<T>::Vec2(const Vec2<T>& copy)
{
	this->x = copy.getX();
	this->y = copy.getY();
}

template<class T>
inline Vec2<T>::Vec2(const Vec2& v1, const Vec2& v2)
{
	this->x = v1.x - v2.x;
	this->y = v1.y - v2.y;
}

template<class T>
inline Vec2<T> Vec2<T>::add(const Vec2& v)
{
	this->x += v.x;
	this->y += v.y;

	return *this;
}

template<class T>
inline Vec2<T> Vec2<T>::add(const T& x, const T& y)
{
	this->x += x;
	this->y += y;

	return *this;
}

template<class T>
inline Vec2<T> Vec2<T>::add(const T& nb)
{
	this->x += nb;
	this->y += nb;

	return *this;
}

template<class T>
inline Vec2<T> Vec2<T>::sub(const Vec2& v)
{
	this->x -= v.x;
	this->y -= v.y;

	return *this;
}

template<class T>
inline Vec2<T> Vec2<T>::sub(const T& x, const T& y)
{
	this->x -= x;
	this->y -= y;

	return *this;
}

template<class T>
inline Vec2<T> Vec2<T>::sub(const T& nb)
{
	this->x -= nb;
	this->y -= nb;

	return *this;
}

template<class T>
inline Vec2<T> Vec2<T>::mult(const Vec2& v)
{
	this->x *= v.x;
	this->y *= v.y;

	return *this;
}

template<class T>
inline Vec2<T> Vec2<T>::mult(const T& x, const T& y)
{
	this->x *= x;
	this->y *= y;

	return *this;
}

template<class T>
inline Vec2<T> Vec2<T>::mult(const T& nb)
{
	this->x *= nb;
	this->y *= nb;

	return *this;
}

template<class T>
inline Vec2<T> Vec2<T>::div(const Vec2& v)
{
	this->x /= v.x;
	this->y /= v.y;

	return *this;
}

template<class T>
inline Vec2<T> Vec2<T>::div(const T& x, const T& y)
{
	this->x /= x;
	this->y /= y;

	return *this;
}

template<class T>
inline Vec2<T> Vec2<T>::div(const T& nb)
{
	this->x /= nb;
	this->y /= nb;

	return *this;
}

template<class T>
inline Vec2<T> Vec2<T>::normalize()
{
	double length = getMag();
	this->x /= length;
	this->y /= length;

	return *this;
}

template<class T>
inline Vec2<T> Vec2<T>::copy() const
{
	return Vec2<T>(this->x, this->y);
}

template<class T>
inline sf::Vector2<T> Vec2<T>::toSfVec2(const Vec2& v)
{
	return sf::Vector2<T>(v.getX(),v.getY());
}

template<class T>
inline double Vec2<T>::getMag() const
{
	return sqrt(x * x + y * y);
}

template<class T>
inline double Vec2<T>::getMagSq() const
{
	return getMag()*getMag();
}

template<class T>
inline double Vec2<T>::getAngle() const
{
	return atan2(this->y, this->x);
}

template<class T>
inline Vec2<T> Vec2<T>::getOrtho() const
{
	return Vec2<T>(this->y, -this->x);
}

template<class T>
inline Vec2<T> Vec2<T>::getOrthoCounter() const
{
	return Vec2<T>(-this->y, this->x);
}

template<class T>
inline Vec2<T> Vec2<T>::add(const Vec2& v1, const Vec2& v2)
{
	return Vec2<T>(v1.x + v2.x, v1.y + v2.y);
}

template<class T>
inline Vec2<T> Vec2<T>::add(const Vec2& v, const T& x, const T& y)
{
	return Vec2<T>(v.x + x, v.y + y);
}

template<class T>
inline Vec2<T> Vec2<T>::add(const T& x, const T& y, const Vec2& v)
{
	return Vec2<T>(x + v.x, y + v.y);
}

template<class T>
inline Vec2<T> Vec2<T>::add(const T& x1, const T& y1, const T& x2, const T& y2)
{
	return Vec2<T>(x1 + x2, y1 + y2);
}


template<class T>
inline Vec2<T> Vec2<T>::sub(const Vec2& v1, const Vec2& v2)
{
	return Vec2<T>(v1.x - v2.x, v1.y - v2.y);
}

template<class T>
inline Vec2<T> Vec2<T>::sub(const Vec2& v, const T& x, const T& y)
{
	return Vec2<T>(v.x - x, v.y - y);
}

template<class T>
inline Vec2<T> Vec2<T>::sub(const T& x, const T& y, const Vec2& v)
{
	return Vec2<T>(x - v.x, y - v.y);
}

template<class T>
inline Vec2<T> Vec2<T>::sub(const T& x1, const T& y1, const T& x2, const T& y2)
{
	return Vec2<T>(x1 - x2, y1 - y2);
}


template<class T>
inline Vec2<T> Vec2<T>::mult(const Vec2& v1, const Vec2& v2)
{
	return Vec2<T>(v1.x * v2.x, v1.y * v2.y);
}

template<class T>
inline Vec2<T> Vec2<T>::mult(const Vec2& v, const T& x, const T& y)
{
	return Vec2<T>(v.x * x, v.y * y);
}

template<class T>
inline Vec2<T> Vec2<T>::mult(const T& x, const T& y, const Vec2& v)
{
	return Vec2<T>(x * v.x, y * v.y);
}

template<class T>
inline Vec2<T> Vec2<T>::mult(const T& x1, const T& y1, const T& x2, const T& y2)
{
	return Vec2<T>(x1 * x2, y1 * y2);
}

template<class T>
inline Vec2<T> Vec2<T>::div(const Vec2& v1, const Vec2& v2)
{
	return Vec2<T>(v1.x / v2.x, v1.y / v2.y);
}

template<class T>
inline Vec2<T> Vec2<T>::div(const Vec2& v, const T& x, const T& y)
{
	return Vec2<T>(v.x / x, v.y / y);
}

template<class T>
inline Vec2<T> Vec2<T>::div(const T& x, const T& y, const Vec2& v)
{
	return Vec2<T>(x / v.x, y / v.y);
}

template<class T>
inline Vec2<T> Vec2<T>::div(const T& x1, const T& y1, const T& x2, const T& y2)
{
	return Vec2(x1 / x2, y1 / y2);
}

template<class T>
inline Vec2<T> Vec2<T>::lerp(const Vec2& v1, const Vec2& v2, double prc)
{
	if (prc > 1)
		prc = 1;
	else if (prc < 0)
		prc = 0;
	return Vec2<T>::sub(v2, v1).mult(prc);
}


template<class T>
inline double Vec2<T>::cross(const Vec2& v1, const Vec2& v2)
{
	return v1.x*v2.y - v1.y*v2.x;
}

template<class T>
inline double Vec2<T>::cross(const Vec2& v, const T& x, const T& y)
{
	return v.x*y - v.y*x;
}

template<class T>
inline double Vec2<T>::cross(const T& x, const T& y, const Vec2& v)
{
	return x * v.y - y * v.x;
}

template<class T>
inline double Vec2<T>::cross(const T& x1, const T& y1, const T& x2, const T& y2)
{
	return x1 * y2 - y1 * x2;
}

template<class T>
inline double Vec2<T>::dot(const Vec2& v1, const Vec2& v2)
{
	return v1.x*v2.x + v1.y*v2.y;
}

template<class T>
inline double Vec2<T>::dot(const Vec2& v, const T& x, const T& y)
{
	return v.x*x + v.y*y;
}

template<class T>
inline double Vec2<T>::dot(const T& x, const T& y, const Vec2& v)
{
	return x * v.x + y * v.y;
}

template<class T>
inline double Vec2<T>::dot(const T& x1, const T& y1, const T& x2, const T& y2)
{
	return x1 * x2 + y1 * y2;
}

template<class T>
inline double Vec2<T>::angleBetween(const Vec2& v1, const Vec2& v2)
{
	double v1_angle = v1.getAngle();
	double v2_angle = v2.getAngle();

	return (v1_angle > v2_angle) ? v1_angle - v2_angle : v2_angle - v1_angle;
}

template<class T>
inline double Vec2<T>::angleBetween(const Vec2& v, const T& x, const T& y)
{
	double v1_angle = v.getAngle();
	double v2_angle = Vec2(x, y).getAngle();

	return (v1_angle > v2_angle) ? v1_angle - v2_angle : v2_angle - v1_angle;
}

template<class T>
inline double Vec2<T>::angleBetween(const T& x, const T& y, const Vec2& v)
{
	double v1_angle = Vec2(x, y).getAngle();
	double v2_angle = v.getAngle();

	return (v1_angle > v2_angle) ? v1_angle - v2_angle : v2_angle - v1_angle;
}

template<class T>
inline double Vec2<T>::angleBetween(const T& x1, const T& y1, const T& x2, const T& y2)
{
	double v1_angle = Vec2(x1, y1).getAngle();
	double v2_angle = Vec2(x2, y2).getAngle();

	return (v1_angle > v2_angle) ? v1_angle - v2_angle : v2_angle - v1_angle;
}

template<class T>
inline double Vec2<T>::distanceBetween(const Vec2& v1, const Vec2& v2)
{
	return sqrt((v2.x - v1.x)*(v2.x - v1.x) + (v2.y - v1.y)*(v2.y - v1.y));
}

template<class T>
inline double Vec2<T>::distanceBetween(const Vec2& v, const T& x, const T& y)
{
	return sqrt((x - v.x)*(x - v.x) + (y - v.y)*(y - v.y));
}

template<class T>
inline double Vec2<T>::distanceBetween(const T& x, const T& y, const Vec2& v)
{
	return sqrt((v.x - x)*(v.x - x) + (v.y - y)*(v.y - y));
}

template<class T>
inline double Vec2<T>::distanceBetween(const T& x1, const T& y1, const T& x2, const T& y2)
{
	return sqrt((x2 - x1)*(x2 - x1) + (y2 - y1)*(y2 - y1));
}

template<class T>
inline double Vec2<T>::cross(const Vec2& v) const
{
	return Vec2<T>::cross(*this, v);
}

template<class T>
inline double Vec2<T>::cross(const T& x, const T& y) const
{
	return Vec2<T>::cross(*this, x, y);
}

template<class T>
inline double Vec2<T>::cross(const T& val) const
{
	return Vec2<T>::cross(*this, val, val);
}

template<class T>
inline double Vec2<T>::dot(const Vec2& v) const
{
	return Vec2<T>::dot(*this, v);
}

template<class T>
inline double Vec2<T>::dot(const T& x, const T& y) const
{
	return Vec2<T>::dot(*this, x, y);
}

template<class T>
inline double Vec2<T>::dot(const T& val) const
{
	return Vec2<T>::dot(*this, val, val);
}

template<class T>
inline double Vec2<T>::angleBetween(const Vec2& v) const
{
	return Vec2<T>::angleBetween(*this, v);
}

template<class T>
inline double Vec2<T>::angleBetween(const T& x, const T& y) const
{
	return Vec2<T>::angleBetween(*this, x, y);
}

template<class T>
inline double Vec2<T>::angleBetween(const T& val) const
{
	return Vec2<T>::angleBetween(*this, val, val);
}

template<class T>
inline double Vec2<T>::distanceBetween(const Vec2& v) const
{
	return Vec2<T>::distanceBetween(*this, v);
}

template<class T>
inline double Vec2<T>::distanceBetween(const T& x, const T& y) const
{
	return Vec2<T>::distanceBetween(*this, x, y);
}

template<class T>
inline double Vec2<T>::distanceBetween(const T& val) const
{
	return Vec2<T>::distanceBetween(*this, val, val);
}

template<class T>
inline Vec2<T> Vec2<T>::rotate(const double& angle_deg)
{
	double rad = angle_deg * 3.141592653589793238463 / 180;
	set(this->x*cos(rad) - this->y*sin(rad), this->x*sin(rad) + this->y*cos(rad));
	return *this;
}

template<class T>
inline Vec2<T> Vec2<T>::setMag(const double& ref)
{
	return this->mult(ref / getMag());
}

template<class T>
inline Vec2<T> Vec2<T>::limit(const double& limit)
{
	if (getMag() > limit) {
		setMag(limit);
	}

	return *this;
}

template<class T>
inline Vec2<T> Vec2<T>::negate()
{
	mult(-1);
	return *this;
}

template<class T>
inline Vec2<T> Vec2<T>::reset()
{
	set(0);
	return *this;
}

template<class T>
inline Vec2<T> Vec2<T>::revert()
{
	T temp = this->x;
	this->x = this->y;
	this->y = temp;

	return *this;
}

template<class T>
inline Vec2<T> Vec2<T>::getMaxOf(const Vec2& v1, const Vec2& v2)
{
	return Vec2((v1.getX() > v2.getX()) ? v1.getX() : v2.getX(), (v1.getY() > v2.getY()) ? v1.getY() : v2.getY());
}

template<class T>
inline Vec2<T> Vec2<T>::getMinOf(const Vec2& v1, const Vec2& v2)
{
	return Vec2((v1.getX() < v2.getX()) ? v1.getX() : v2.getX(), (v1.getY() < v2.getY()) ? v1.getY() : v2.getY());
}

template<class T>
inline Vec2<T> Vec2<T>::randomize(const T& r)
{
	return Vec2(RandNum<T>(0, r), RandNum<T>(0, r));
}

template<class T>
inline Vec2<T> Vec2<T>::randomize(const T& min, const T& max)
{
	return Vec2(RandNum<T>(min, max), RandNum<T>(min, max));
}

template<class T>
inline Vec2<T> Vec2<T>::randomize(const T& minX, const T& maxX, const T& minY, const T& maxY)
{
	return Vec2(RandNum<T>(minX, maxX), RandNum<T>(minY, maxY));
}

template<class T>
inline Vec2<T> Vec2<T>::mutate(const T& m_rate)
{
	this->x += RandNum<T>(-m_rate, m_rate);
	this->y += RandNum<T>(-m_rate, m_rate);
	return *this;
}

template<class T>
inline Vec2<T> Vec2<T>::mutate(const T& m_rateX, const T& m_rateY)
{
	this->x += RandNum<T>(-m_rateX, m_rateX);
	this->y += RandNum<T>(-m_rateY, m_rateY);
	return *this;
}

template<class T>
inline Vec2<T> Vec2<T>::setAngle(const double& angle_deg)
{
	rotate(angle_deg - to_deg(getAngle()));
	return *this;
}

template<class T>
inline Vec2<T> Vec2<T>::expand(const double& mag)
{
	return setMag(getMag() + mag);
}

template<class T>
inline std::string Vec2<T>::toString() const
{
	return "(" + std::to_string(this->x) + "," + std::to_string(this->y) + ")";
}

template<class T>
inline bool Vec2<T>::equals(const Vec2& eq) const
{
	if (this->x == eq.getX() && this->y == eq.getY())
		return true;
	return false;
}

template<class T>
inline bool Vec2<T>::fuzzyEquals(const Vec2& v, const T& acceptance) const
{
	if (acceptance < 0) return false;
	T min = v.x - acceptance;
	T max = v.x + acceptance;
	if ((this->x > min && this->x < max) && (this->y > min && this->y < max)) return true;
	return false;
}

template<class T>
inline bool Vec2<T>::fuzzyEquals(const Vec2& v, const T& acceptanceX, const T& acceptanceY) const
{

	if (acceptanceX < 0 || acceptanceY < 0) return false;
	T minX = v.x - acceptanceX;
	T maxX = v.x + acceptanceX;
	T minY = v.y - acceptanceY;
	T maxY = v.y + acceptanceY;
	if ((this->x > minX && this->x < maxX) && (this->y > minY && this->y < maxY)) return true;
	return false;
}

template<class T>
inline bool Vec2<T>::isZero() const
{
	if (this->x == 0 && this->y == 0)
		return true;
	return false;
}

template<class T>
inline bool Vec2<T>::isOne() const
{
	if (this->x == 1 && this->y == 1)
		return true;
	return false;
}

template<class T>
inline T Vec2<T>::getX() const { return this->x; }

template<class T>
inline T Vec2<T>::getY() const { return this->y; }

template<class T>
inline void Vec2<T>::setX(const T& nb) { this->x = nb; }

template<class T>
inline void Vec2<T>::setY(const T& nb) { this->y = nb; }

template<class T>
inline void Vec2<T>::set(const T& x, const T& y)
{
	this->x = x;
	this->y = y;
}

template<class T>
inline void Vec2<T>::set(const T& val)
{
	this->x = val;
	this->y = val;
}

template<class T>
inline void Vec2<T>::set(const Vec2<T>& v)
{
	this->x = v.x;
	this->y = v.y;
}

template<class T>
inline Vec2<T>::~Vec2() {}

template<class T>
inline Vec2<T> operator+(const Vec2<T>& v1, const Vec2<T>& v2)
{
	return Vec2<T>(v1.getX() + v2.getX(), v1.getY() + v2.getY());
}

template<class T>
inline Vec2<T> operator-(const Vec2<T>& v1, const Vec2<T>& v2)
{
	return Vec2<T>(v1.getX() - v2.getX(), v1.getY() - v2.getY());
}

template<class T>
inline Vec2<T> operator*(const Vec2<T>& v1, const Vec2<T>& v2)
{
	return Vec2<T>(v1.getX() * v2.getX(), v1.getY() * v2.getY());
}

template<class T>
inline Vec2<T> operator/(const Vec2<T>& v1, const Vec2<T>& v2)
{
	return Vec2<T>(v1.getX() / v2.getX(), v1.getY() / v2.getY());
}

template<class T>
inline Vec2<T> operator+=(Vec2<T>& v1, const Vec2<T>& v2)
{
	return v1.add(v2);
}

template<class T>
inline Vec2<T> operator-=(Vec2<T>& v1, const Vec2<T>& v2)
{
	return v1.sub(v2);
}

template<class T>
inline Vec2<T> operator*=(Vec2<T>& v1, const Vec2<T>& v2)
{
	return v1.mult(v2);
}

template<class T>
inline Vec2<T> operator/=(Vec2<T>& v1, const Vec2<T>& v2)
{
	return v1.div(v2);
}

template<class T>
inline std::ostream& operator<<(std::ostream& os, const Vec2<T>& v)
{
	os << v.toString() << std::endl;
	return os;
}

template<class T>
inline bool operator==(const Vec2<T>& v1, const Vec2<T>& v2)
{
	if (v1.equals(v2))
		return true;
	return false;
}

template<class T>
inline bool operator!=(const Vec2<T>& v1, const Vec2<T>& v2)
{
	if (!v1.equals(v2))
		return true;
	return false;
}

template<class T>
inline bool operator>(const Vec2<T>& v1, const Vec2<T>& v2)
{
	if (v1.getMag() > v2.getMag())
		return true;
	return false;
}

template<class T>
inline bool operator<(const Vec2<T>& v1, const Vec2<T>& v2)
{
	if (v1.getMag() < v2.getMag())
		return true;
	return false;
}

template<class T>
inline bool operator>=(const Vec2<T>& v1, const Vec2<T>& v2)
{
	if (v1.getMag() >= v2.getMag())
		return true;
	return false;
}

template<class T>
inline bool operator<=(const Vec2<T>& v1, const Vec2<T>& v2)
{
	if (v1.getMag() <= v2.getMag())
		return true;
	return false;
}