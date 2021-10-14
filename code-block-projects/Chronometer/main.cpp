#include <iostream>
#include <Chrono.h>

using namespace std;

int main()
{
    Chrono c(0,0,0,0);
    while(true){
        c.setMilliSecond(c.getMilliSecond() + 1);
        c.show();
    }

    return 0;
}
