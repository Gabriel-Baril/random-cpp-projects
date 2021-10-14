 #include "opengl_includes.h"
 #include "cpp_includes.h"
 #include "Random.h"
 
class PerlinNoise
{
public:
	PerlinNoise();
	float lerp(const GLfloat&,const GLfloat&, const GLfloat&);
	float dotGridGradient(const GLint&,const GLint&,const GLfloat&,const GLfloat&);
	float perlin(const GLfloat&,const GLfloat&);
private:
	Random random;
	double frequence;
	double octave;
	double persistence;
	double lacunarity;
};