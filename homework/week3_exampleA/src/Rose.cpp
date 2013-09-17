//
//  Rose.cpp
//  week3_exampleA
//
//  Created by Owen Herterich on 9/13/13.
//
//

#include "Rose.h"

Rose::Rose() {
    amplitude = 100.0;
    angle = 0;
    petals = sqrt(2.0);
    scaleFactor = 0.0;
    rotateFactor = 0;
    
    keepAdding = true;
    
    c.setHsb(255 * 0.5, 255, 255);
}

void Rose::update() {
    angle = ofGetElapsedTimef() * 3;
    scaleFactor += 0.003;
}

void Rose::draw() {
    c.setHsb( 255 * 0.5 * cos( angle / 20 ) + 255 * 0.5, 240, 240);
    
    if (keepAdding == true) {
        ofVec3f tmp;
        tmp.x = amplitude * cos(petals * angle) * sin( angle );
        tmp.y = amplitude * cos(petals * angle) * cos( angle );
        
        pointList.push_back( tmp );
    }
    
    if ( pointList.size() > 2500 || keepAdding == false) {
        pointList.erase( pointList.begin() );
    }
    
    ofPushMatrix();{
        ofTranslate( ofGetWindowSize() / 2 );
        ofRotate((angle+rotateFactor) * 1.5);
        ofScale(scaleFactor, scaleFactor);
        ofNoFill();
        ofSetColor(c);
        ofBeginShape();
        for (int i = 5; i < pointList.size(); i ++) {
            ofVertex( pointList[i] );
            if (scaleFactor >= 5) {
                keepAdding = false;
                pointList[i].x += ofRandom(-.1,.1);
                pointList[i].y += ofRandom(-.1,.1);
                pointList[i].z += 0.3;
                rotateFactor += 0.000001;
            }
        }
        ofEndShape();
    }ofPopMatrix();
}