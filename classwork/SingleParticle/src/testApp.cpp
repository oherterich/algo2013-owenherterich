#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofSetVerticalSync(true);
    ofSetFrameRate(60);
    ofBackground(0);
    
    for (int i = 0; i < 100; i ++) {
        addParticle();
    }
    
}

void testApp::addParticle() {
    Particle tmp;
    
    float vx = ofRandom(-4, 4);
    float vy = ofRandom(-4, 4);
    
    tmp.setParams(300, 300, vx, vy);
    
    particleList.push_back( tmp );
}

//--------------------------------------------------------------
void testApp::update(){
    
    for ( int i=0; i < particleList.size(); i++ ) {
        particleList[i].resetForces();
        //particleList[i].addForce( ofVec2f(0, 0.1) );
        particleList[i].addDampingForce();
        particleList[i].update();
    }
}

//--------------------------------------------------------------
void testApp::draw(){
    for ( int i=0; i < particleList.size(); i++ ) {
        particleList[i].draw();
    }
    
    ofBeginShape();
    for(int i = 0; i < particleList.size(); i++) {
        ofVertex(particleList[i].pos.x, particleList[i].pos.y);
    }
    ofEndShape();
    
//    C++ 11 syntax for iterating
//    or( auto p : particleList ) {
//        p.draw();
//    }
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
    for (int i = 0; i < 100; i ++) {
        float circVal = ofRandom(0, TWO_PI);
        
        float vx = cos( circVal ) * ofRandom( 4.0 );
        float vy = sin( circVal ) * ofRandom( 4.0 );
        
        particleList[i].setParams(x, y, vx, vy);
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