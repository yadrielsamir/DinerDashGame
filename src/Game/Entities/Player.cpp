#include "Player.h"

Player::Player(int x, int y, int width, int height, ofImage sprite, EntityManager* em) : Entity(x, y, width, height, sprite){

    vector<ofImage> chefAnimframes;
    ofImage temp;
    this->burger = new Burger(ofGetWidth()-110, 100, 100, 50);
    temp.cropFrom(sprite, 30,3,66,120);
    chefAnimframes.push_back(temp);
    temp.cropFrom(sprite, 159,3,66,120);
    chefAnimframes.push_back(temp);
    temp.cropFrom(sprite, 287, 3,67,120);
    chefAnimframes.push_back(temp);
    temp.cropFrom(sprite, 31,129,66,120);
    chefAnimframes.push_back(temp);
    this->chefAnim = new Animation(50, chefAnimframes);
    this->entityManager = em;
    
}
void Player::tick(){
    chefAnim->tick();
    if(ofGetKeyPressed(OF_KEY_LEFT) && x > 0){ 
        facing = "left";
        x-=speed;
    }else if(ofGetKeyPressed(OF_KEY_RIGHT) && x < ofGetWidth() - width){ 
        facing = "right";
        x+=speed;
    }
    if(x <= 0){
        facing = "right";
    }else if(x + width >= ofGetWidth()){
        facing = "left";
    }
}

void Player::render(){
    BaseCounter *ac = getActiveCounter();
    StoveCounter *asc = getActiveStoveCounter();
    if (ac != nullptr) {
        ac->showItem();
    }
    else if (asc != nullptr){
        if(cooked){
            ofSetColor(100, 35, 0);
        }
        else if (cooking){
            ofSetColor(145 , 55, 0);
        }
        asc->showItem();
    }
    ofSetColor(256, 256, 256);
    ofImage currentFrame = chefAnim->getCurrentFrame();
    if (facing == "left") {
        currentFrame.mirror(false, true);
    }
    currentFrame.draw(x, y, width, height);
    burger->render();
}

void Player::keyPressed(int key){
    if(key == 'e'){
        BaseCounter* ac = getActiveCounter();
        StoveCounter* asc = getActiveStoveCounter();
        if(ac != nullptr){
            Item* item = ac->getItem();
            if(item != nullptr){
                burger->addIngredient(item);
                ingredientAdded = true;
            }    
        } else if (asc != nullptr){
            Item* item = asc->getItem();
            if(item != nullptr && cooked){
                burger->addIngredient(item);
                ingredientAdded = true;
                cooked = false;
            } else if (item != nullptr && !cooking){
                cooking = true;
            }
        }
    } 
    if(key == 'u'){
        burger->removeIngredient();
    }

}

BaseCounter* Player::getActiveCounter(){
    for(Entity* e:entityManager->entities){
        BaseCounter* c = dynamic_cast<BaseCounter*>(e);
        if(dynamic_cast<StoveCounter*>(c)){
            continue;
        }
        if(x + e->getWidth()/2 >= e->getX() && x +e->getWidth()/2 <e->getX() + e->getWidth()){
            return c;
        }
    }
    return nullptr;
}

StoveCounter* Player::getActiveStoveCounter(){
    for(Entity* e:entityManager->entities){
        StoveCounter* c = dynamic_cast<StoveCounter*>(e);
        if(x + e->getWidth()/2 >= e->getX() && x +e->getWidth()/2 <e->getX() + e->getWidth()){
            return c;
        }
    }
    return nullptr;
}

void Player::keyReleased(int key) {
}
void Player::mousePressed(int x, int y, int button) {
}

void Player::setFacing(string facing){ this->facing = facing; }