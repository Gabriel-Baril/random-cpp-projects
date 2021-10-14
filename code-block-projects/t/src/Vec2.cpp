#include "Vec2.h"

#include <math.h>
#include <iostream>

Vec2::Vec2() : x(0), y(0) {}
Vec2::Vec2(const double& x_,const double& y_) : x(x_), y(y_) {}

Vec2::Vec2(const Vec2* v)
{
    x = (*v).x;
    y = (*v).y;
} // copy

double Vec2::getX() const
{
    return this->x;
}
double Vec2::getY() const
{
    return this->y;
}
void Vec2::setX(const double& x)
{
    this->x = x;
}
void Vec2::setY(const double& y)
{
    this->y = y;
}

void Vec2::setup(const double& x,const double& y)
{
    this->x = x;
    this->y = y;
}

double Vec2::getMag() const
{
    return sqrt((this->x*this->x)+(this->y*this->y));
}

Vec2* Vec2::add(const Vec2* v)
{
    this->x += (*v).x;
    this->y += (*v).y;

    return this;
}

Vec2* Vec2::add(const double& x,const double& y)
{
    this->x += x;
    this->y += y;

    return this;
}

Vec2* Vec2::sub(const Vec2* v)
{
    this->x -= (*v).x;
    this->y -= (*v).y;

    return this;
}

Vec2* Vec2::sub(const double& x,const double& y)
{
    this->x -= x;
    this->y -= y;

    return this;
}

Vec2* Vec2::div(const Vec2* v)
{
    this->x /= (*v).x;
    this->y /= (*v).y;

    return this;
}

Vec2* Vec2::div(const double& x,const double& y)
{
    this->x /= x;
    this->y /= y;

    return this;
}

Vec2* Vec2::scale(const double& lambda)
{
    this->x *= lambda;
    this->y *= lambda;

    return this;
}

Vec2* Vec2::normalize()
{
    double length = this->getMag();
    this->x /= length;
    this->y /= length;

    return this;
}

double Vec2::dot(const Vec2* v)
{
    return this->x*v->x + this->y*v->y;
}

Vec2* Vec2::getPerpClockwise() const
{
    return new Vec2(-this->y,this->x);
}

Vec2* Vec2::getPerpCounterClockwise() const
{
    return new Vec2(this->y,-this->x);
}

void Vec2::toString() const
{
    std::cout << "(" << this->x << "," << this->y << ")" << std::endl;
}


Vec2::~Vec2()
{
    //dtor
}

