#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    
    ofSetVerticalSync(true);
    ofEnableAlphaBlending();
    ofBackground(0);
    
    boxRadius = 200.0;
    ballPos = ofPoint( 0.0, 0.0, 0.0 );
    ballVel = ofVec3f( ofRandomuf(), ofRandomf(), ofRandomf() );
    ballVel *= 5.0;
    
    mBox = ofBoxPrimitive( boxRadius * 2, boxRadius * 2, boxRadius * 2 );
}

//--------------------------------------------------------------
void testApp::update(){
    ballPos += ballVel;
    
    if( ballPos.x > boxRadius || ballPos.x < -boxRadius ) {
        ballVel.x *= -1;
    }
    
    if( ballPos.y > boxRadius || ballPos.y < -boxRadius ) {
        ballVel.y *= -1;
    }
    
    if( ballPos.z > boxRadius || ballPos.z < -boxRadius ) {
        ballVel.z *= -1;
    }
    
}

//--------------------------------------------------------------
void testApp::draw(){
    ofPushMatrix();{
        ofSetColor( 255, 255, 255, 255 );
        
        ofTranslate( ofGetWindowSize() / 2 );
        ofDrawSphere( ballPos, 20 );
        
        ofSetColor( 255, 255, 255, 255 * 0.2 );
        mBox.getMesh().drawWireframe();
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