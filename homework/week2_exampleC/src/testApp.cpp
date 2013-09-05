#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofSetVerticalSync(true);

}

//--------------------------------------------------------------
void testApp::update(){    
    for ( int i = 0; i < ballList.size(); i++ ) {
        ballList[i].wallCollide();
        ballList[i].update();
        
//        if (ballList[i].kill()) {
//            ballList.erase( ballList.begin() + i );
//        }
    }
    
    if (ballList.size() > 0) {
    cout << ballList[0].vel.x << " " << ballList[0].vel.y << endl;
    }
}

//--------------------------------------------------------------
void testApp::draw(){
    for ( int i = 0; i < ballList.size(); i++ ) {
        ballList[i].draw();
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

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
    Ball tmpBall;
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