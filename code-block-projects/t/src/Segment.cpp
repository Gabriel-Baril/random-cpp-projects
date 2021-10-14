#include "Segment.h"
#include <iostream>

Segment::Segment()
{
    //ctor
}

Segment::Segment(const Vec2* st,const Vec2* ed)
{
    start_ = new Vec2(*st);
    end_ = new Vec2(*ed);
}


Segment::Segment(const Segment* cop)
{
    start_ = new Vec2(*(cop->start_));
    end_ = new Vec2(*(cop->end_));
}

Vec2* Segment::toVect() const
{
    return new Vec2((*end_).getX() - (*start_).getX(),(*end_).getY() - (*start_).getY());
}

double Segment::getLength() const
{
    return (*toVect()).getMag();
}

Vec2* Segment::getStart() const
{
    return (*this).start_;
}

Vec2* Segment::getEnd() const
{
    return (*this).end_;
}

void Segment::setStart(const Vec2* vec)
{
    start_ = new Vec2(*vec);
}

void Segment::setEnd(const Vec2* vec)
{
    end_ = new Vec2(*vec);
}

Segment::~Segment()
{
    //dtor
}
