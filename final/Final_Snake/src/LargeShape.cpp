//
//  LargeShape.cpp
//  Final_Snake
//
//  Created by Owen Herterich on 12/9/13.
//
//

#include "LargeShape.h"

LargeShape::LargeShape() {
    rotation = ofRandom(180);
    scale = ofRandom(0.5, 2.0);
    
    trans = 255;
    c.setHsb(0, 0, 200);
}

void LargeShape::addForce( ofVec2f force ) {
    
}

void LargeShape::update() {
    
}

void LargeShape::draw() {
    
}