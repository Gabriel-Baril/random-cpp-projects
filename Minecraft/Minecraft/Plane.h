#pragma once
#include "cpp_includes.h"
#include "opengl_includes.h"

class Plane
{
public:
	Plane(vec3 A, vec3 B, vec3 C, vec3 D)
	{
		this->normal = glm::cross(B - A, C - B);
		this->scalarComp = -this->normal * A;
		this->A = A;
		this->B = B;
		this->C = C;
		this->D = D;
	}
	vec3 normal;
	vec3 scalarComp;
	vec3 A;
	vec3 B;
	vec3 C;
	vec3 D;
};