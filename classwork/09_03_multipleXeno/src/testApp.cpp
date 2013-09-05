#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofSetBackgroundAuto(false);
    ofEnableAlphaBlending();
    
    for ( int i = 0; i < 40; i++ ) {
        Rectangle tmpRect;
        rectList.push_back( tmpRect );
    }
}

//--------------------------------------------------------------
void testApp::update(){
    for ( int i = 0; i < rectList.size(); i++ ) {
        
        rectList[i].size = rectList.size()-i;
        
        if ( i == 0 ) {
            rectList[i].xenoToPoint(mousePos.x, mousePos.y);
        }
        else {
            rectList[i].xenoToPoint(rectList[i-1].pos.x, rectList[i-1].pos.y);
        }
    }
}

//--------------------------------------------------------------
void testApp::draw(){
    ofColor semiTransparent(100, 100, 100, 255.0 * 0.1);
    
    ofSetRectMode( OF_RECTMODE_CORNER);
    ofSetColor( semiTransparent);
    ofRect(0, 0, ofGetWindowWidth(), ofGetWindowHeight());
    
    for ( int i = 0; i < rectList.size(); i++ ) {
        rectList[i].draw();
    }
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y){
    mousePos.x = x;
    mousePos.y = y;
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