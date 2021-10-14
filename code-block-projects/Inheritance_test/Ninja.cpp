#include "Enemy.h"
#include "Ninja.h"
#include <iostream>

Ninja::Ninja() : Enemy()
{
}

Ninja::Ninja(int life) : Enemy(life)
{
}

void Ninja::saySomething(string msg) const
{
    cout << msg << "i'm a ninja" << endl;
}
