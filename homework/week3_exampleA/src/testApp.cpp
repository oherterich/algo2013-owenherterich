#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofSetVerticalSync(true);
    ofBackground(0);
    ofEnableSmoothing();
    
    for (int i = 0; i < 90; i++) {
        ofVec3f tmp;
        tmp.x = cos( ofDegToRad(i * 4));
        tmp.y = sin( ofDegToRad(i * 4));
        
        float amp = 250;
        
        Circle tmpCircle;
        tmpCircle.setup(tmp, amp);
        
        myCircles.push_back( tmpCircle );
    }
    
}

//--------------------------------------------------------------
void testApp::update(){
    myBackground.update();
        
        for (int i = 0; i < myCircles.size(); i++) {
            myCircles[i].update();
        }
    
    myRose.update();
}

//--------------------------------------------------------------
void testApp::draw(){
    myBackground.draw();
    
    for (int i = 0; i < myCircles.size(); i++) {
        myCircles[i].draw();
    }
    
    myRose.draw();

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