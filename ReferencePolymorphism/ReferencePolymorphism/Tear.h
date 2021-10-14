#pragma once
#include <vector>
class TearEffect;

class Tear {
public:
    Tear();
    void spawn(int direction);
    void addEffect(TearEffect* effect);
    ~Tear();
private:
    std::vector<TearEffect*> effects;
};