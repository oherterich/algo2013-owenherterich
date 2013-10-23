#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    int res = 20;
    
    myField.setup( ofGetWindowWidth()+res, ofGetWindowHeight()+res, res);
    ofBackground( 0 );
    ofSetCircleResolution(3);
    
    particleList.clear();
    
    for (int i = 0; i < 10000; i++) {
        addParticle();
    }
    
    setFieldDraw = true;

}

void testApp::addParticle() {
    Particle p;
    p.pos = ofVec2f( ofRandomWidth(), ofRandomHeight() );
    
    particleList.push_back( p );
}

//--------------------------------------------------------------
void testApp::update(){
    for ( vector<Particle>::iterator it = particleList.begin(); it != particleList.end(); it++ ) {
        it->applyForce( myField.getForceAtPosition( it->pos ) * 0.05 );
        it->boundaries();
        it->update();
    }
}

//--------------------------------------------------------------
void testApp::draw(){
    if (setFieldDraw) {
        ofSetColor(255);
        myField.draw();
    }
    
    for ( vector<Particle>::iterator it = particleList.begin(); it != particleList.end(); it++ ) {
        it->draw();
    }
    
    if (bSnapshot == true){
		img.grabScreen(0,0,ofGetWindowWidth(),ofGetWindowHeight());
        
		string fileName = "snapshot_"+ofToString(10000+snapCounter)+".png";
		img.saveImage(fileName);
		snapCounter++;
		bSnapshot = false;
	}

}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    if (key == '1') {
        myField.setDirectional();
    }
    
    if (key == 'd' || key == 'D') {
        setFieldDraw = !setFieldDraw;
    }
    
    if (key == 'x'){
		bSnapshot = true;
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
