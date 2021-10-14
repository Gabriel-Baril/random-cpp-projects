#include "Box.h"

Box::Box()
{
    //ctor
}

Box::Box(const double& w,const double& h)
{
    this->width = w;
    this->height = h;
    setPos(new Vec2(0,0));
    setVel(new Vec2(0,0));
    setAcc(new Vec2(0,0));
}

Box::Box(const Vec2* p,const double& w,const double& h) : GameObject(p)
{
    Box(w,h);
    setVel(new Vec2(0,0));
    setAcc(new Vec2(0,0));
}

Box::Box(const Vec2* p,const Vec2* v,const double& w,const double& h) : GameObject(p,v)
{
    Box(w,h);
    setAcc(new Vec2(0,0));
}

Box::Box(const Vec2* p,const Vec2* v,const Vec2* a,const double& w,const double& h) : GameObject(p,v,a)
{
    Box(w,h);
}

void Box::update()
{
    setPos(getPos()->add(getVel()));
    setVel(getVel()->add(getAcc()));
}

void Box::render()
{

}

Box::~Box()
{
    //dtor
}
