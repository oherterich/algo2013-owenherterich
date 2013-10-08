//
//  InitParticle.cpp
//  week4_particles
//
//  Created by Owen Herterich on 9/21/13.
//
//

#include "InitParticle.h"

InitParticle::InitParticle(float velA, float velB, float _size, ofColor _hue) {
    pos.x = ofRandom(ofGetWindowWidth());
    pos.y = ofGetWindowHeight();
    vel.y = ofRandom(-velB, -velA);
    initVel = vel.y;
    
    c = _hue;
    
    size = ofRandom(_size - _size/4, _size + _size/4);
    
    rotation = ofRandom(-10.0, 10.0);
}

void InitParticle::update() {
    float noise = ofNoise(pos.x * 0.01, pos.y * 0.01, ofGetElapsedTimef() * 0.1) * 10.0;
    pos += ofVec3f( cos(noise), sin(noise));
    
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