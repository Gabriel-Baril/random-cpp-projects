#ifndef ENTITIESHOSTILEMOBS_H_INCLUDED
#define ENTITIESHOSTILEMOBS_H_INCLUDED

#include <string>

class EntitiesHostileMobs
{
public:

    EntitiesHostileMobs();
    EntitiesHostileMobs(int posX, int posY,int type,int speed,int life,int damagePerHitCac = 1,int damagePerHitProjectile = 1);

    //Accessor(getter) method

    int getMobsLife() const;
    int getMobsPosX() const;
    int getMobsPosY() const;
    int getMobsSpeed() const;
    int getMobsType() const;
    int getMobsDamagePerHitCac() const;
    int getMobsDamagePerHitProjectile() const;
    int getMobsMass() const;
    int getMobsSizeX() const;
    int getMobsSizeY() const;
    int getMobsNbKill() const;
    int getMobsDamageReceived() const;
    int getMobsId() const;

    std::string getMobsBasicSprite() const;
    int getMobsNbSprite() const;
    std::string getMobsCurrentSprite() const;
    std::string getMobsName() const;

    bool getMobsIsDead() const;
    bool getMobsIsSpawn() const;
    bool getMobsIsMoving() const;
    bool getMobsIsShooting() const;
    bool getMobsIsCollideWith() const;
    bool getMobsIsDetectSomethings() const;

    //Mutator(setter) method

    void setMobsLife(int life);
    void setMobsPosX(int posX);
    void setMobsPosY(int posY);
    void setMobsPosition(int posX, int posY);
    void setMobsPositionAndLife(int life, int posX, int posY);
    void setMobsBasicInformation(int life, int type, int posX, int posY, int speed);
    void setMobsDamage(int damagePerHitProjectile, int damagePerHitCac = 1);
    void setMobsSpeed(int speed);
    void setMobsType(int type);
    void setMobsDamagePerHitCac(int damagePerHitCac);
    void setMobsDamagePerHitProjectile(int damagePerHitProjectile);
    void setMobsMass(int mass);
    void setMobsSizeX(int sizeX);
    void setMobsSizeY(int sizeY);
    void setMobsNbKill(int nbKill);
    void setMobsDamageReceived(int damageReceived);
    void setMobsId(int id);

    void setMobsNbSprite(int nbSprite);
    void setMobsBasicSprite(std::string accessPathBasicSprite);
    void setMobsCurrentSprite(std::string accessPathCurrentSprite);
    void setMobsName(std::string nameMob);

    void setMobsIsDead(bool isDead);
    void setMobsIsSpawn(bool isSpawn);
    void setMobsIsMoving(bool isMoving);
    void setMobsIsShooting(bool isShooting);
    void setMobsIsCollideWith(bool isCollideWith);
    void setMobsIsDetectSomethings(bool isDetectSomething);

    //method

    void moveRight();
    void moveLeft();
    void moveUp();
    void moveDown();

protected:

    int m_posX;
    int m_posY;
    int m_type;
    int m_speed;
    int m_life;
    int m_damagePerHitCac;
    int m_damagePerHitProjectile;
    int m_mass;
    int m_sizeX;
    int m_sizeY;
    int m_nbSprite;
    std::string m_spriteList[];
    std::string m_accessPathCurrentSprite;
    std::string m_accessPathBasicSprite;
    std::string m_nameMob;
    int m_id;
    bool m_isMoving;
    bool m_isDead;
    bool m_isCollideWith;
    bool m_isShooting;
    bool m_isDetectSomething;
    bool m_isSpawn;
    int m_damageReceived;
    int m_nbKill;

};

#endif // ENTITIESHOSTILEMOBS_H_INCLUDED
