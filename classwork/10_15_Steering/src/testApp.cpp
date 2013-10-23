#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofSetVerticalSync( true );
    ofBackground( 0 );
    
    dest.set( ofRandomWidth(), ofRandomHeight() );
    
    for (int i = 0; i < 1; i++) {
        addParticle();
    }
}

//--------------------------------------------------------------
void testApp::update(){
    for (int i = 0; i < particleList.size(); i++) {
        
        if (particleList[i].pos.distance(dest) < 5 ) {
            dest.set( ofRandomWidth(), ofRandomHeight() );
        }
        
        particleList[i].seek( dest );
        particleList[i].update();
    }
    
}

//--------------------------------------------------------------
void testApp::draw(){
    for (int i = 0; i < particleList.size(); i++) {
        particleList[i].draw();
    }
    
    ofSetColor(255, 255, 0);
    ofCircle( dest, 5 );
}

void testApp::addParticle() {
    Particle p;
    p.pos = ofVec2f( ofRandomWidth(), ofRandomHeight() );
    p.vel = ofVec2f( ofRandom(-5, 5), ofRandom( -5, 5) );
    particleList.push_back( p );
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
