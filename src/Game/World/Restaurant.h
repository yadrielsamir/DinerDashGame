//
// Created by joshu on 11/3/2020.
//
#pragma once

#include "BaseCounter.h"
#include "EntityManager.h"
#include "Player.h"
#include "ofMain.h"
#include "Inspector.h"
#include "StoveCounter.h"

class Restaurant {
    private:
        Player* player;
        int ticks=0;
        std::vector<ofImage> people;

    public:
        EntityManager* entityManager;
        int money =0;
        Restaurant();
        Player* getPlayer();
        void setPlayer(Player *player);
        Item* cheese;
        Item* lettuce;
        Item* tomato;
        Item* burger;
        Item* botBread;
        Item* topBread;
        ofImage floor;
        ofImage chairImg; 
        ofImage tableImg;
        ofImage plantImg;
        void initItems();
        void initCounters();
        void initClients();
        void generateClient();
        void serveClient();
        void tick();
        void render();
        void keyPressed(int key);
        int stoveticks;
};
