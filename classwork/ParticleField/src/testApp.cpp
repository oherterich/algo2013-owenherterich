#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    myField.setup( ofGetWindowWidth(), ofGetWindowHeight(), 20 );
        
    ofBackground(0);
    
    for (int i = 0; i < 500; i++) {
        addParticle();
    }
}

//--------------------------------------------------------------
void testApp::update(){
    
    for( int i = 0; i < particleList.size(); i++ ) {
        particleList[i].applyForce( myField.getForceAtPosition( particleList[i].pos ) * 0.005 );
        particleList[i].update();
    }
    
    myField.update();
}

//--------------------------------------------------------------
void testApp::draw(){
    
    for( int i = 0; i < particleList.size(); i++ ) {
        particleList[i].draw();
    }

    myField.draw();
}

void testApp::addParticle() {
    Particle tmp;
    tmp.pos = ofVec2f( ofRandomWidth(), ofRandomHeight() );
    
    particleList.push_back( tmp );
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    if( key == '1'){
        myField.setRandom( 20.0 );
    }else if( key == '2' ){
        myField.setPerlin();
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
    
    
    if( button == OF_MOUSE_BUTTON_1 ){
//        myField.addRepelForce(x, y, 100, 2.0);
        myField.addCircularForce(x, y, 300, 2.0);
    }else{
        myField.addAttractForce(x, y, 100, 2.0);
    }
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
    mouseDragged(x, y, button);
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
