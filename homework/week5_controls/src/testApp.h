#pragma once

#include "ofMain.h"
#include "ofxUI.h"

#include "Particle.h"
#include "InitParticle.h"
#include "Background.h"

class testApp : public ofBaseApp{
	public:
		void setup();
        void exit();
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
    
    void createParticle(ofVec2f pos, float velMult, ofColor c, float size);
    void onGuiEvent( ofxUIEventArgs &e );

    
    vector <Particle> particles;
    vector <InitParticle> single;
    Background myBackground;
    
    ofxUICanvas *gui;
    
    float particleSize;
    float particleSpeedLow, particleSpeedHigh;
    float particleRate;
    float r, g, b;
    float trailAmount;
    float explosionSize;
    
    bool start;
    bool randomColor;
    
    ofColor hue;

    
    

};
