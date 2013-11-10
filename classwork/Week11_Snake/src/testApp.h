#pragma once

#include "ofMain.h"
#include "ofxOsc.h"

class testApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
    void snakeCollision();
    
    void sendOsc();
    void receiveOsc();
    
    ofxOscSender    mSender;
    ofxOscReceiver mReceiver;
    
    vector<ofVec2f> snake;
    ofVec2f         pos, vel;
    int             snakeLength, snakeSize;
    ofColor         c;
    
    void addOb( ofVec2f pos );
    vector<ofVec2f> obList;
    
    int state;
    
    ofImage end;
};
