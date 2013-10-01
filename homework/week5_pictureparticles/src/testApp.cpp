#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofSetVerticalSync( true );
    ofBackground( 255 );
    
    dandelion.loadImage( "dandelion.gif" );
    
    int numStalks = ofRandom(5, 10);
    
    for (int i = 0; i < numStalks; i++) {
        float randX = ofRandom(ofGetWindowWidth());
        float randY = ofRandom(ofGetWindowHeight() / 2, ofGetWindowHeight());
        
        stalk.push_back( ofVec2f(randX, randY) );
        
        for (int j = 0; j < 100; j++) {
            createParticle( ofVec2f(randX, randY) );
        }
    }
}

//--------------------------------------------------------------
void testApp::update(){
    for ( vector<Particle>::iterator it = pList.begin(); it != pList.end(); it++) {
        it->update( wind );
        
//        if ( it->kill() ) {
//            pList.erase( it );
//        }
//        else {
//            it++;
//        }
    }
    wind *= 0.3;
}

//--------------------------------------------------------------
void testApp::draw(){
    
    for (int i = 0; i < stalk.size(); i++) {
        ofSetColor(0);
        ofRect(stalk[i].x, stalk[i].y, 10, ofGetWindowHeight());
    }
    
    for ( vector<Particle>::iterator it = pList.begin(); it != pList.end(); it++ ) {
        it->draw();
    }
    
    ofSetColor(0);
    ofDrawBitmapString( "Click to create a breeze.", ofPoint(430, 20) );
}

void testApp::createParticle( ofVec2f mouse ) {
    Particle tmp( dandelion, mouse );
    pList.push_back( tmp );
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
    wind.x += ofRandom( -0.2, 0.2 );
    wind.y += ofRandom( -0.2, -.07 );
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
