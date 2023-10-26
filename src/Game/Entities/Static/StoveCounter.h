#pragma once
#include "BaseCounter.h"

class StoveCounter : public BaseCounter {
public:
    StoveCounter(int, int, int, int, Item*, ofImage);
    void startCooking();
    bool isBurgerReady();
    void update();
    // void showItem();
    bool cooking = false;
    bool cooked = false;
private:
    
    int ticks = 0;
    bool cooker;
};