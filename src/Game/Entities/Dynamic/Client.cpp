#include "Client.h"

Client::Client(int x, int y, int width, int height, ofImage sprite, Burger* burger): Entity(x, y, width, height, sprite){
    this->burger = burger;
}
Client::~Client(){
    delete burger;
}
void Client::render(){
    burger->render();
    if (isInspector){
        ofSetColor ((255)*patience/2000.0, 255*(patience/2000.0), 255);
    }
    else {
        ofSetColor (255, (patience/2000.0)*255, (patience/2000.0)*255);        
    }
    sprite.draw(x, y, width, height);
    ofSetColor(255,255,255);
    if(nextClient != nullptr){
        nextClient->render();
    }
}

void Client::tick(){
    patience-= 1;
    burger->setY(y);
    if(patience == 0){
        isLeaving = true;
    }
    if(nextClient != nullptr){
        nextClient->tick();
    }
}

int Client::serve(Burger* burger) {
    if (this->burger->equals(burger)) {
        isLeaving = true;
        int cost = 0;
        for (Item * i : burger->getIngredients()) {
            if (i->name == "topBun" || i->name == "bottomBun") {
                cost += 1;
            } else if (i->name == "lettuce" || i->name == "tomato") {
                cost += 2;
            } else if (i->name == "cheese") {
                cost += 3;
            } else if (i->name == "patty") {
                cost += 4;
            }
        }
        burger->clear(); 
        return cost;
    } else if (nextClient != nullptr) {
        return nextClient->serve(burger);
    }
    burger->clear(); 
    return 0;
}