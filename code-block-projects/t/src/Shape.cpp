#include "Shape.h"

Shape::Shape()
{
    //ctor
}

Shape::Shape(std::vector<const Vec2*>* vertices)
{
    this->vertices = vertices;
}

Shape::Shape(const Shape& shape)
{
    *this = shape;
}

std::vector<const Vec2*>* Shape::getVertices() const
{
    return (*this).vertices;
}

std::vector<const Segment*>* Shape::getSegments() const
{
    std::vector<const Segment*>* segments = new std::vector<const Segment*>();
    for(unsigned int i = 0; i < vertices->size(); i++)
    {
        unsigned int next = (i == vertices->size() - 1) ? 0 : (i + 1);
        segments->push_back(new Segment(vertices->at(i),vertices->at(next)));
    }
    return segments;
}

void Shape::update()
{
    setVel(getVel()->add(getAcc()));
    for(unsigned int i = 0;i < this->vertices->size();i++){
        this->vertices->at(i)->add(getVel());kk
    }
}

void Shape::render()
{


}

Shape::~Shape()
{
    //dtor
}
