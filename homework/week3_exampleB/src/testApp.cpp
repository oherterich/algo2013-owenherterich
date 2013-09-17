#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofSetVerticalSync(true);

    hue = 0;
    amp = ofGetWindowHeight() / 4;
    
    song.loadSound("HorseSteppin.mp3");
    song.play();
    
    for (int i = 0; i < 1000; i++) {
        Circle tmp;
        myCircles.push_back( tmp );
    }    
}

//--------------------------------------------------------------
void testApp::update(){
    for (int i = 0; i < myCircles.size(); i++) {
        myCircles[i].update();
    }
    
    for (int i = 0; i < myRectangles.size(); i++) {
        myRectangles[i].update();
    }
    
    rectangleTimer();
}

//--------------------------------------------------------------
void testApp::draw(){
    background();
    
    for (int i = 0; i < myCircles.size(); i++) {
        myCircles[i].draw(hue);
    }
    
    for (int i = 0; i < myRectangles.size(); i++) {
        myRectangles[i].draw();
        cout << i << " " << myRectangles[i].pos.x << endl;
    }
    
    line1Draw();
    line2Draw();
}

//--------------------------------------------------------------
void testApp::background() {
    hue += 0.05;
    
    if (hue >= 255.0) {
        hue = 0;
    }
    
    ofFill();
    ofColor c;
    c.setHsb(hue, 255 * 0.4, 255);
    ofSetColor(c);
    ofRect(0, 0, ofGetWindowWidth(), ofGetWindowHeight());
}

//--------------------------------------------------------------
void testApp::line1Draw() {
    ofPoint tmp;
    tmp.x = ofGetWindowWidth() / 4;
    tmp.y = amp * (sin( ofGetElapsedTimef() * 0.9 ) + sin( ofGetElapsedTimef() * 0.1 ));
        
    line1.push_back( tmp );
    
    if (line1.size() > 200) {
        line1.erase(line1.begin());
    }
    
    ofPushMatrix(); {
        ofTranslate(ofGetWindowSize() / 2);
        ofNoFill();
        ofSetLineWidth(3.0);
        ofColor c;
        c.setHsb(hue, 255 * 0.4, 140);
        ofSetColor(c, 100);
        ofBeginShape();
        for (int i = 0; i < line1.size(); i++) {
            ofVertex(line1[i]);
            line1[i].z += 1.0;
        }
        ofEndShape();
    }ofPopMatrix();
}

//--------------------------------------------------------------
void testApp::line2Draw() {
    ofPoint tmp;
    tmp.x = - ofGetWindowWidth() / 4;
    tmp.y = amp * (sin( ofGetElapsedTimef() * 0.9 ) + sin( ofGetElapsedTimef() * 0.1 ));
    
    line2.push_back( tmp );
    
    if (line2.size() > 200) {
        line2.erase(line2.begin());
    }
    
    ofPushMatrix(); {
        ofTranslate(ofGetWindowSize() / 2);
        ofNoFill();
        ofSetLineWidth(3.0);
        ofColor c;
        c.setHsb(hue, 255 * 0.4, 140);
        ofSetColor(c, 100);
        ofBeginShape();
        for (int i = 0; i < line2.size(); i++) {
            ofVertex(line2[i]);
            line2[i].z += 1.0;
        }
        ofEndShape();
    }ofPopMatrix();
}

//--------------------------------------------------------------
void testApp::rectangleTimer() {
    int time = ofGetElapsedTimeMillis();

    if (time % 100 == 0) {
        Rectangle tmp;
        myRectangles.push_back( tmp );
    }
    
    for (int i = 0; i < myRectangles.size(); i++) {
        if (myRectangles[i].dead()) {
            myRectangles.erase(myRectangles.begin() + i);
        }
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