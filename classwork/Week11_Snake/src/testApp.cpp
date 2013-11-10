#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofSetVerticalSync( true );
    ofSetFrameRate(60);
    ofSetRectMode(OF_RECTMODE_CENTER);
    ofBackground(0);
    
    mSender.setup("192.168.1.129", 12345);
    mReceiver.setup(12345);
    
    pos = ofGetWindowSize() / 2;
    vel = ofVec2f(3.0, 0);
    
    snakeLength = 75;
    snakeSize = 10;
    c = ofColor(255,255,0);
    
    end.loadImage("gameover.png");
    
    for (int i = 0; i < snakeLength; i++) {
        ofVec2f p;
        p = ofGetWindowSize() / 2;
        snake.push_back( p );
    }
    
    state = 0;
}

//--------------------------------------------------------------
void testApp::update(){
    
    receiveOsc();
    sendOsc();
    
    for (int i = 0; i < snake.size() - 1; i++) {
        snake[i] = snake[i+1];
    }
    
    snake[snake.size()-1] = pos;
    
    if (state == 0) {
        pos += vel;
    }
    
    if (pos.x > ofGetWindowWidth() - snakeSize / 2) {
        pos.x = snakeSize / 2;
    }
    
    if (pos.x < snakeSize / 2) {
        pos.x = ofGetWindowWidth() - snakeSize / 2;
    }
    
    if (pos.y > ofGetWindowHeight() - snakeSize / 2) {
        pos.y = snakeSize / 2;
    }
    
    if (pos.y < snakeSize / 2) {
        pos.y = ofGetWindowHeight() - snakeSize / 2;
    }
    
    snakeCollision();
}

void testApp::snakeCollision(){
    for (int i = 0; i < snake.size(); i++) {
        for (int j = 0; j < obList.size(); j++) {
            if ( snake[i].distance(obList[j]) < 10 ) {
                state = 1;
            }
        }
    }
}

//--------------------------------------------------------------
void testApp::draw(){
    
    for (int i = 0; i < snake.size(); i++) {
        ofSetColor(c);
        ofRect(snake[i], 10, 10);
    }
    
    for (int i = 0; i < obList.size(); i++) {
        ofSetColor(255, 0, 0);
        ofRect(obList[i], 25, 25);
    }
    
    if (state == 1) {
        ofSetRectMode(OF_RECTMODE_CORNER);
        ofSetColor(255);
        end.draw(0,0);
    }
    
}

void testApp::sendOsc(){
    ofxOscMessage m;
    m.setAddress("/snake/pos");
    m.addFloatArg(pos.x);
    m.addFloatArg(pos.y);
    
    mSender.sendMessage( m );
}

void testApp::receiveOsc(){
    while( mReceiver.hasWaitingMessages() ) {
        ofxOscMessage m;
        mReceiver.getNextMessage( &m );
        
        string addr = m.getAddress();
        
        if (addr == "/ob/pos") {
            
            float xPos = m.getArgAsFloat(0);
            float yPos = m.getArgAsFloat(1);
            
            addOb( ofVec2f(xPos, yPos) );
        }
    }
}

void testApp::addOb( ofVec2f pos ){
    ofVec2f tmp;
    tmp = pos;
    obList.push_back( tmp );
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

    if (key == OF_KEY_UP) {
        vel.set(0.0, -3.0);
    }
    
    if (key == OF_KEY_RIGHT) {
        vel.set(3.0, 0.0);
    }
    
    if (key == OF_KEY_DOWN) {
        vel.set(0.0, 3.0);
    }
    
    if (key == OF_KEY_LEFT) {
        vel.set(-3.0, 0.0);
    }
    
    if (key == 'r' || key == 'R') {
        state = 0;
        pos = ofGetWindowSize() / 2;
    }
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
