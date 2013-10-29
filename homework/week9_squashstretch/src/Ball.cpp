//
//  Ball.cpp
//  week9_squashstretch
//
//  Created by Owen Herterich on 10/29/13.
//
//

#include "Ball.h"

Ball::Ball( ofImage *tmpAnimation ) {
    
    for (int i = 0; i < 12; i++) {
        imgs[i] = tmpAnimation[i];
    }
    
    pos.set(ofRandomWidth(), ofRandomHeight());
    vel.set(ofRandom(5, 10), ofRandom(1, 5));
    
    startFrame = ofRandom(11);
    frame = startFrame;
}

void Ball::update() {
    pVel = vel;
    
    vel += acc;
    pos += vel;
    
    acc.set(0);
    
    if (frame < 11) {
        frame++;
    }
    else {
        frame = 0;
    }
}

void Ball::addForce(ofVec2f frc) {
    acc += frc;
}

ofVec2f Ball::addSquashStretch() {
    
    float stretchX = ofMap(vel.x, 0, 30, 1.0, 1.3);
    float stretchY = ofMap(vel.y, 0, 30, 1.0, 1.3);

    
    ofVec2f amount;
    amount.set(stretchX, stretchY);
    
    return amount;
}

void Ball::addBoundaries() {
    if (pos.x > ofGetWindowWidth() - size / 2) {
        vel.x = -vel.x;
        pos.x = ofGetWindowWidth() - size / 2;
        vel.x *= 0.92;
    }
    
    if (pos.x < size / 2) {
        vel.x = -vel.x;
        pos.x = size / 2;
        vel.x *= 0.92;
    }
    
    if (pos.y > ofGetWindowHeight() - size / 2) {
        vel.y = -vel.y;
        pos.y = ofGetWindowHeight() - size / 2;
        vel.y *= 0.92;
    }
    
    if (pos.y < size / 2) {
        vel.y = -vel.y;
        pos.y = size / 2;
        vel.y *= 0.92;
    }
}

void Ball::draw() {
    ofSetColor( c );
    
    ofVec2f squash = addSquashStretch();
    
    ofPushMatrix();{
        ofTranslate(pos.x, pos.y);
        ofScale(squash.x, squash.y);
        imgs[frame].draw(0,0);
    }ofPopMatrix();
    
}