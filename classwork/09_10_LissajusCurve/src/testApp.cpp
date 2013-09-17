#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofSetVerticalSync(true);
    ofBackground(0);
    ofEnableSmoothing();
}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){
    float angle = ofGetElapsedTimef() * 3.5;
    float radius = 200;
    
    float x = radius * cos( angle * 3.4);
    float y = radius * sin( angle * 4.7);
    
    ofPoint pos;
    pos.x = x;
    pos.y = y;
    
    pointList.push_back(pos);
    
    if (pointList.size() > 500) {
        pointList.erase(pointList.begin());
    }
    
    ofPushMatrix();{
        
        ofTranslate(ofGetWindowSize() / 2);
        
        
        ofNoFill();
        ofSetColor(170, 150, 0);
        
        ofBeginShape();
        for ( int i = 0; i < pointList.size(); i++ ) {
            ofVertex(pointList[i]);
        }
        ofEndShape();
        
    }ofPopMatrix();
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

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}