#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofSetVerticalSync(true);
    ofBackground(0);
    
    Creature tmp;
    myCreatures.push_back( tmp );
}

//--------------------------------------------------------------
void testApp::update(){
    for (int i = 0; i < myCreatures.size(); i++) {
        myCreatures[i].update();
        myCreatures[i].xenoToPoint(mouseX, mouseY);
        myCreatures[i].mousePos.x = mouseX;
        myCreatures[i].mousePos.y = mouseY;
        
    }
}

//--------------------------------------------------------------
void testApp::draw(){
    for (int i = 0; i < myCreatures.size(); i++) {
        myCreatures[i].draw();
    }
    
    ofSetColor(240);
    ofDrawBitmapString("Press 'A' to add new creatures", ofPoint(10, 15));
    ofDrawBitmapString("Press 'R' to push the creatures back", ofPoint(10, 30));
    ofDrawBitmapString("Click on the creature to remove", ofPoint(10, 45));
    
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    if (key == 'a') {
        Creature tmp;
        myCreatures.push_back( tmp );
    }
    
    if (key == 'r') {
        for (int i = 0; i < myCreatures.size(); i++) {
            myCreatures[i].vel = myCreatures[i].diff * -0.03;
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
    for (int i = 0; i < myCreatures.size(); i++) {
        if (myCreatures[i].kill()) {
            myCreatures.erase( myCreatures.begin() + i);
        }
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