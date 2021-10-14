#pragma once
#include <string>
#include <iostream>
#include "Vec2.h"

template<class T>
class Segment
{
public:
	Segment();
	Segment(const Vec2<T>&,const Vec2<T>&);
	~Segment();

	struct Equation {
		double coef;
		double b;
		std::string equ = "y = " + std::to_string(coef) + "x + " + std::to_string(b);
	};

	//Equation getEqu() const { return this->equation; }

	Vec2<T> start;
	Vec2<T> end;
	Equation equation;
};

