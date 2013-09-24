//
//  InitParticle.cpp
//  week4_particles
//
//  Created by Owen Herterich on 9/21/13.
//
//

#include "InitParticle.h"

InitParticle::InitParticle() {
    pos.x = ofRandom(ofGetWindowWidth());
    pos.y = ofGetWindowHeight();
    vel.y = ofRandom(-25.0, -10.0);
    initVel = vel.y;
    
    c.setHsb(ofRandom(255), 255, 255);
    
    size = ofRandom(5.0, 10.0);
    
    rotation = ofRandom(-10.0, 10.0);
}

void InitParticle::update() {
    pos += vel;
    vel *= 0.96;
    rotation += rotation;
}

void InitParticle::draw() {
    ofSetRectMode(OF_RECTMODE_CENTER);
    ofPushMatrix();{
        ofTranslate(pos);
        ofRotate(rotation);
        ofSetColor(c, 150);
        ofRect(0, 0, size, size);
    }ofPopMatrix();
}

bool InitParticle::kill() {
    if (abs(vel.y) <= 3.0) {
        return true;
    }
    else {
        return false;
    }
}