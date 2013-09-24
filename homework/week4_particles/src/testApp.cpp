#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofSetVerticalSync(true);
    ofSetBackgroundAuto(false);
    ofEnableAlphaBlending();
    ofBackground(0);


}

//--------------------------------------------------------------
void testApp::update(){
    
    if (ofGetElapsedTimeMillis() % 40 == 0) {
        InitParticle tmp;
        single.push_back( tmp );
    }
    
    
    for ( vector<Particle>::iterator it = particles.begin(); it!=particles.end(); ) {
        it->update();
        
        if ( it->kill() ) {
            it = particles.erase(it);
        }
        else {
            it++;
        }
    }
    
    for ( int i = 0; i < single.size(); i++ ) {
        single[i].update();
        
        if (single[i].kill()) {
            for ( int j = 0; j < 100; j ++ ) {
                createParticle(single[i].pos, single[i].initVel, single[i].c.getHue());
            }
            
            single.erase(single.begin() + i);
        }
    }
    
    
}

//--------------------------------------------------------------
void testApp::draw(){
        
    ofSetRectMode(OF_RECTMODE_CORNER);
    ofSetColor(0, 25);
    ofRect(0, 0, ofGetWindowWidth(), ofGetWindowHeight());
    
    for ( vector<Particle>::iterator it=particles.begin(); it!=particles.end(); ) {
        it->draw();
        it++;
    }
    
    for ( int i = 0; i < single.size(); i++ ) {
        single[i].draw();
    }
        
    ofSetColor(255);
    ofDrawBitmapString(ofToString(particles.size()), 20, 20);
    ofDrawBitmapString(ofToString(single.size()), 20, 40);

}

//--------------------------------------------------------------
void testApp::createParticle(ofVec2f pos, float velMult, float hue){
    Particle tmp;
    tmp.setup(pos, velMult, hue);
    cout << velMult << endl;
    particles.push_back( tmp );
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
    InitParticle tmp;
    single.push_back( tmp );
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