#include <iostream>
#define ADD_ONE(x) x+1
#define LAMBDA(FUN, y, z) FUN(ADD_ONE(y), ADD_ONE(z))
#define CONCAT(S1, S2) (#S1#S2)
#define CONST(a) const a
#define SIG(FUN) "1"#FUN
#define PRINT(STR) #STR
#define PRINT_UNTIL(STR, NB_TIMES) (((NB_TIMES) >= 0) ? PRINT(STR) : PRINT(STR) ## PRINT(STR))
#define POINT(TYPE, NB_POINTER) TYPE*

int add(int a, int b)
{
	return a + b;
}

int main()
{
	POINT(int, 3) a;

	std::cout << PRINT_UNTIL(*, -1) << std::endl;
	//std::cout << CONCAT(HELLO, WORLD) << std::endl;
	//std::cout << ADD_ONE(2) << std::endl;
	return 0;
}