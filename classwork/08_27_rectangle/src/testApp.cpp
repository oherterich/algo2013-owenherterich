#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    
    ofSetVerticalSync(true);

    myRectangle.pos.x = ofGetWindowWidth() / 2;
    myRectangle.pos.y = ofGetWindowHeight() / 2;
    
    myRectangle.posA.x = 10;
    myRectangle.posA.y = 100;
    
    myRectangle.posB.x = 600;
    myRectangle.posB.y = 400;
    
    myRectangle.interpolateByPct(0.0f);
    
    pct = 0;
    
}

//--------------------------------------------------------------
void testApp::update(){
//    pct += 0.01f;
//    
//    if (pct > 1) {
//        pct = 0;
//    }
//    
//    myRectangle.interpolateByPct(pct);
    
//    myRectangle.interpolateByPct(pct);
    
    myRectangle.xenoToPoint(mouseX, mouseY);

}

//--------------------------------------------------------------
void testApp::draw(){
    myRectangle.draw();
    
    ofSetColor(255);
    ofDrawBitmapString(ofToString(pct), ofPoint(10,10));
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){
//    pct = (float) y / (float) ofGetWindowHeight();    
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
