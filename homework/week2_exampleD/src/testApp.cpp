#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofSetVerticalSync(true);
	ofEnableDepthTest();
    ofEnableAlphaBlending();
    
    ofSetSmoothLighting(true);
    
    lookAt.x = myShape.wall / 2;
    lookAt.y = myShape.wall / 2;
    lookAt.z = myShape.wall / 2;
    
    theta = 0;
    
    cam.lookAt(lookAt);
    cam.move(moveCam.x, moveCam.y, moveCam.z);
}

//--------------------------------------------------------------
void testApp::update(){
    myShape.update();
        
    cam.move(moveCam.x, moveCam.y, moveCam.z);
    cam.lookAt(lookAt);
    moveCam.x = cos(ofDegToRad(theta));
    moveCam.z = sin(ofDegToRad(theta));
    moveCam.y = .2;

}

//--------------------------------------------------------------
void testApp::draw(){
    ofEnableLighting();
    pointLight.enable();
    
    cam.begin();
    ofBackground(0);
    
    drawBoundary();
    
    myShape.draw();
    cam.end();
}

//--------------------------------------------------------------
void testApp::drawBoundary() {
    ofEnableAlphaBlending();
    ofNoFill();
    ofSetLineWidth(1);
    ofSetColor(0, 255, 0);
    
    box.setResolution(5);
    box.setPosition(myShape.wall / 2, myShape.wall / 2, myShape.wall / 2);
    box.setScale(myShape.wall / 100);
    box.drawWireframe();
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