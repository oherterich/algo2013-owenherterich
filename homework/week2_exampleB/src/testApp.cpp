#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    
    ofSetVerticalSync(true);
    ofSetBackgroundAuto(false);
    
    ofBackground( 255 );
    
    for (int i = 0; i < NUM_RECTS; i++) {
        Rectangle tmpRect;
        myRectangle.push_back( tmpRect );
    }    
}

//--------------------------------------------------------------
void testApp::update(){
    for (int i = 0; i < myRectangle.size(); i++) {
        myRectangle[i].update();
        
        if (i == 0) {
        myRectangle[i].xenoToPoint(mouseX, mouseY);
        }
        else {
        myRectangle[i].xenoToPoint(myRectangle[i-1].pos.x, myRectangle[i-1].pos.y);
        }
    }
}

//--------------------------------------------------------------
void testApp::draw(){
    ofEnableAlphaBlending();
    ofSetRectMode(OF_RECTMODE_CORNER);
    ofColor transparent(10, 255 * 0.1);
    ofSetColor( transparent );
    ofRect(0,0,ofGetWindowWidth(), ofGetWindowHeight());
    
    for (int i = 0; i < myRectangle.size(); i++) {
        myRectangle[i].c = ofMap(myRectangle[i].pos.y, 0, ofGetWindowHeight(), 0, 235);
        myRectangle[i].size = 40 - 40/myRectangle.size() * i;
        myRectangle[i].draw();
    }
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
    Rectangle tmpRect;
    myRectangle.push_back( tmpRect );
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
