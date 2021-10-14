#ifndef BOX_H
#define BOX_H

#include <GameObject.h>
#include <Vec2.h>

class Box : public GameObject
{
public:
    Box();
    Box(const double&,const double&);
    Box(const Vec2*,const double&,const double&);
    Box(const Vec2*,const Vec2*,const double&,const double&);
    Box(const Vec2*,const Vec2*,const Vec2*,const double&,const double&);
    virtual ~Box();

    void update();
    void render();
private:
    double width;
    double height;
};

#endif // BOX_H
