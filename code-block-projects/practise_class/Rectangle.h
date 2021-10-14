#ifndef RECTANGLE_H_INCLUDED
#define RECTANGLE_H_INCLUDED

class Rectangle
{
    public:

    Rectangle();
    Rectangle(int x, int y, int width, int height, int velocity);

    int getX() const;
    int getY() const;
    int getWidth() const;
    int getHeight() const;
    int getVelocity() const;

    int getInformation() const;

    void setX(int x);
    void setY(int y);
    void setWidth(int width);
    void setHeight(int height);
    void setVelocity(int velocity);

    void setPosition(int x, int y);
    void setDimention(int width, int height);
    void setAll(int x, int y, int width, int height, int velocity);

    void translateRectX(int x);
    void translateRectY(int y);
    void move_rect(int x, int y);
    void addVelocity(int velocity);

    private:

    int m_x;
    int m_y;
    int m_width;
    int m_height;
    int m_velocity;
};


#endif // RECTANGLE_H_INCLUDED
