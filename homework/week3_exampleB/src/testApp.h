#pragma once

#include "ofMain.h"

#include "Circle.h"
#include "Rectangle.h"

class testApp : public ofBaseApp{
	public:
		void setup();
		void update();
		void draw();
		
		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y);
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
    void background();
    void line1Draw();
    void line2Draw();
    void rectangleTimer();
    
    ofSoundPlayer song;
    
    float hue;
    float amp;
        
    vector <ofPoint> line1;
    vector <ofPoint> line2;
    vector <Circle> myCircles;
    vector <Rectangle> myRectangles;

};
