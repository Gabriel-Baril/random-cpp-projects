#ifndef SEGMENT_H
#define SEGMENT_H

#include <Vec2.h>

class Segment
{
public:
    Segment();
    Segment(const Vec2*,const Vec2*);
    Segment(const Segment*);
    virtual ~Segment();

    Vec2* toVect() const;
    double getLength() const;

    Vec2* getStart() const;
    Vec2* getEnd() const;
    void setStart(const Vec2*);
    void setEnd(const Vec2*);

private:
    Vec2* start_;
    Vec2* end_;
};

#endif // SEGMENT_H
