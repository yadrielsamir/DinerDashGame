#include "WinState.h"
WinState::WinState() {
}

void WinState::tick() {
	render();
}
void WinState::render() {
	ofSetBackgroundColor(255, 40, 35);
	ofDrawBitmapString("YOU WIN", ofGetWidth()/2 - 30, ofGetHeight()/2);
	ofDrawBitmapString("YOU MADE $100 OR MORE", ofGetWidth()/2 - 70, ofGetHeight()/2 + 100);
}

void WinState::keyPressed(int key){
	
}

void WinState::mousePressed(int x, int y, int button){
}

void WinState::reset(){
	setFinished(false);
	setNextState(" ");
}