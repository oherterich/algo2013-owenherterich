#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofSetVerticalSync( true );
    ofBackground( 0 );
    
    mReceiver.setup(12346);
    mSender.setup("localhost", 12347);
    
    ofSetWindowPosition(0, 790/2);
}

//--------------------------------------------------------------
void testApp::update(){
    getMsg();
    sendMsg();
}

//--------------------------------------------------------------
void testApp::draw(){
    ofSetWindowTitle("3");
    
    ofPushMatrix();{
        ofTranslate(0, -ofGetWindowHeight());
        ofColor c;
        c.setHsb(hue, 255, 255);
        ofSetColor(c);
        ofCircle(pos, size);
    }ofPopMatrix();
}

void testApp::getMsg(){
    while( mReceiver.hasWaitingMessages() ) {
        ofxOscMessage m;
        mReceiver.getNextMessage( &m );
        string addr = m.getAddress();
        
        if(addr == "/ball/pos") {
            float x = m.getArgAsFloat(0);
            float y = m.getArgAsFloat(1);
            pos.set(x, y);
        }
        
        else if(addr == "/ball/size") {
            float s = m.getArgAsFloat(0);
            size = s;
        }
        
        else if (addr == "/ball/hue") {
            int h = m.getArgAsFloat(0);
            hue = h;
        }
    }
}

void testApp::sendMsg(){
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
