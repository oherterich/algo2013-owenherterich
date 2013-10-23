#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofSetVerticalSync( true );
    ofSetFrameRate( 60 );
    ofEnableDepthTest();
    ofBackground( 0 );
    
    cam.setDistance( 100 );
    
    flocker.addParticle(500);
}

//--------------------------------------------------------------
void testApp::update(){
    flocker.update();
}

//--------------------------------------------------------------
void testApp::draw(){
    ofSetWindowTitle( ofToString( ofGetFrameRate() ) );
    
    cam.begin();
    
    flocker.draw();
    
    cam.end();
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
