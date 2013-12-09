//
//  LargeShape.cpp
//  Final_Snake
//
//  Created by Owen Herterich on 12/9/13.
//
//

#include "LargeShape.h"

LargeShape::LargeShape( int _shape ) {
    rotation = ofRandom(180);
    scale = ofRandom(0.5, 2.0);
    rotationSpeed = ofRandom(0.1, 1.1);
    
    trans = 255;
    c.setHsb(0, 0, 200);
    
    shape = _shape;
}

void LargeShape::addForce( ofVec2f force ) {
    acc += force;
}

void LargeShape::screenBoundaryCheck() {
    if ( pos.x > ofGetWindowWidth() + 10 * scale * 2) {
        pos.x = 0 - 10 * scale * 2;
    }
    
    if ( pos.x < 0 - 10 * scale * 2) {
        pos.x = ofGetWindowWidth() + 10 * scale * 2;
    }
    
    if ( pos.y > ofGetWindowHeight() + 10 * scale * 2) {
        pos.y = 0 - 10 * scale * 2;
    }
    
    if ( pos.y < 0 - 10 * scale * 2) {
        pos.y = ofGetWindowHeight() + 10 * scale * 2;
    }
}

void LargeShape::update() {
    screenBoundaryCheck();
    
    vel += acc;
    pos += vel;
    
    acc.set(0);
    
    rotation += rotationSpeed;
}

void LargeShape::draw() {
    ofFill();
    ofSetColor(c, trans);
    
    ofPushMatrix();{
        
        ofTranslate(pos);
        ofRotate(rotation);
        ofScale(scale, scale, scale);
        
        switch (shape) {
            case 0:
                drawTriangle();
                break;
                
            case 1:
                drawSquare();
                break;
        }
        
    }ofPopMatrix();
}

void LargeShape::drawTriangle() {
    ofTriangle(-25, 25, 0, -25, 25, 25);
}

void LargeShape::drawSquare() {
    ofRect(0, 0, 50, 50);
}