#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofSetVerticalSync( true );
    ofBackground( 0 );
    ofSetRectMode( OF_RECTMODE_CENTER );
    ofEnableAlphaBlending();
        
    px = 0.1;
    py = 0.1;
    
    a = -0.966918,			// coefficients for "The King's Dream"
	b = 2.879879,
	c = 0.765145,
	d = 0.744728;
    
    for (int i = 0; i < 50000; i++) {
        ofPoint tmp;
        tmp.x = (sin(py*b) + c*sin(px*b));
		tmp.y = (sin(px*a) + d*sin(py*a));
        
        px = tmp.x;
        py = tmp.y;
        
        tmp.x *= 200;
        tmp.y *= 200;
        
        a += ofRandom(-0.01, 0.01);
        b += ofRandom(-0.01, 0.01);
        c += ofRandom(-0.01, 0.01);
        d += ofRandom(-0.01, 0.01);

        
        points.push_back( tmp );
        
    }
    
//    for (int i = 0; i < 1000000; i++) {
//        Particle tmp;
//        tmp.pos.x = sin(y*b) + c*sin(x*b);
//		tmp.pos.y = sin(x*a) + d*sin(y*a);
//        
//        x = tmp.pos.x;
//        y = tmp.pos.y;
//        
//        tmp.pos.x *= 200;
//        tmp.pos.y *= 200;
//        
//        particles.push_back( tmp );
//    }
}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){
    ofNoFill();
    ofSetColor(255, 5);

    
    ofPushMatrix();{
        ofBeginShape();
        ofTranslate(ofGetWindowSize() / 2);
        for (vector<ofPoint>::iterator it = points.begin(); it != points.end(); it++) {
            ofVertex(it->x, it->y);
        }
        ofEndShape();
    }ofPopMatrix();
    
//    
//    for (vector<Particle>::iterator it = particles.begin(); it != particles.end(); it++) {
//        it->draw();
//    }
//
    
    
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    if (key == 's') {
        myImage.grabScreen(0,0,ofGetWindowWidth(),ofGetWindowHeight());
        myImage.saveImage("partOfTheScreen-"+ofToString(num)+".png");
        num++;
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
    px = 0.1;
    py = 0.1;
    
    a = -0.966918,			// coefficients for "The King's Dream"
	b = 2.879879,
	c = 0.765145,
	d = 0.744728;
    
    for (int i = 0; i < points.size(); i++) {
        points[i].x = (sin(py*b) + c*sin(px*b));
		points[i].y = (sin(px*a) + d*sin(py*a));
        
        px = points[i].x;
        py = points[i].y;
        
        points[i].x *= 200;
        points[i].y *= 200;
        
        a += ofRandom(-0.01, 0.01);
        b += ofRandom(-0.01, 0.01);
        c += ofRandom(-0.01, 0.01);
        d += ofRandom(-0.01, 0.01);
        
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
