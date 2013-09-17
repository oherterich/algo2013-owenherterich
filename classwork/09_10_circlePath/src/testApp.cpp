#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofSetVerticalSync(true);
    ofBackground(0);
    ofEnableSmoothing();
    
    radius = 50.0;
}

//--------------------------------------------------------------
void testApp::update(){
    radius += 0.1;
}

//--------------------------------------------------------------
void testApp::draw(){
    
    float angle = ofGetElapsedTimef() * 3.5;
    
    float x = radius * cos( angle );
    float y = radius * sin( angle );
    
    ofPoint pos;
    pos.x = x;
    pos.y = y;
    pointList.push_back( pos );
    
    if ( pointList.size() > 1000 ) {
        pointList.erase( pointList.begin() );
    }
    
    ofPushMatrix(); {
        
        ofTranslate( ofGetWindowSize() / 2 );
        
        ofSetColor( 0, 255, 0 );
        ofFill();
        ofCircle( pos, 20 );
        
        ofSetColor(255);
        ofNoFill();
        ofBeginShape();
        
        for ( int i = 0; i < pointList.size(); i++ ) {
            ofVertex( pointList[i] );
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