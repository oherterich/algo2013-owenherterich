#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofSetVerticalSync( true );
    ofBackground( 0 );
    
    mReceiver.setup(12347);
    
    ofSetWindowPosition(1024/2, 790/2);

}

//--------------------------------------------------------------
void testApp::update(){
    getMsg();
}

//--------------------------------------------------------------
void testApp::draw(){
    ofSetWindowTitle("4");
    
    ofPushMatrix();{
        ofTranslate(-ofGetWindowWidth(), -ofGetWindowHeight());
        ofColor c;
        c.setHsb(hue, 255, 255);
        ofSetColor(c);
        ofCircle(pos, size);
    }ofPopMatrix();
}

void testApp::getMsg(){
    while( mReceiver.hasWaitingMessages() ){
        ofxOscMessage m;
        mReceiver.getNextMessage( &m );
        string addr = m.getAddress();
        
        if( addr == "/ball/pos") {
            float x = m.getArgAsFloat(0);
            float y = m.getArgAsFloat(1);
            
            pos.set(x, y);
        }
        
        else if( addr == "/ball/size") {
            float s = m.getArgAsFloat(0);
            size = s;
        }
        
        else if (addr == "/ball/hue") {
            int h = m.getArgAsFloat(0);
            hue = h;
        }
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
