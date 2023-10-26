#include "LoseState.h"
LoseState::LoseState() {
}

void LoseState::tick() {
	render();
}
void LoseState::render() {
	ofSetBackgroundColor(255, 40, 35);
	ofDrawBitmapString("YOU LOST", ofGetWidth()/2 - 30, ofGetHeight()/2);
	ofDrawBitmapString("YOU LET 10 PEOPLE GO!", ofGetWidth()/2 - 70, ofGetHeight()/2 + 100);
}

void LoseState::keyPressed(int key){
	
}

void LoseState::mousePressed(int x, int y, int button){
}

void LoseState::reset(){
	setFinished(false);
	setNextState(" ");
}