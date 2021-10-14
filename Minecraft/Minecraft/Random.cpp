 #include "Random.h"
 
 Random::Random(GLulong seed,GLdouble min,GLdouble max)
 {
	this->seed = seed;
	this->min = min;
	this->max = max;
	srand(seed);
 }
 
 double Random::next() const
 {
	return min + ((float)rand() / (float)RAND_MAX) * (max - min);
 }
 