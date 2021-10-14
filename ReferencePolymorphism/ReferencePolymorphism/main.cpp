// Online C++ compiler to run C++ program online
#include <iostream>
#include <vector>
#include <string>

#include "Tear.h"
#include "FireTearEffect.h"
#include "PercingTearEffect.h"

void* operator new(size_t size)
{
    std::cout << size << " byte(s)" << std::endl;
    void* p = malloc(size);
    return p;
}

struct Color {
    float r, g, b, a;
};

struct TearEntity {
    TearEntity(Tear* model, float x, float y, float baseDamage, float baseSpeed, float baseRange, float luck) {
        
    }

    bool spawn();

    float x, y;
    float speed;
    float range;
    float damage;
    Color tearColor;
    float luck;
    
    bool isPercing;
    bool isFlaming;
    TearEffect* effects[4];
    Tear* model;
};

int main() {
    Tear model;
    model.addEffect(new FireTearEffect);
    model.addEffect(new PercingTearEffect);


    return 0;
}