//
//  Background.cpp
//  week3_exampleA
//
//  Created by Owen Herterich on 9/13/13.
//
//

#include "Background.h"

Background::Background() {
 
    for (int i = 0; i < 300; i++) {
        ofPoint tmp;
        tmp.x = ofRandom(ofGetWindowWidth());
        tmp.y = ofRandom(ofGetWindowHeight());
        
        pointList.push_back( tmp );
        
        float tmpB = ofRandom(50, 100);
        brightness.push_back( tmpB );
    }
    
}

void Background::update() {
    for (int i = 0; i < brightness.size(); i++) {
        brightness[i] += ofRandom(-10,10);
    }
}

void Background::draw() {
    for (int i = 0; i < pointList.size(); i++) {
        ofSetColor( brightness[i], brightness[i], brightness[i] + 5 );
        ofFill();
        ofRect(pointList[i], 2, 2);
    }
}