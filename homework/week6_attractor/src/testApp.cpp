#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofSetVerticalSync( true );
    ofBackground( 10 );
    ofSetBackgroundAuto( false );
    ofEnableAlphaBlending();
    
    for (int i = 0; i < 10000; i++) {
        addParticle();
    }
    
    for (int i = 0; i < 5; i++) {
        Mover tmp;
        moverList.push_back( tmp );
    }
    
    attract = false;
}

//--------------------------------------------------------------
void testApp::update(){
    for (vector<Particle>::iterator it = particleList.begin(); it != particleList.end(); it++) {
        
        if (attract) {
            for (int i = 0; i < moverList.size(); i++) {
                it->attractForce(moverList[i].pos.x, moverList[i].pos.y, moverList[i].rAttract, moverList[i].sAttract);
                it->repulseForce(moverList[i].pos.x, moverList[i].pos.y, moverList[i].rRepulse, moverList[i].sRepulse);
            }
        }

        it->update();
    }
    
    for (int i = 0; i < moverList.size(); i++) {
        moverList[i].update();
    }
}

//--------------------------------------------------------------
void testApp::draw(){
    ofSetRectMode( OF_RECTMODE_CORNER );
    ofSetColor( 10, 50 );
    ofRect( 0, 0, ofGetWindowWidth(), ofGetWindowHeight() );
    
    ofSetRectMode( OF_RECTMODE_CENTER );
    for (vector<Particle>::iterator it = particleList.begin(); it != particleList.end(); it++) {
        it->draw();
    }
}

void testApp::addParticle() {
    Particle tmp;
    particleList.push_back( tmp );
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    if (key == 'A' || key == 'a') {
        attract = !attract;
    }
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
    for (int i = 0; i < moverList.size(); i++) {
        moverList[i].switchForces();
    }
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
