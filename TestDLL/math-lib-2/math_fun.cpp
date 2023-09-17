#include "math_fun.h"

static int inccount = 0;

int add(int a, int b)
{
	return a + b;
}

int sub(int a, int b)
{
	return a - b;
}

void inc()
{
	inccount++;
}

int get_inc()
{
	return inccount;
}