#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofSetVerticalSync( true );
    ofBackground( 0 );
    
    ofSetRectMode(OF_RECTMODE_CENTER);
    
    for (int i = 0; i < 11; i++) {
        cars[i].loadImage("car" + ofToString(i) + ".png");
    }
    background.loadImage("background.png");
    
    for (int i = 0; i < 10; i++) {
        addParticle();
    }
}

//--------------------------------------------------------------
void testApp::update(){
    for (vector<Particle>::iterator i1 = particleList.begin(); i1 != particleList.end(); ++i1) {
        
        vector<Particle>::iterator i2 = i1 + 1;
        
        for (i2; i2 != particleList.end(); ++i2) {
            
            if (i1->pos.distance(i2->pos) < 100.0) {
                i2->addRepulsion(i1->pos);
                i1->addRepulsion(i2->pos);
            }
        }
        
        if (i1->pos.distance(i1->dest) < 5 ) {
            i1->dest.set( ofRandomWidth(), ofRandomHeight() );
        }
        
        i1->seek();
        i1->update();
    }
    
}

//--------------------------------------------------------------
void testApp::draw(){
    ofSetColor(255);
    ofPushMatrix();
    ofTranslate(ofGetWindowWidth() / 2, ofGetWindowHeight() /2);
    background.draw(0,0);
    ofPopMatrix();
    
    for (int i = 0; i < particleList.size(); i++) {
        particleList[i].draw();
    }
}

void testApp::addParticle() {
    int rand = (int)ofRandom(11);
    Particle p( &cars[rand]);
    p.pos = ofVec2f( ofRandomWidth(), ofRandomHeight() );
    p.vel = ofVec2f( ofRandom(-5, 5), ofRandom( -5, 5) );
    p.dest = ofVec2f( ofRandomWidth(), ofRandomHeight() );
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
