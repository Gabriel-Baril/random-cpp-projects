#ifndef VEC2_H
#define VEC2_H

#include <string>

class Vec2
{
public:
    Vec2();
    Vec2(double,double);
    Vec2(const Vec2& v); // copy
    virtual ~Vec2();

    double getX() const;
    double getY() const;
    void setX(double);
    void setY(double);
    void setup(double,double);

    double getMag() const;
    double dot(const Vec2&);

    Vec2 add(const Vec2&);
    Vec2 add(const double&,const double&);
    Vec2 sub(const Vec2&);
    Vec2 sub(const double&,const double&);
    Vec2 div(const Vec2&);
    Vec2 div(const double&,const double&);
    Vec2 scale(const double&);
    Vec2 normalize();

    Vec2 getPerpClockwise() const;
    Vec2 getPerpCounterClockwise() const;

    void toString() const;

private:
    double x;
    double y;
};

#endif // VEC2_H
