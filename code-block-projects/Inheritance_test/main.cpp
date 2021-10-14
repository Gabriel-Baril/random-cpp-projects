#include <iostream>
#include "Enemy.h"
#include "Ninja.h"
#include "Warrior.h"

#include "vector"

using namespace std;

class Cat
{
public:
    bool operator()(int x)
    {
        return x;
    }

};

int main()
{
    Enemy* e = new Ninja(45);
    e->saySomething("Bonjour ");


    return 0;
}
