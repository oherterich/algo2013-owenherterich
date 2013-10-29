#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofSetVerticalSync( true );
    ofBackground(22,25,58);
    ofSetRectMode(OF_RECTMODE_CENTER);
    
    for (int i = 0; i < 12; i++) {
        anim[i].loadImage("ball_" + ofToString(i) + ".png");
    }
    
    for (int i = 0; i < 30; i++) {
        Ball tmp(anim);
        tmp.c = ofColor(186,160,49);
        ballList.push_back( tmp );
    }
}

//--------------------------------------------------------------
void testApp::update(){
    for (int i = 0; i < ballList.size(); i++) {
        ballList[i].addBoundaries();
        ballList[i].addForce( ofVec2f(0.0, 0.97) ); //gravity
        ballList[i].update();
    }
}

//--------------------------------------------------------------
void testApp::draw(){
    ofColor b;
    b.setHsb(160 + sin(ofGetElapsedTimef() * 0.2) * 20, 170, 50);
    ofSetColor(b);
    ofBackground( b );
    
    for (int i = 0; i < ballList.size(); i++) {
        ballList[i].draw();
    }
    
    ofSetColor(186,160,49);
    ofDrawBitmapString("Click to reset balls", ofPoint(ofGetWindowWidth() / 2 - 60, 20));
}

void testApp::addBall() {
    Ball tmp(anim);
    tmp.c = ofColor(186,160,49);
    ballList.push_back( tmp );
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
    for (int i = 0; i < ballList.size(); i++) {
        ballList[i].pos = ofVec2f(ofRandomWidth(), ofRandomHeight());
        ballList[i].vel = ofVec2f(ofRandom(-10, 10), ofRandom(-5, 5));
    }
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}
