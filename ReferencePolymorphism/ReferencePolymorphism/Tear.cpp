#include "Tear.h"
#include "TearEffect.h"

Tear::Tear()
    : effects{}
{
    effects.reserve(10);
}

void Tear::spawn(int direction) {
    for (TearEffect* effect : effects) {
        effect->apply(this, 1);
    }
}

void Tear::addEffect(TearEffect* effect) {
    effects.push_back(effect);
}

Tear::~Tear()
{
    for (TearEffect* effect : effects) {
        if (effect != nullptr) {
            delete effect;
            effect = nullptr;
        }
    }
}