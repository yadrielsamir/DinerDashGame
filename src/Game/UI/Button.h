#include "ofMain.h"

class Button {
    
    public:
        Button();
        Button(int, int, int, int, string, int);
        void mousePressed(int x, int y);
        void tick();
        void render();
        bool wasPressed();
        void reset();

    private:
        int xPos, yPos, width, height, font;
        ofImage buttonImage;
        ofImage clickedButtonImage;
        bool pressed = false;
        int pressedCounter = -1;
        string buttonText;
        ofTrueTypeFont fonts;

};