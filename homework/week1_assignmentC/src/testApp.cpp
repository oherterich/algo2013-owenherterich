#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofEnableSmoothing();
    
    myLine.p1.x = ofRandom(ofGetWindowWidth());
    myLine.p1.y = ofRandom(ofGetWindowHeight());
    myLine.p2.x = ofRandom(ofGetWindowWidth());
    myLine.p2.y = ofRandom(ofGetWindowHeight());
    
    myLine.c1.x = ofRandom(ofGetWindowWidth());
    myLine.c1.y = ofRandom(ofGetWindowHeight());
    myLine.c2.x = ofRandom(ofGetWindowWidth());
    myLine.c2.y = ofRandom(ofGetWindowHeight());
    
    
    myLine.whichPoint = false;
}

//--------------------------------------------------------------
void testApp::update(){
    myLine.update();
}

//--------------------------------------------------------------
void testApp::draw(){
    ofBackground(10);
    myLine.draw();
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
    if (myLine.whichPoint) {
        myLine.p1.x = x;
        myLine.p1.y = y;
        myLine.whichPoint = !myLine.whichPoint;
    }
    else {
        myLine.p2.x = x;
        myLine.p2.y = y;
        myLine.whichPoint = !myLine.whichPoint;
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