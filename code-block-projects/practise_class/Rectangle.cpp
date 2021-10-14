#include <iostream>
#include <string>
#include "Rectangle.h"

using namespace std;

Rectangle::Rectangle() : m_x(0), m_y(0), m_width(10), m_height(10), m_velocity(0)
{
}

Rectangle::Rectangle(int x, int y, int width, int height, int velocity) : m_x(x), m_y(y), m_width(width), m_height(height), m_velocity(velocity)
{
}

int Rectangle::getX() const
{
    return m_x;
}

int Rectangle::getY() const
{
    return m_y;
}

int Rectangle::getWidth() const
{
    return m_width;
}

int Rectangle::getHeight() const
{
    return m_height;
}

int Rectangle::getVelocity() const
{
    return m_velocity;
}

int Rectangle::getInformation() const
{
    cout << "x : " << getX() << endl;
    cout << "y : " << getY() << endl;
    cout << "width : " << getWidth() << endl;
    cout << "height : " << getHeight() << endl;
    cout << "velocity : " << getVelocity() << endl;
}

void Rectangle::setX(int x)
{
    m_x = x;
}

void Rectangle::setY(int y)
{
    m_y = y;
}

void Rectangle::setWidth(int width)
{
    m_width = width;
}

void Rectangle::setHeight(int height)
{
    m_height = height;
}

void Rectangle::setVelocity(int velocity)
{
    m_velocity = velocity;
}

void Rectangle::setPosition(int x, int y)
{
    m_x = x;
    m_y = y;
}

void Rectangle::setDimention(int width, int height)
{
    m_width = width;
    m_height = height;
}

void Rectangle::setAll(int x, int y, int width, int height, int velocity)
{
    m_x = x;
    m_y = y;
    m_width = width;
    m_height = height;
    m_velocity = velocity;
}

void Rectangle::translateRectX(int x)
{
    m_x += x;
}

void Rectangle::translateRectY(int y)
{
    m_y += y;
}

void Rectangle::move_rect(int x, int y)
{
    m_x += x;
    m_y += y;
}

void Rectangle::addVelocity(int velocity)
{
    m_velocity += velocity;
}

