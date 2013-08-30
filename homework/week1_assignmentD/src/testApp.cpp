#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    
    ofSetVerticalSync(true);
    ofSetCircleResolution(10);
    
    for (int i = 0; i < NUM_THINGS; i++) {
        myThing[i].interpolateByPct(0.0f, 0.0f);
    }
    
    pct = 0;
    rad = 0;
    
}

//--------------------------------------------------------------
void testApp::update(){
    for (int i = 0; i < NUM_THINGS; i++) {
        myThing[i].pctGrow += myThing[i].pctAdd;
        
        if (myThing[i].pctGrow > 1.0f) {
            myThing[i].pctGrow = 0.0f;
            
            float randomStart = ofRandom(ofGetWindowWidth());
            myThing[i].posA.x = randomStart;
            myThing[i].posB.x = randomStart;
            
            myThing[i].size = myThing[i].initSize;
        }
    
        myThing[i].interpolateByPct(myThing[i].pctGrow, rad);
        myThing[i].horizontalMovement();
    }
    
    rad += 0.05;
    
    cout << myThing[0].cosPct << " " << myThing[0].trigger << endl;
}

//--------------------------------------------------------------
void testApp::draw(){
    ofBackground(10,10,30);
    for (int i = 0; i < NUM_THINGS; i++) {
        myThing[i].draw();
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
    //    pct = (float) y / (float) ofGetWindowHeight();    
}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){
    
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
    for (int i = 0; i < NUM_THINGS; i++) {
        myThing[i].trigger = true;
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
