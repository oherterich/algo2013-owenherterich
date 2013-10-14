#include "testApp.h"

//-------------------------------------------------------------------------------
//-------------------------------------------------------------------------------
// This code was altered from Albert Kim's Attractor / Repulsor code, located at:
// https://github.com/oherterich/kim_algo2013/tree/master/wk6_attractorRepulsor
//-------------------------------------------------------------------------------
//-------------------------------------------------------------------------------


//--------------------------------------------------------------
void testApp::setup(){
    
    ofSetVerticalSync(true);
    ofSetFrameRate(60);
    ofBackground(2, 40, 64);
    ofEnableAlphaBlending();
    
    for (int i = 0; i < 100; i++){
        Particle myParticle;
        
        float randX = ofRandom(0,1000);
        float randY = ofRandom(0,1000);
        
        myParticle.setInitCondition( randX, randY, 0, 0);
        myParticle.damping = ofRandom(0.01,0.05);
        particles.push_back(myParticle);
        
        ofPoint tmp;
        tmp.set(randX, randY);
        vertices.push_back( tmp );
    }
    
    repulsion = false;
    
}

//--------------------------------------------------------------
void testApp::update(){
    
    for (int i = 0; i < particles.size(); i++){
        particles[i].resetForce();
        
        for (int j = i+1; j < particles.size(); j++) {
            particles[i].addRepulsion(particles[j].pos.x, particles[j].pos.y, particles[i].size + 10, particles[i].size / 2);
        }
        
        if (repulsion) {
            ofVec2f center;
            center.set(ofGetWindowWidth() / 2, ofGetWindowHeight() / 2);
            
            ofVec2f diff = center - particles[i].pos;
            diff.normalize();
            particles[i].vel *= diff * 5.0;
        }
        
        particles[i].addDamping();
        particles[i].addBoundaries();
        particles[i].update();
        particles[i].size = (1.0 -  i / (float)particles.size() ) * 10.0;
        
        
        vertices[i].x = particles[i].pos.x;
        vertices[i].y = particles[i].pos.y;
        
        if (i == 0){
            particles[i].trail(mouseX, mouseY);
        }else{
            particles[i].trail(particles[i-1].pos.x, particles[i-1].pos.y);
        }
    }
    
    repulsion = false;
    
    particles[0].vel.x += cos( ofNoise( ofGetElapsedTimef() * 0.001 ) ) * 3.0;
    particles[0].vel.y += sin( ofNoise( ofGetElapsedTimef() * 0.001 + 1000) ) * 3.0;

}

//--------------------------------------------------------------
void testApp::draw(){
    
    
    ofSetColor(242,220,153,30);
    ofNoFill();
    ofBeginShape();
    for (int i = 1; i < vertices.size(); i++) {
        ofVertex( vertices[i] );
    }
    ofEndShape();
    
    for (int i = 1; i < particles.size(); i++){
  
        particles[i].draw();
    }
    


}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

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
    repulsion = true;
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
