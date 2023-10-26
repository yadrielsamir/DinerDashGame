#pragma once
#include "Client.h"

class Inspector : public Client{
private:
    bool badReview;
public:
    Inspector(int x, int y, int width, int height, ofImage sprite, Burger* burger) : Client(x, y, width, height, sprite, burger){
        badReview = false;
    }
    bool getReview() {return badReview;}
    void setReview(bool b) {badReview = b;}
};
