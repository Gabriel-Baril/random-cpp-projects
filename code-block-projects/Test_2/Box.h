#ifndef BOX_H_INCLUDED
#define BOX_H_INCLUDED

class Box
{
public:
    Box();
    Box(double,double,int,int);
    Box(Box*);

    void setX(double);
    void setY(double);
    void setWidth(int);
    void setHeight(int);
    double getX() const;
    double getY() const;
    int getWidth() const;
    int getHeight() const;

    void getInformation() const;
    int getArea() const;
    bool testCollision(Box*) const;
    static bool testCollision(Box*,Box*);
private:
    int width,height;
    double x,y;
};

#endif // BOX_H_INCLUDED
