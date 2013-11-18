#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofSetVerticalSync( true );
    ofBackground( 0 );
    
    k = 0.1;
    restLength = 200.0;
    
    anchor = ofVec2f(ofGetWindowWidth() / 2, 10);
    handle = ofVec2f(ofGetWindowWidth() / 2, 10 + restLength);
    
    bIsDragging = false;

}

//--------------------------------------------------------------
void testApp::update(){
    
    if (bIsDragging) {
        return;
    }
    
    ofVec2f force = handle - anchor;
    float length = force.length();
    float stretchLength = length - restLength;
    
    force.normalize();
    force *= -1 * k * stretchLength;
    
    applyForce( force );
    applyForce( ofVec2f( 0, 1.0 ) ); //gravity
    
    vel += acc;
    vel *= 0.95;
    handle += vel;
    
    acc.set(0);
}

//--------------------------------------------------------------
void testApp::draw(){
    
    ofLine( anchor, handle );

    ofCircle( anchor, 5 );
    ofCircle( handle, 25 );
    
}

void testApp::applyForce( ofVec2f force ){
    acc += force;
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
    if (bIsDragging) {
        handle.set( x, y );
    }
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
    
    if( ofVec2f(x, y).distance(handle) < 30) {
        handle.set( x, y );
        vel.set(0);
        bIsDragging = true;
    }
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){
    bIsDragging = false;
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
