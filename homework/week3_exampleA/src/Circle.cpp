//
//  Circle.cpp
//  week3_exampleA
//
//  Created by Owen Herterich on 9/13/13.
//
//

#include "Circle.h"

Circle::Circle() {
    shaper = .5;
    opacity = 70;
}

void Circle::setup(ofVec3f _pt, float _amplitude) {
    pt = _pt;
    amplitude = _amplitude;
}

void Circle::update() {
    opacity -= 0.04;
}

void Circle::draw() {
    ofPushMatrix();{
        float angle = ofGetElapsedTimef() * 3;
        ofTranslate( ofGetWindowSize() / 2 );
        ofRotate( -angle );
        ofFill();
        ofSetColor(255, opacity);
        ofCircle(pt * amplitude, 40);
    }ofPopMatrix();
}