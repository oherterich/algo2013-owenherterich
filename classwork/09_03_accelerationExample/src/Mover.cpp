//
//  Mover.cpp
//  09_03_accelerationExample
//
//  Created by Owen Herterich on 9/3/13.
//
//

#include "Mover.h"

Mover::Mover() {
    
    ofSetRectMode(OF_RECTMODE_CENTER);
    
    pos = ofGetWindowSize() / 2;
        
    vel.x = ofRandom( -5.0, 5.0 );
    vel.y = ofRandom( -5.0, 5.0 );
    
    dragged = false;
    leader = false;
    
    r = 20;
    catchUpSpeed = 0.3;
}

void Mover::update() {
    if (dragged) {
        accel = (mousePos - pos) * 0.005;
    }
    else {
        accel.x = 0;
        accel.y = 0;
    }
    
    vel += accel;
    
    pos += vel;
    vel *= 0.992;
}

void Mover::draw( ofColor c ) {
    ofSetColor( c , 100);
    ofCircle( pos, r );
}

void Mover::wallCollision() {
    
    if (pos.x < r) {
        pos.x = r;
        vel.x *= -1;
    }
    
    if (pos.x > ofGetWindowWidth() - r) {
        pos.x = ofGetWindowWidth() - r;
        vel.x *= -1;
    }
    
    if (pos.y < r) {
        pos.y = r;
        vel.y *= -1;
    }
    
    if (pos.y > ofGetWindowHeight() - r) {
        pos.y = ofGetWindowHeight() - r;
        vel.y *= -1;
    }
    
}

void Mover::xenoToPoint(ofVec2f catchPos) {
    pos.x = catchUpSpeed * catchPos.x + (1 - catchUpSpeed) * pos.x;
    pos.y = catchUpSpeed * catchPos.y + (1 - catchUpSpeed) * pos.y;
}