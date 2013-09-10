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
    
    initVel = 0.21;
    accel.y = 44094.48f / (ofGetFrameRate() * ofGetFrameRate()); //44,094 is 9.8m/s2 in px
    r = 10;
    
    pos.x = ofGetWindowWidth() / 2;
    pos.y = ofGetWindowHeight();
    
    ofVec2f mousePos;
    mousePos.x = ofGetMouseX();
    mousePos.y = ofGetMouseY();
    
    vel = (mousePos - pos) * initVel;
}

void Ball::setup(float gravity, float _initVel) {
    accel.y = gravity;
    initVel = _initVel;
}

void Ball::update() {
    vel += accel;
    pos += vel;
}

void Ball::draw() {
    ofEnableAlphaBlending();
    ofFill();
    ofSetColor( 255, 0, 0, 150 );
    ofCircle( pos, r);
    ofNoFill();
    ofSetLineWidth(1);
    ofSetColor(255, 0, 0);
    ofCircle(pos, r);
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
        
        vel.x *= 0.94;
    }
}

bool Ball::kill() {
    if (pos.y > ofGetWindowHeight()) {
        return true;
    }
    else return false;
}