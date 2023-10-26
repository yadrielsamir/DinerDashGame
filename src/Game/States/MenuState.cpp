#include "MenuState.h"

MenuState::MenuState() {
	string text = "Start";
	startButton = new Button(ofGetWidth()/2 - text.length()*20, ofGetHeight()/2 - text.length()*8, 64, 50, text, 30);
	string titleText = "Dinner Dash";
    title = new Button(ofGetWidth()/2 - text.length()*50, ofGetHeight()/2 - text.length()*35, 64, 50, titleText, 72);
}

void MenuState::tick() {
	startButton->tick();
	if(startButton->wasPressed()){
		setNextState("Game");
		setFinished(true);
	}
}
void MenuState::render() {
	string text = "Start";
	ofSetBackgroundColor(255, 40, 35);
	startButton->render();
	title->render();
	fonts.load("TechnoRaceItalic-eZRWe.otf", 15);
    fonts.drawString("Press 'e' to pickup ingredients", ofGetWidth()/2 - text.length()*25, ofGetHeight()/2 + text.length()*25);
    fonts.drawString("Press 's' to serve clients", ofGetWidth()/2 - text.length()*22, ofGetHeight()/2 + text.length()*30);
	fonts.drawString("Press 'u' to remove the last added ingredient", ofGetWidth()/2 - text.length()*35, ofGetHeight()/2 + text.length()*20);
	fonts.drawString("Press right arrow key to move right", ofGetWidth()/2 - text.length()*31, ofGetHeight()/2 + text.length()*35);
	fonts.drawString("Press left arrow key to move left", ofGetWidth()/2 - text.length()*30, ofGetHeight()/2 + text.length()*40);
}

void MenuState::keyPressed(int key){
	
}

void MenuState::mousePressed(int x, int y, int button){
	startButton->mousePressed(x, y);
}

void MenuState::reset(){
	setFinished(false);
	setNextState("");
	startButton->reset();
}