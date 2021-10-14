#pragma once
#include "TearEffect.h"

class PercingTearEffect : public TearEffect {
public:
    virtual void apply(Tear* context, float luck);
};