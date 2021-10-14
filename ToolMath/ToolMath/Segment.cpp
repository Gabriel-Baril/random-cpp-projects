#include "stdafx.h"
#include "Segment.h"

template<class T>
Segment<T>::Segment()
{
}

template<class T>
Segment<T>::Segment(const Vec2<T>& start, const Vec2<T>& end)
{
	this->start = start;
	this->end = end;
	this->equation.coef = (end.getY() - start.getY()) / (end.getX() - start.getX());
	this->equation.b = start.getY() - this->equation.coef*start.getX();
}

template<class T>
Segment<T>::~Segment()
{
}
