#include "pch.h"
#include "math_fun.h"
#include "log_fun.h"

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
	log("Fuck");
	return inccount;
}
