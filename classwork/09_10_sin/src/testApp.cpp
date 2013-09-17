#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofSetVerticalSync(true);
    ofBackground(0);
    ofSetCircleResolution(100);
    
    amplitudeX = ofGetWindowWidth() / 2;
    amplitudeY = ofGetWindowHeight() / 2;
    period = 5000.0;
}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){
    
    ofPoint pos;
    pos.x = amplitudeX * sin( (ofGetElapsedTimeMillis() / period) * TWO_PI );
    pos.y = amplitudeY * cos( (ofGetElapsedTimeMillis() / period) * TWO_PI );
    
    ofPushMatrix();{
        ofTranslate( ofGetWindowSize() / 2 );
        ofCircle(pos, breathingCircle());
    }ofPopMatrix();
}

//--------------------------------------------------------------
float testApp::breathingCircle(){
    float sinOfTime =  sin( ofGetElapsedTimef() * 2 );
    float sinMapped = ofMap( sinOfTime, -1.0, 1.0, 10.0, 25.0 );
    return sinMapped;
    
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

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){
    amplitudeX = w / 2.0;
    amplitudeY = h / 2.0;
}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}