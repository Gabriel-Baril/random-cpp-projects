#pragma once
#include "cpp_includes.h"
#include "opengl_includes.h"
#include <cstdlib>
#include <random>


class Random
{
public:
	Random(GLulong seed,GLdouble min, GLdouble max);
	double next() const;
private:
	GLulong seed;
	GLdouble min;
	GLdouble max;
};