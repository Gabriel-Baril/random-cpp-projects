#include <iostream>
#include <string>
#include <tuple>
#include <memory>
#include <vector>
// HEX
// RGB
// RGBA
// HSV
// HSB
// CMY
// CMYK
// RYB
// YUV
// LAB
// XYZ

using uchar = unsigned char;

struct RGB
{
    uchar r;
    uchar g;
    uchar b;
    RGB(uchar r_, uchar g_, uchar b_) : r{ r_ }, g{ g_ }, b{ b_ } {}

    friend std::ostream& operator<<(std::ostream& os, const RGB& rgb)
    {
        return os << "[" << (int)rgb.r << "," << (int)rgb.g << "," << (int)rgb.b << "]\n";
    }
};

struct RGBA
{
    uchar r;
    uchar g;
    uchar b;
    uchar a;
    RGBA(uchar r_, uchar g_, uchar b_, uchar a_) : r{ r_ }, g{ g_ }, b{ b_ }, a{ a_ } {}
    friend std::ostream& operator<<(std::ostream& os, const RGBA& rgba)
    {
        return os << "[" << (int)rgba.r << "," << (int)rgba.g << "," << (int)rgba.b << "," << (int)rgba.a << "]\n";
    }
};



template<typename T> struct ColorAdapter;

template<>
struct ColorAdapter<RGB>
{
    static RGB& process(RGB& rgb)
    {
        std::cout << "RGB process : " << rgb;
        return rgb;
    }
};

template<>
struct ColorAdapter<RGBA>
{
    static RGBA& process(RGBA& rgba)
    {
        std::cout << "RGBA process : " << rgba;
        return rgba;
    }
};

template<typename ColorFormat>
struct Line
{
    ColorFormat cf;
    void render()
    {
        ColorAdapter<ColorFormat>::process(cf);
    }
};

struct Vec2
{
    float x;
    float y;

    operator std::string()
    {
        return "[" + std::to_string(x) + "," + std::to_string(y) + "]";
    }
};

class Component
{
public:
    virtual std::string get_name() = 0;
};

class ComponentDecorator : public Component
{

};

class WindowDecorator : public ComponentDecorator
{

};

class Window : public Component
{
    Vec2 pos;
    float width;
    float height;
    std::vector<std::shared_ptr<Component>> children;
public:
    Window(const Vec2& pos, float width, float height) : pos{ pos }, width{ width }, height{ height } {}
    virtual std::string get_name() override
    {
        return "Window[POS:" + (std::string)pos + ", DIM:[" + std::to_string(width) + "," + std::to_string(height) + "]], ";
    }
};

class VerticalScrollBarDecorator : public WindowDecorator
{
public:
    enum class VerticalScrollBarPosition
    {
        LEFT,
        RIGHT
    };
    Component* component;
    VerticalScrollBarPosition pos;
    float thickness;
    VerticalScrollBarDecorator(Component* component, VerticalScrollBarPosition pos, float thickness) : component{ component }, pos{ pos }, thickness{ thickness } {}
    virtual std::string get_name() override
    {
        std::string info = "VerticalScrollBar[SCROLL_POS: ";
        switch (pos)
        {
            case VerticalScrollBarPosition::LEFT:
                info += "LEFT";
                break;
            case VerticalScrollBarPosition::RIGHT:
                info += "RIGHT";
                break;
        }
        info += ", THICKNESS: " + std::to_string(thickness) + "],";
        return component->get_name() + info;
    }
};

class Colored



int main()
{
    Window window = Window({1, 2}, 1920, 1080);
    VerticalScrollBarDecorator scrollBar = VerticalScrollBarDecorator(&window, VerticalScrollBarDecorator::VerticalScrollBarPosition::RIGHT, 20);
    std::cout << scrollBar.get_name() << '\n';
}