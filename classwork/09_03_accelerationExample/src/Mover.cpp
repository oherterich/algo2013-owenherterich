//
//  Mover.cpp
//  09_03_accelerationExample
//
//  Created by Owen Herterich on 9/3/13.
//
//

#include "Mover.h"

Mover::Mover() {
    
    pos = ofGetWindowSize() / 2;
        
    vel.x = ofRandom( -5.0, 5.0 );
    vel.y = ofRandom( -5.0, 5.0 );
}

void Mover::update() {
    accel = (mousePos - pos) * 0.005;
    vel += accel;
    
    pos += vel;
    vel *= 0.97;
}

void Mover::draw() {
    ofCircle( pos, 20 );
}