#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    int res = 20;
    
    myField.setup( ofGetWindowWidth()+res, ofGetWindowHeight()+res, res);
    myField.setHorizontal();
    
    ofBackground( 0 );
    ofSetCircleResolution(3);
    ofSetDrawBitmapMode(OF_BITMAPMODE_MODEL);
    
    particleList.clear();
    
    for (int i = 0; i < 500; i++) {
        addParticle();
    }
    
    setFieldDraw = false;
    
    type.loadFont("Futura.ttf", 10);
    

}

void testApp::addParticle() {
    Particle p(&type);
    p.pos = ofVec2f( ofRandomWidth(), ofRandomHeight() );
    
    string alphabet[26] = {"A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z"};
    
    int rand = (int)ofRandom(26);
    
    p.letter = alphabet[rand];
    
    particleList.push_back( p );
}

//--------------------------------------------------------------
void testApp::update(){
    for ( vector<Particle>::iterator i1 = particleList.begin(); i1 != particleList.end(); ++i1 ) {
        
        vector<Particle>::iterator i2 = i1 + 1;
        
        for (i2; i2 != particleList.end(); ++i2) {
            i1->addRepelForce(i2->pos, 15, 0.2);
        }
        
        i1->applyForce( myField.getForceAtPosition( i1->pos ) * 0.05 );
        i1->boundaries();
        i1->update();
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
