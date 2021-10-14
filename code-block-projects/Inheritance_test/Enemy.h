#ifndef ENEMY_H_INCLUDED
#define ENEMY_H_INCLUDED

#include <string>

using namespace std;

class Enemy
{
public:
    Enemy();
    Enemy(int);

    virtual void saySomething(string) const;
    void heal(int);
    void setLife(int);
    int getLife() const;



private:
    int life;
};


#endif // ENEMY_H_INCLUDED
