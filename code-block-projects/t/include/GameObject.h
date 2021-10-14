#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <Vec2.h>

class GameObject
{
public:
    GameObject();
    GameObject(const Vec2*);
    GameObject(const Vec2*,const Vec2*);
    GameObject(const Vec2*,const Vec2*,const Vec2*);
    virtual ~GameObject();

    //virtual double getArea() = 0;
    virtual void update() = 0;
    virtual void render() = 0;

    virtual Vec2* getPos() const;
    virtual Vec2* getVel() const;
    virtual Vec2* getAcc() const;
    virtual void setPos(const Vec2*);
    virtual void setVel(const Vec2*);
    virtual void setAcc(const Vec2*);
private:
    Vec2* pos;
    Vec2* vel;
    Vec2* acc;
};

#endif // GAMEOBJECT_H
