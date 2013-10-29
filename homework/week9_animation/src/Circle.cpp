//
//  Circle.cpp
//  week9_animation
//
//  Created by Owen Herterich on 10/28/13.
//
//

#include "Circle.h"

Circle::Circle( float _size, float _offset ) {
    size = _size;
    initSize = size;
    offset = _offset;
    
    numTri = ofRandom(30, 120);
    sizeTri = ofRandom(7, 10);
    
    amplitude = ofRandom(0.9, 1.3);
}

void Circle::update() {
    
    size = ofMap(sin(ofGetElapsedTimef() * amplitude + offset), -1, 1, -initSize, initSize);
}

bool Circle::changeColor() {
    if (size < 5 && size > -5) {
        numTri = ofRandom(30, 120);
        sizeTri = ofRandom(7, 10);
        return true;
    }
    else return false;
}

void Circle::draw() {
    
    ofSetColor( c );

    ofPushMatrix();{
        ofTranslate(ofGetWindowWidth() / 2, ofGetWindowHeight() / 2);
        
        for (int i = 0; i < numTri; i++) {
            ofPushMatrix();{
                float x = cos( ofDegToRad( i * (360 / numTri) * sin(ofGetElapsedTimef() * amplitude + offset)) ) * size * 1.08;
                float y = sin( ofDegToRad( i * (360 / numTri) * sin(ofGetElapsedTimef() * amplitude + offset))  ) * size * 1.08;
                ofTranslate(x, y);
               // ofRotate(i * 360 / numTri - 30);
                ofFill();
                ofTriangle(sizeTri / 2, 0, sizeTri, sizeTri, 0, sizeTri);
            }ofPopMatrix();
        }
        
        ofNoFill();
        ofSetLineWidth(10);
        ofCircle(pos, size);
    }ofPopMatrix();
}