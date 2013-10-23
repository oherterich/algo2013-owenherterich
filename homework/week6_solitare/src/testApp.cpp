#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofSetVerticalSync( true );
    ofBackground( 0 );
    
    for (int i = 1; i < 53; i++) {
        ofImage tmp;
        tmp.loadImage("cards/" + ofToString(i) + ".png");
        cardImages.push_back( tmp );
    }
    
    ofVec2f pos;
    pos.set(ofRandomWidth(), ofRandomHeight() / 2);
    ofVec2f vel;
    vel.set(ofRandom(-5.0, 5.0), ofRandom(-4.0, 4.0));
    addCard( pos, vel, 1.1 );
}

//--------------------------------------------------------------
void testApp::update(){
    
    for (int i = 0; i < cards.size(); i++) {
        ofVec2f grav;
        grav.set(0, 0.2);
        cards[i].addForce( grav );
        cards[i].dampingForce();
        cards[i].update();
        
        if (cards[i].kill) {
            for (int i = 0; i < 4; i++) {
                addCard(cards[i].pos, ofVec2f(ofRandom(-5.0, 5.0), ofRandom(-15.0, -10.0)), cards[i].scaleFactor);
            }
            cards.erase(cards.begin() + i);
        }
        
        if (cards.size() > 800) {
            cards.erase(cards.begin());
        }
    }
    

        int time = ofGetElapsedTimef() / 5;
        for (int i = 0; i < time; i++) {
            ofPoint tmp;
            tmp.x = ofRandomWidth();
            tmp.y = ofRandomHeight();
            pixels.push_back( tmp );\
        }
    
}

//--------------------------------------------------------------
void testApp::draw(){
    

    
    for (vector<Card>::iterator it = cards.begin(); it != cards.end(); it++) {
        it->draw();
    }
    
    for (int i = 0; i < pixels.size(); i++) {
        ofSetColor(255);
        ofRect(pixels[i], 3, 3);
    }
    
}

void testApp::addCard( ofVec2f pos, ofVec2f vel, float scale ) {
    int rand = ofRandom(0, cardImages.size());
    Card tmp(&cardImages[rand], pos, vel);
    tmp.scaleFactor = scale * 0.9;
    cards.push_back( tmp );
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
