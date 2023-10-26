#pragma once

#include "State.h"
#include "restaurant.h"

class WinState : public State {
private:
public:
	WinState();
	void tick();
	void render();
	void keyPressed(int key);
	void mousePressed(int x, int y, int button);
	void reset();
};
