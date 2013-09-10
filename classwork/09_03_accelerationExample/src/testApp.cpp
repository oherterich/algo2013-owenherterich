#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofSetVerticalSync(true);
    ofSetBackgroundAuto(false);
    
    Mover tmpMover;
    myMover.push_back( tmpMover );
}

//--------------------------------------------------------------
void testApp::update(){
    myMover[0].mousePos.x = mouseX;
    myMover[0].mousePos.y = mouseY;
    myMover[0].leader = true;
    
    for (int i = 0; i < myMover.size(); i++) {
        myMover[i].update();
        myMover[i].wallCollision();
        
        if (myMover[i].leader == false) {
            myMover[i].xenoToPoint( myMover[i-1].pos);
        }
    }
}

//--------------------------------------------------------------
void testApp::draw(){
    ofEnableAlphaBlending();
    ofSetColor(0, 0, 0, 100);
    ofRect(ofGetWindowWidth() / 2, ofGetWindowHeight() / 2, ofGetWindowWidth(), ofGetWindowHeight());
    for (int i = 0; i < myMover.size(); i++) {
        ofColor c = 255 - i * (255/myMover.size());
        myMover[i].draw( c );
        myMover[i].r = 25 - i * (25/myMover.size());
    }
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    if (key == 'a') {
        Mover tmpMover;
        myMover.push_back( tmpMover );
    }
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
    myMover[0].dragged = true;
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){
    myMover[0].dragged = false;
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