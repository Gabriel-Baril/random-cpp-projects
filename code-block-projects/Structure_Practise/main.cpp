#include <iostream>
#include <Vec2.h>

using namespace std;

int main()
{
    Vec2* vec = new Vec2(5,5);
    (*vec).getPerpClockwise().toString();
    return 0;
}
