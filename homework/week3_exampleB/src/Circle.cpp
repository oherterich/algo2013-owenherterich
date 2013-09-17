//
//  Circle.cpp
//  week3_exampleB
//
//  Created by Owen Herterich on 9/16/13.
//
//

#include "Circle.h"

Circle::Circle() {
    pos.x = ofRandom( -3000, 3000 );
    pos.y = ofRandom( -3000, 3000 );
    pos.z = ofRandom( -10000, 0 );
    
    size = ofRandom( 15, 30 );
    
    opacity = ofRandom(40, 70);
}

void Circle::update() {
    pos.z += 1.0;
}

void Circle::draw(float hue) {
    ofFill();
    c.setHsb(hue, 255 * 0.4, 180);
    ofSetColor(c, opacity);
    ofCircle( pos, size );
}