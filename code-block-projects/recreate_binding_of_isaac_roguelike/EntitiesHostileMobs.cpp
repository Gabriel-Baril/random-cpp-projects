#include "EntitiesHostileMobs.h"
#include <iostream>
#include <string>
#include <math.h>
#include <vector>

using namespace std;

//constructor

EntitiesHostileMobs::EntitiesHostileMobs() : m_posX(0), m_posY(0), m_type(1), m_speed(1), m_life(100), m_damagePerHitCac(1), m_damagePerHitProjectile(1), m_isSpawn(false)
{
}

EntitiesHostileMobs::EntitiesHostileMobs(int posX, int posY,int type,int speed,int life,int damagePerHitCac,int damagePerHitProjectile) : m_posX(posX), m_posY(posY),m_type(type) ,m_speed(speed), m_life(life), m_damagePerHitCac(damagePerHitCac), m_damagePerHitProjectile(damagePerHitProjectile)
{
}

//Accessor(getter) method

EntitiesHostileMobs::getMobsPosX() const {return m_posX;}
EntitiesHostileMobs::getMobsPosY() const {return m_posY;}
EntitiesHostileMobs::getMobsLife() const {return m_life;}
EntitiesHostileMobs::getMobsSpeed() const {return m_speed;}
EntitiesHostileMobs::getMobsType() const {return m_type;}
EntitiesHostileMobs::getMobsDamagePerHitCac() const {return m_damagePerHitCac;}
EntitiesHostileMobs::getMobsDamagePerHitProjectile() const {return m_damagePerHitProjectile;}
EntitiesHostileMobs::getMobsMass() const {return m_mass;}
EntitiesHostileMobs::getMobsSizeX() const {return m_sizeX;}
EntitiesHostileMobs::getMobsSizeY() const {return m_sizeY;}
EntitiesHostileMobs::getMobsNbKill() const {return m_nbKill;}
EntitiesHostileMobs::getMobsDamageReceived() const {return m_damageReceived;}
EntitiesHostileMobs::getMobsId() const {return m_id;}

EntitiesHostileMobs::getMobsNbSprite() const {return m_nbSprite;}
string EntitiesHostileMobs::getMobsBasicSprite() const {return m_accessPathBasicSprite;}
string EntitiesHostileMobs::getMobsCurrentSprite() const {return m_accessPathCurrentSprite;}
string EntitiesHostileMobs::getMobsName() const {return m_nameMob;}


bool EntitiesHostileMobs::getMobsIsSpawn() const {return m_isSpawn;}
bool EntitiesHostileMobs::getMobsIsDead() const {return m_isDead;}
bool EntitiesHostileMobs::getMobsIsMoving() const {return m_isMoving;}
bool EntitiesHostileMobs::getMobsIsShooting() const {return m_isShooting;}
bool EntitiesHostileMobs::getMobsIsCollideWith() const {return m_isCollideWith;}
bool EntitiesHostileMobs::getMobsIsDetectSomethings() const {return m_isDetectSomething;}

//Mutator(setter) method

void EntitiesHostileMobs::setMobsLife(int life) {m_life = life;}
void EntitiesHostileMobs::setMobsPosX(int posX) {m_posX = posX;}
void EntitiesHostileMobs::setMobsPosY(int posY) {m_posY = posY;}
void EntitiesHostileMobs::setMobsPosition(int posX, int posY) {m_posX = posX; m_posY = posY;}
void EntitiesHostileMobs::setMobsPositionAndLife(int life, int posX, int posY) {m_life = life; m_posX = posX; m_posY = posY;}
void EntitiesHostileMobs::setMobsBasicInformation(int life, int type, int posX, int posY, int speed) {m_life = life; m_type = type; m_posX = posX; m_posY = posY; m_speed = speed;}
void EntitiesHostileMobs::setMobsSpeed(int speed) {m_speed = speed;}
void EntitiesHostileMobs::setMobsType(int type) {m_type = type;}
void EntitiesHostileMobs::setMobsDamagePerHitCac(int damagePerHitCac) {m_damagePerHitCac = damagePerHitCac;}
void EntitiesHostileMobs::setMobsDamagePerHitProjectile(int damagePerHitProjectile) {m_damagePerHitProjectile = damagePerHitProjectile;}
void EntitiesHostileMobs::setMobsMass(int mass) {m_mass = mass;}
void EntitiesHostileMobs::setMobsSizeX(int sizeX) {m_sizeX = sizeX;}
void EntitiesHostileMobs::setMobsSizeY(int sizeY) {m_sizeY = sizeY;}
void EntitiesHostileMobs::setMobsNbKill(int nbKill) {m_nbKill = nbKill;}
void EntitiesHostileMobs::setMobsDamageReceived(int damageReceived) {m_damageReceived = damageReceived;}
void EntitiesHostileMobs::setMobsId(int id) {m_id = id;}

void EntitiesHostileMobs::setMobsNbSprite(int nbSprite) {m_nbSprite = nbSprite;}
void EntitiesHostileMobs::setMobsBasicSprite(std::string accessPathBasicSprite) {m_accessPathBasicSprite = accessPathBasicSprite;}
void EntitiesHostileMobs::setMobsCurrentSprite(std::string accessPathCurrentSprite) {m_accessPathCurrentSprite = accessPathCurrentSprite;}
void EntitiesHostileMobs::setMobsName(std::string nameMob) {m_nameMob = nameMob;}

void EntitiesHostileMobs::setMobsIsDead(bool isDead) {m_isDead = isDead;}
void EntitiesHostileMobs::setMobsIsSpawn(bool isSpawn) {m_isSpawn = isSpawn;}
void EntitiesHostileMobs::setMobsIsMoving(bool isMoving) {m_isMoving = isMoving;}
void EntitiesHostileMobs::setMobsIsShooting(bool isShooting) {m_isShooting = isShooting;}
void EntitiesHostileMobs::setMobsIsCollideWith(bool isCollideWith) {m_isCollideWith = isCollideWith;}
void EntitiesHostileMobs::setMobsIsDetectSomethings(bool isDetectSomething) {m_isDetectSomething = isDetectSomething;}

//method

void EntitiesHostileMobs::moveRight() {m_posX++;}
void EntitiesHostileMobs::moveLeft() {m_posX--;}
void EntitiesHostileMobs::moveUp() {m_posY--;}
void EntitiesHostileMobs::moveDown() {m_posY++;}

