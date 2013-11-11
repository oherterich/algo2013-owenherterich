//
//  Circle.cpp
//  week11_duration
//
//  Created by Owen Herterich on 11/10/13.
//
//

#include "Circle.h"

Circle::Circle() {
    
}

void Circle::update() {
    
}

void Circle::draw() {
    
    
    ofPushMatrix();{
        
        ofTranslate(ofGetWindowWidth() / 2, ofGetWindowHeight() / 2);
    
        ofSetColor(outerColor);
        ofCircle(pos, outerSize);
        
        ofSetColor(innerColor);
        ofCircle(pos, innerSize);
        
    }ofPopMatrix();
}
