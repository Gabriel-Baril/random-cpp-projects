#ifndef SHAPE_H
#define SHAPE_H

#include <GameObject.h>
#include <Vec2.h>
#include <Segment.h>
#include <vector>

class Shape : public GameObject
{
public:
    Shape();
    Shape(std::vector<const Vec2*>*);
    Shape(const Shape&);
    virtual ~Shape();

    std::vector<const Vec2*>* getVertices() const;
    std::vector<const Segment*>* getSegments() const;

    void update() override;
    void render() override;

private:
    std::vector<const Vec2*>* vertices;

};

#endif // SHAPE_H
