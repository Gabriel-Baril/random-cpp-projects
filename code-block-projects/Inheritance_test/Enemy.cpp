#include "Enemy.h"
#include <ostream>
#include <iostream>

using namespace std;

Enemy::Enemy()
{
    this->life = 100;
}

Enemy::Enemy(int life)
{
    this->life = life;
}

void Enemy::saySomething(string msg) const
{
    cout << msg << "i'm a enemy" << endl;
}

void Enemy::heal(int hp)
{
    this->life += hp;
}

void Enemy::setLife(int life)
{
    this->life = life;
}

int Enemy::getLife() const
{
    return this->life;
}
