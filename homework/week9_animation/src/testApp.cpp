#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofSetVerticalSync( true );
    ofBackground( 45 );
    ofSetCircleResolution(100);
    
    pallette[0] = ofColor(123,179,142);
    pallette[1] = ofColor(244,241,215);
    pallette[2] = ofColor(248,171,101);
    pallette[3] = ofColor(241,92,76);
    
    for (int i = 0; i < 4; i++) {
        Circle tmp(ofRandom(100, 250), i * PI/5);
        tmp.c = pallette[(int)ofRandom(4)];
        circles.push_back( tmp );
    }
}

//--------------------------------------------------------------
void testApp::update(){
    for (int i = 0; i < circles.size(); i++) {
        if (circles[i].changeColor()) {
            circles[i].c = pallette[(int)ofRandom(4)];
        }
        circles[i].update();
    }
}

//--------------------------------------------------------------
void testApp::draw(){
    for (int i = 0; i < circles.size(); i++) {
        circles[i].draw();
    }
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
