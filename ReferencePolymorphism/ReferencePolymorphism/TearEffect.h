#pragma once

class Tear;

class TearEffect {
public:
    virtual void apply(Tear* context, float luck) = 0;
};