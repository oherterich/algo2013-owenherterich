#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofSetVerticalSync( true );
    ofBackground( 0 );
    
    mReceiver.setup(12345);
    mSender.setup("localhost",12345);
    
    ampMod = 1.0;
    outerSize = 7.0;
    innerSize = 5.0;
    rate = 1.0;
    outerColor = ofColor(70,175,240);
    innerColor = ofColor(200,230,255);
    
    numCircles = 60;
    
    for ( int i = 0; i < numCircles; i++ ) {
        Circle c;
        
        float x = cos( ofDegToRad( i * (360 / numCircles) ) ) * 200;
        float y = sin( ofDegToRad( i * (360 / numCircles) ) ) * 200;
        
        c.pos.x = x;
        c.pos.y = y;
        c.innerSize = 4;
        c.outerSize = 6;
        c.innerColor = ofColor(255);
        c.outerColor = ofColor(255,0,0);
        
        circleList.push_back( c );
    }

}

//--------------------------------------------------------------
void testApp::update(){
    getMsg();
    
    for (int i = 0; i < circleList.size(); i++) {
        
        float angle = sin(ofGetElapsedTimef() + (i * numCircles/20) );
        float newAmp = ofMap(angle, -1, 1, 40, 200);
        
        circleList[i].pos.x = cos( ofDegToRad( i * (360 / numCircles) ) * rate ) * newAmp * ampMod;
        circleList[i].pos.y = sin( ofDegToRad( i * (360 / numCircles) ) * rate ) * newAmp * ampMod;
        
        circleList[i].outerSize = outerSize;
        circleList[i].innerSize = innerSize;
        circleList[i].outerColor = outerColor;
        circleList[i].innerColor = innerColor;
    }
}

//--------------------------------------------------------------
void testApp::draw(){

    for (int i = 0; i < circleList.size(); i++) {
        circleList[i].draw();
    }
    
}

void testApp::getMsg(){
    while ( mReceiver.hasWaitingMessages() ){
        ofxOscMessage m;
        mReceiver.getNextMessage( &m );
        string addr = m.getAddress();
        
        if ( addr == "/outer_amplitude" ) {
            float a = m.getArgAsFloat(0);
            ampMod = a;
        }
        
        else if ( addr == "/outer_size" ) {
            float s = m.getArgAsFloat(0);
            outerSize = s;
        }
        
        else if ( addr == "/inner_size" ) {
            float s = m.getArgAsFloat(0);
            innerSize = s;
        }
        
        else if ( addr == "/outer_color" ) {
            float r = m.getArgAsInt32(0);
            float g = m.getArgAsInt32(1);
            float b = m.getArgAsInt32(2);
            outerColor = ofColor(r, g, b);
        }
        
        else if ( addr == "/inner_color" ) {
            float r = m.getArgAsInt32(0);
            float g = m.getArgAsInt32(1);
            float b = m.getArgAsInt32(2);
            innerColor = ofColor(r, g, b);
        }
        
        else if ( addr == "/rate" ) {
            float r = m.getArgAsFloat(0);
            rate = r;
        }
    }
}

void testApp::sendMsg(){

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
