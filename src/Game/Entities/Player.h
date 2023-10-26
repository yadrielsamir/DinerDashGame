#pragma once
#include "Animation.h"
#include "Burger.h"
#include "EntityManager.h"
#include "BaseCounter.h"
#include "StoveCounter.h"
class Player: public Entity{

    private:
        int speed = 5;
        string facing = "right";
        Animation *chefAnim;
        Burger *burger;
        EntityManager* entityManager;
        bool ingredientAdded = false;
    public:
        Player(int x, int y, int width, int height, ofImage sprite, EntityManager* em);
        void tick();
        void render();
        void keyPressed(int);
        void keyReleased(int);
        void mousePressed(int, int, int);
        void setFacing(string);
        BaseCounter* getActiveCounter();
        StoveCounter* getActiveStoveCounter();
        bool cooking = false;
        bool cooked = false;
        Item* item;
        int scx;
        int scy;
        int scwidth;
        int scheight;
        // Getters
        Burger* getBurger(){ return burger;}
        bool getIngredientAdded() {return ingredientAdded;}

        // Setters
        void setIngredientAdded(bool x) {ingredientAdded = x;}
};