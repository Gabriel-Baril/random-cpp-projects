#include "GameObject.h"

GameObject::GameObject()
{
    //ctor
}

GameObject::GameObject(const Vec2* p)
{
    this->pos = new Vec2(*p);
}

GameObject::GameObject(const Vec2* p,const Vec2* v) : GameObject(p)
{
    this->vel = new Vec2(*v);
}

GameObject::GameObject(const Vec2* p,const Vec2* v,const Vec2* a) : GameObject(p,v)
{
    this->acc = new Vec2(*a);
}

Vec2* GameObject::getPos() const
{
    return (*this).pos;
}

Vec2* GameObject::getVel() const
{
    return (*this).vel;
}

Vec2* GameObject::getAcc() const
{
    return (*this).acc;
}

void GameObject::setPos(const Vec2* p)
{
    this->pos = new Vec2(*p);
}

void GameObject::setVel(const Vec2* v)
{
    this->vel = new Vec2(*v);
}

void GameObject::setAcc(const Vec2* a)
{
    this->acc = new Vec2(*a);
}

GameObject::~GameObject()
{
    //dtor
}
