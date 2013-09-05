#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofSetVerticalSync(true);
	ofEnableDepthTest();
    ofEnableAlphaBlending();
    
    ofSetSmoothLighting(true);
    pointLight.setDiffuseColor( ofFloatColor(.85, .85, .55) );
    pointLight.setSpecularColor( ofFloatColor(1.f, 1.f, 1.f));
    pointLight.setPosition(0,0,0);
}

//--------------------------------------------------------------
void testApp::update(){
    myShape.update();
}

//--------------------------------------------------------------
void testApp::draw(){
    ofEnableLighting();
    pointLight.enable();
    
    cam.begin();
    ofBackground(255);
    
    drawBoundary();
    
    myShape.draw();
    cam.end();
}

//--------------------------------------------------------------
void testApp::drawBoundary() {
    ofEnableAlphaBlending();
    ofNoFill();
    ofSetLineWidth(3);
    ofSetColor(0, 255, 0);
    ofDrawBox(ofPoint(myShape.wall / 2, myShape.wall / 2, myShape.wall / 2), myShape.wall);
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