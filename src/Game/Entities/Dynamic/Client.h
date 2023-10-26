#pragma once
#include "Entity.h"
#include "Burger.h"

class Client: public Entity{
    private:
        Burger* burger;
        int patience=2000;
        int originalPatience;
    public:
        Client(int, int, int, int, ofImage, Burger*);
        virtual ~Client();
        void tick();
        void render();
        int serve(Burger* burger);
        Client* nextClient=nullptr;
        bool isLeaving=false;
        int clientLeft=0;
        int getPatience() const {return patience;}
        Burger* getBurger() { return burger; }
        bool isInspector = false;
};