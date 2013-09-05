//
//  Ball.cpp
//  week2_exampleC
//
//  Created by Owen Herterich on 9/4/13.
//
//

#include "Ball.h"

Ball::Ball() {
    ofSetRectMode( OF_RECTMODE_CENTER );
    
    initVel = 0.06;
    //accel.y = 70,551.18 / ofGetFrameRate(); //70,551 is 9.8m/s2 in px
    accel.y = 1.2;
    r = 25;
    
    pos.x = ofGetWindowWidth() / 2;
    pos.y = ofGetWindowHeight();
    
    ofVec2f mousePos;
    mousePos.x = ofGetMouseX();
    mousePos.y = ofGetMouseY();
    
    vel = (mousePos - pos) * initVel;
    //vel = vel.normalize() * initVel;
}

void Ball::update() {
    vel += accel;
    pos += vel;
}

void Ball::draw() {
    ofSetColor( 255, 0, 0 );
    ofCircle( pos, r);
}

void Ball::wallCollide() {
    if (pos.x < r/2) {
        pos.x = r/2;
        vel.x *= -0.9;
    }
    
    if (pos.x > ofGetWindowWidth()-r/2) {
        pos.x = ofGetWindowWidth() - r/2;
        vel.x *= -0.9;
    }
    
    if (pos.y < r/2) {
        pos.y = r/2;
        vel.y *= -0.9;
        
        vel.x *= 0.9;
    }
    
    if (pos.y > ofGetWindowHeight()-r/2) {
        pos.y = ofGetWindowHeight() - r/2;
        vel.y *= -0.9;
        
        vel.x *= 0.97;
    }
}

bool Ball::kill() {
    if (pos.y > ofGetWindowHeight()) {
        return true;
    }
    else return false;
}