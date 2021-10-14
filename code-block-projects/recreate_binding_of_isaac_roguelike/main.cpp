#include "EntitiesHostileMobs.h"
#include <iostream>
#include <time.h>

using namespace std;

int main()
{
    EntitiesHostileMobs enemy;

    enemy.setMobsName("enemy");
    enemy.setMobsBasicInformation(100,2,30,45,5);

    cout << "ATTRIBUTS DE ENEMY" << endl << endl;
    cout << "LIFE : " << enemy.getMobsLife() << endl;
    cout << "TYPE : " << enemy.getMobsType() << endl;
    cout << "POSITION X : " << enemy.getMobsPosX() << endl;
    cout << "POSITION Y : " << enemy.getMobsPosY() << endl;
    cout << "SPEED : " << enemy.getMobsSpeed() << endl;


    return 0;
}
