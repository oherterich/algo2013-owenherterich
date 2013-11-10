#include "testApp.h"

//******************************************************************
//******************************************************************
//********** USE THE NUMBER KEYS 1 - 6 TO CHANGE MODES. ************
//*** PRESS SPACEBAR TO FREEZE, CLICK TO CHANGE FRAME, S TO SAVE ***
//******************************************************************
//******************************************************************
 
//--------------------------------------------------------------
void testApp::setup(){
    ofSetVerticalSync( true );
    ofBackground( 0 );
    ofSetBackgroundAuto( true );
    ofEnableAlphaBlending();
    
    for (int i = 0; i < 20000; i++) {
        addParticle();
    }
    
    for (int i = 0; i < 5; i++) {
        Mover tmp;
        moverList.push_back( tmp );
    }
    
    attract = false;
    
    stepA = ofRandom(80,120);
    stepB = ofRandom(80,120);
    
    lastTime = ofGetElapsedTimef();
    timeScale = 1.0;
    
    mode = 1;
    imgNum = 0;
    
    myFbo.allocate(ofGetWindowWidth(), ofGetWindowHeight());
}

//--------------------------------------------------------------
void testApp::update(){
    
    float dt = ofGetElapsedTimef() - lastTime;
    lastTime = ofGetElapsedTimef();
    
    if (stopTime && !nextFrame) {
        timeScale = 0.0;
    }
    else if (stopTime && nextFrame) {
        timeScale = 1.0;
    }
    
    for (vector<Particle>::iterator it = particleList.begin(); it != particleList.end(); it++) {
        
        if (attract) {
            for (int i = 0; i < moverList.size(); i++) {
                it->attractForce(moverList[i].pos.x, moverList[i].pos.y, moverList[i].rAttract, moverList[i].sAttract);
                it->repulseForce(moverList[i].pos.x, moverList[i].pos.y, moverList[i].rRepulse, moverList[i].sRepulse);
            }
        }

        it->update( dt * timeScale );
    }
    
    for (int i = 0; i < moverList.size(); i++) {
        moverList[i].update();
    }
    
    nextFrame = false;
}

//--------------------------------------------------------------
void testApp::draw(){
    
    ofSetWindowTitle(ofToString(ofGetFrameRate()));
    
    myFbo.begin();
    
    if (mode != 4 && mode != 5 && mode != 6) {
        ofSetColor(255, 255, 255, 0);
        ofClear(255, 255, 255, 0);
    }
    else {
        ofBackground(0);
    }
    
    ofSetRectMode( OF_RECTMODE_CENTER );
    for (vector<Particle>::iterator it = particleList.begin(); it != particleList.end(); it++) {
        it->draw();
    }
    
    myFbo.end();
    
    ofSetRectMode( OF_RECTMODE_CORNER );
    ofSetColor(255);
    ofBackground(0);
    
    myFbo.draw(0,0);
    drawFbos();
    

}

void testApp::drawFbos() {
    
    switch (mode) {
        case 1:
            stepA = 90;
            stepB = 110;
            break;
            
        case 2:
            stepA = 5;
            stepB = 5;
            break;
            
        case 3:
            stepA = 2;
            stepB = 2;
            break;
            
        case 4:
            stepA = 3;
            stepB = 3;
            break;
            
        case 5:
            stepA = 10;
            stepB = 10;
            break;
            
        case 6:
            stepA = 25;
            stepB = 25;
            break;
    }
    
    for (int x = 0; x < ofGetWindowWidth() / 2; x += stepA) {
            myFbo.draw(x, 0);
    }
    
    for (int x = 0; x < ofGetWindowWidth() / 2; x += stepB) {
        ofPushMatrix();{
        ofTranslate(ofGetWindowWidth() - x, 0);
        ofScale(-1.0, 1.0);
        myFbo.draw(x, 0);
        } ofPopMatrix();
    }
    
}

void testApp::addParticle() {
    Particle tmp;
    particleList.push_back( tmp );
    ofMap()
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    if (key == ' ') {
        stopTime = !stopTime;
        timeScale = ofMap(mouseX, 0, ofGetWindowWidth(), -3.0, 3.0);
    }
    
    if (key == 's') {
        ofSaveScreen("image_" + ofToString(imgNum) + ".png");
        imgNum++;
    }
    
    switch (key) {
        case '1':
            mode = 1;
            break;
            
        case '2':
            mode = 2;
            break;
            
        case '3':
            mode = 3;
            break;
            
        case '4':
            mode = 4;
            break;
            
        case '5':
            mode = 5;
            break;
            
        case '6':
            mode = 6;
            break;
            
        default:
            break;
    }
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){
    timeScale = ofMap(x, 0, ofGetWindowWidth(), -3.0, 3.0);
}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
    if (!stopTime) {
        stopTime = true;
    }
    
    nextFrame = true;
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
