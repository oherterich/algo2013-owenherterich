#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofBackground(10,10,50);
    
    theta = 45;
    generation = 0;
    
}

//--------------------------------------------------------------
void testApp::update(){

}

void testApp::branch( float length ) {
    
    generation++;
    
    ofPushMatrix();{
        
        ofSetColor(170,170,30);
        ofLine(0,0, 0, -length);
        ofTranslate(0, -length);
        
        float noise = ofNoise( generation, ofGetElapsedTimef() * 0.1 );
        
        if (length > 3) {
            ofPushMatrix();{
                ofRotate(45 - theta + noise * 10.0 - 5.0);
                branch( length * 0.666666);
            }ofPopMatrix();
            
            ofPushMatrix();{
                ofRotate(45 + theta + noise * 10.0 - 5.0);
                branch( length * 0.666666);
            }ofPopMatrix();
        }
        
    }ofPopMatrix();
    
    generation--;
    
}

//--------------------------------------------------------------
void testApp::draw(){
    ofPushMatrix();{
        ofTranslate( ofGetWindowWidth() / 2, ofGetWindowHeight());
        branch ( 200 );
    }ofPopMatrix();
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){
    theta = ofMap(x, 0, ofGetWindowWidth(), -180, 180);
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
