#pragma once
#include "TearEffect.h"

class FireTearEffect : public TearEffect {
public:
    virtual void apply(Tear* context, float luck);
};