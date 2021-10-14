#include "Box.h"
#include <iostream>

using namespace std;

Box::Box()
{
    this->x = 0;
    this->y = 0;
    this->width = 10;
    this->height = 10;
}

Box::Box(double x,double y,int width,int height)
{
    this->x = x;
    this->y = y;
    this->width = width;
    this->height = height;
}

Box::Box(Box* b)
{
    this->x = b->x;
    this->y = b->y;
    this->width = b->width;
    this->height = b->height;
}

double Box::getX() const
{
    return this->x;
}

double Box::getY() const
{
    return this->y;
}

int Box::getWidth() const
{
    return this->width;
}

int Box::getHeight() const
{
    return this->height;
}

void Box::setX(double x)
{
    this->x = x;
}

void Box::setY(double y)
{
    this->y = y;
}

void Box::setWidth(int width)
{
    this->width = width;
}

void Box::setHeight(int height)
{
    this->height = height;
}

void Box::getInformation() const
{
    cout << "Pos : (" << getX() << "," << getY() << ")  Dim : (" << getWidth() << "," << getHeight() << ")" << endl;
}

int Box::getArea() const
{
    return getWidth()*getHeight();
}

bool Box::testCollision(Box* b) const
{
    if(getX() < b->getX() + b->getWidth() &&
        getX() + getWidth() > b->getX() &&
        getY() < b->getY() + b->getHeight() &&
        getY() + getHeight() > b->getY())
    {
        return true;
    }
    return false;
}

bool Box::testCollision(Box* b1,Box* b2)
{
    if(b2->getX() < b1->getX() + b1->getWidth() &&
        b2->getX() + b2->getWidth() > b1->getX() &&
        b2->getY() < b1->getY() + b1->getHeight() &&
        b2->getY() + b2->getHeight() > b1->getY())
    {
        return true;
    }
    return false;
}
