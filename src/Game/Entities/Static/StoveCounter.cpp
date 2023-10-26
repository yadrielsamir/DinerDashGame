#include "StoveCounter.h"

StoveCounter::StoveCounter(int x, int y, int width, int height, Item* item, ofImage sprite) : BaseCounter(x, y, width, height, item, sprite) {
   cooker = true;
}

void StoveCounter::startCooking() {
    cooking = true;
}

bool StoveCounter::isBurgerReady() {
    if (cooking && ticks >= 10) {
        ticks = 0;
        return true;
    }
    return false;
}

