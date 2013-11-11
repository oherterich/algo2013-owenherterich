#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofSetVerticalSync( true );
    ofBackground( 0 );
    
    mSender.setup("localhost", 12345);
    
    pos.set(ofRandomWidth() * 2, ofRandomHeight() * 2);
    vel.set(ofRandom(3, 7), ofRandom(3, 7));
    size = 25;
    
    ofSetWindowPosition(0, 0);
}

//--------------------------------------------------------------
void testApp::update(){
    
    if( pos.x < size / 2) {
        vel.x *= -1;
        pos.x = size / 2;
    }
    
    if( pos.x > ofGetWindowWidth() * 2 - size / 2) {
        vel.x *= -1;
        pos.x = ofGetWindowWidth() * 2 - size / 2;
    }
    
    if( pos.y < size / 2) {
        vel.y *= -1;
        pos.y = size / 2;
    }
    
    if( pos.y > ofGetWindowHeight() * 2 - size / 2) {
        vel.y *= -1;
        pos.y = ofGetWindowHeight() * 2 - size / 2;
    }
    
    pos += vel;
    
    size = ofMap(sin(ofGetElapsedTimef()), -1, 1, 20, 40);
    
    hue = ofMap(pos.x, 0, ofGetWindowWidth() * 2, 0, 255);
    
    sendMsg();
    
}

//--------------------------------------------------------------
void testApp::draw(){
    ofSetWindowTitle("1");
    
    ofColor c;
    c.setHsb(hue, 255, 255);
    ofSetColor(c);
    ofCircle(pos, size);
}

void testApp::sendMsg() {
    ofxOscMessage m;
    m.setAddress("/ball/pos");
    m.addFloatArg( pos.x );
    m.addFloatArg( pos.y );
    mSender.sendMessage( m );
    
    ofxOscMessage m2;
    m2.setAddress("/ball/size");
    m2.addFloatArg( size );
    mSender.sendMessage( m2 );
    
    ofxOscMessage m3;
    m3.setAddress("/ball/hue");
    m3.addFloatArg( hue );
    mSender.sendMessage( m3 );
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
