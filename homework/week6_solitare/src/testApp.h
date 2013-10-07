#pragma once

#include "ofMain.h"
#include "Card.h"

class testApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
        void addCard( ofVec2f pos, ofVec2f vel, float scale );

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		
    vector<ofImage> cardImages;
    vector<Card> cards;
    vector<ofPoint> pixels;
    
};
