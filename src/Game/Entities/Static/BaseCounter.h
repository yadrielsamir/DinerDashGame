//
// Created by joshu on 11/3/2020.
//

#pragma once

#include "Item.h"
#include "Entity.h"

class BaseCounter: public Entity {
    private:

    public:
        Item *item;
        BaseCounter(int x, int y, int width, int height, Item* item, ofImage sprite);
        Item* getItem();
        void showItem();

};
