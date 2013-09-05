//
//  Ball.cpp
//  09_03_vectors
//
//  Created by Owen Herterich on 9/3/13.
//
//

#include "Ball.h"

Ball::Ball() {
    ofSeedRandom();
    
    xVel = ofRandom(0.0, 1.0);
    yVel = ofRandom(0.0, 1.0);
    
    pos.x = ofGetWindowWidth() / 2;
    pos.y = ofGetWindowHeight() / 2;
    
    ofSetRectMode( OF_RECTMODE_CENTER);
}

void Ball::update() {
    pos.x += xVel * 10.0;
    pos.y += yVel * 10.0;
    
    if ( pos.x < 0 || pos.x > ofGetWindowWidth()) {
        xVel *= -1.0;
    }
    
    if ( pos.y < 0 || pos.y > ofGetWindowHeight()) {
        yVel *= -1.0;
    }
}

void Ball::draw() {
    ofSetColor(240, 240, 20);
    ofCircle(pos.x, pos.y, 20);
}
