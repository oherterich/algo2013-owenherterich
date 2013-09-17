#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofSetVerticalSync(true);
    ofEnableSmoothing();
    ofBackground(230, 230, 255);
    ofEnableAlphaBlending();
    
    amplitude = ofGetWindowHeight() / 2;
    
    type.loadImage("daynight.png");
}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){
    drawGradient();
    drawCircles();
    ofSetColor(255);
    type.draw(0, 0, ofGetWindowWidth(), ofGetWindowHeight());
}

//--------------------------------------------------------------
void testApp::drawGradient(){
    float gradient = sin( ofGetElapsedTimef() );
    
    ofPushMatrix();{
        ofTranslate( ofGetWindowSize() / 2 );
        for (int i = 0; i < ofGetWindowHeight(); i++) {
            float lengthx = amplitude * cos( ofMap( i, 0, ofGetWindowHeight() - 1, 0, PI) );
            float lengthy = amplitude * sin( ofMap( i, 0, ofGetWindowHeight() - 1, 0, PI) );
            float initColor = ofMap(i, 0, ofGetWindowHeight(), 0, 140);
            float color = initColor * -1.0 * sin(ofGetElapsedTimef());
            
            bigCircleColor.setHsb(150, 255 * 0.5, color+102);
            ofSetColor(bigCircleColor);
        ofLine(lengthx, lengthy, -lengthx, -lengthy);
    }
    }ofPopMatrix();
}

//--------------------------------------------------------------
void testApp::drawCircles() {
    ofPoint circle1;
    ofPoint circle2;
    float amp = 325;
    
    circle1.x = amp * cos(ofGetElapsedTimef());
    circle1.y = amp * sin(ofGetElapsedTimef());
    circle2.x = amp * cos(ofGetElapsedTimef() + PI);
    circle2.y = amp * sin(ofGetElapsedTimef() + PI);
    
    float color = ofGetWindowHeight() / 2 * -1.0 * sin(ofGetElapsedTimef());
    circle1Color.setHsb(40, 140, color+102);
    
    ofPushMatrix();{
        ofTranslate( ofGetWindowSize() / 2 );
        ofSetColor(circle1Color);
        ofCircle(circle1, 25);
    }ofPopMatrix();
    
    color = ofGetWindowHeight() / 2 * -1.0 * -1.0 * sin(ofGetElapsedTimef());
    circle1Color.setHsb(40, 40, color+102);
    
    ofPushMatrix();{
        ofTranslate( ofGetWindowSize() / 2 );
        ofSetColor(circle1Color);
        ofCircle(circle2, 25);
    }ofPopMatrix();
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