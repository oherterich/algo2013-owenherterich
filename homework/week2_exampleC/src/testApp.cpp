#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofSetVerticalSync(true);
    
    gravity = 44094.48f / (ofGetFrameRate() * ofGetFrameRate());
    
    whatGravity = "Earth";
    
    initPos.x = ofGetWindowWidth() / 2;
    initPos.y = ofGetWindowHeight();

}

//--------------------------------------------------------------
void testApp::update(){    
    for ( int i = 0; i < ballList.size(); i++ ) {
        ballList[i].update();
        ballList[i].wallCollide();

    }
    
    mousePos.x = mouseX;
    mousePos.y = mouseY;
    
}

//--------------------------------------------------------------
void testApp::draw(){
    ofBackground(0);
    for ( int i = 0; i < ballList.size(); i++ ) {
        ballList[i].draw();
    }

    drawCannon();
    
    ofDrawBitmapString("Press 'E' for Earth gravity", ofPoint(20,20));
    ofDrawBitmapString("Press 'M' for Moon gravity", ofPoint(20, 40));
    ofDrawBitmapString("Press 'J' for Jupiter gravity", ofPoint(20,60));
    ofDrawBitmapString("Press 'R' to reset", ofPoint(20, 80));
    ofDrawBitmapString("Current gravity:", ofPoint(20, 120));
    string tmp = whatGravity + ", " + ofToString(gravity) + " px/s^2";
    ofDrawBitmapString(tmp, ofPoint(160, 120));
}

//--------------------------------------------------------------

void testApp::drawCannon() {
    ofPushMatrix(); {
        ofTranslate(ofGetWindowWidth() / 2, ofGetWindowHeight());
        ofVec2f result = (mousePos - initPos);
        result.normalize();
        result *= 50;
        ofSetLineWidth(200);
        ofSetColor(220);
        ofLine( ofVec2f(0,0), result);
    }ofPopMatrix();
}

//--------------------------------------------------------------

void testApp::keyPressed(int key){

    if (key == 'e' || key == 'E') {
        gravity = 44094.48f / (ofGetFrameRate() * ofGetFrameRate());
        initVel = 0.21;
        whatGravity = "Earth";
        for ( int i = 0; i < ballList.size(); i++ ) {
            ballList[i].accel.y = gravity;
        }
    }
    
    if (key == 'm' || key == 'M') {
        gravity = 44094.48f / (ofGetFrameRate() * ofGetFrameRate()) * 0.16666;
        initVel = 0.01;
        whatGravity = "Moon";
        for ( int i = 0; i < ballList.size(); i++ ) {
            ballList[i].accel.y = gravity;
        }
    }
    
    if (key == 'j' || key == 'J') {
        gravity = 44094.48f / (ofGetFrameRate() * ofGetFrameRate()) * 2.53;
        initVel = 10.0;
        whatGravity = "Jupiter";
        for ( int i = 0; i < ballList.size(); i++ ) {
            ballList[i].accel.y = gravity;
        }
    }
    
    if (key == 'r' || key == 'R') {
        for ( int i = 0; i < ballList.size(); i++ ) {
            ballList.erase( ballList.begin(), ballList.begin() + ballList.size() );
        }
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
    Ball tmpBall;
    tmpBall.setup(gravity, initVel);
    cout << tmpBall.accel.y << " " << tmpBall.initVel << endl;
    ballList.push_back( tmpBall );
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