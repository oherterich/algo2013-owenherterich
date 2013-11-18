#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofSetVerticalSync( true );
    ofBackground( 0 );
    
    bIsDragged = false;
    
    for( int i = 0; i < 12; i++ ){
        SpringJoint sj;
        sj.pos = ofVec2f( ofGetWindowWidth() / 2, 10 + i * 55 );
        jointList.push_back( sj );
    }
    
    for( int i = 0; i < jointList.size()-1; i++ ){
        Spring s;
        s.set( &jointList[i], &jointList[i+1], 0.05, 60.0 );
        springList.push_back( s );
    }
    
    Spring s;
    s.set(&jointList[jointList.size() - 1], &jointList[0], 0.05, 60.0);
    springList.push_back( s );
}

//--------------------------------------------------------------
void testApp::update(){
    
    if (bIsDragged) {
        return;
    }
    
    for ( int i = 0; i < jointList.size(); i++ ){
        jointList[i].update();
    }
    
    for ( int i = 0; i < springList.size(); i++ ){
        springList[i].update();
    }
}

//--------------------------------------------------------------
void testApp::draw(){
    for ( int i = 0; i < springList.size(); i++ ){
        springList[i].draw();
    }
    
    for ( int i = 0; i < jointList.size(); i++ ){
        jointList[i].draw();
    }

}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    int rand = floor( ofRandom( jointList.size() ) );
    jointList[rand].applyForce( ofVec2f(ofRandom(-20, 20), ofRandom(-20, 20)) );
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){
    if (bIsDragged){
        for ( int i = 0; i < jointList.size(); i++ ) {
            if( ofVec2f(x, y).distance(jointList[i].pos) < 30) {
                jointList[i].pos.set( x, y );
            }
        }
 
    }
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
    for ( int i = 0; i < jointList.size(); i++ ) {
        if( ofVec2f(x, y).distance(jointList[i].pos) < 30) {
            jointList[i].pos.set( x, y );
            jointList[i].vel.set( 0 );
            bIsDragged = true;
        }
    }
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){
    bIsDragged = false;
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
