//
//  Particle.cpp
//  week4_particles
//
//  Created by Owen Herterich on 9/20/13.
//
//

#include "Particle.h"

void Particle::setup(ofVec2f _pos, float velMult, ofColor hue, float _size) {
    pos = _pos;
    vel.x = ofRandom(-velMult / 2.0, velMult / 2.0);
    vel.y = ofRandom(-velMult / 2.0, velMult / 2.0 + 1.0);
    accel.y = 0.2;
    
    size = ofRandom(_size - _size/5, _size + _size/5);
    age = 0;
    life = ofRandom(400, 500);
    
    c = hue;
}

void Particle::update() {
    
    float pct = 1.0 - (float)age / (float)life;
    size = pct * size;
    
    float noise = ofNoise(pos.x * 0.01, pos.y * 0.01, ofGetElapsedTimef() * 0.1) * 10.0;
    pos += ofVec3f( cos(noise), sin(noise)) * 1.0-pct;
    
    vel += accel;
    pos += vel;
    vel *= 0.98;
    
    age++;
}

void Particle::draw() {
    ofSetRectMode(OF_RECTMODE_CENTER);
    ofPushMatrix();{
        ofTranslate(pos.x, pos.y);
        ofRotate(ofGetElapsedTimeMillis());
        ofSetColor(c, 150);
        ofRect(0, 0, size, size);
    }ofPopMatrix();
}

bool Particle::kill(){
    if ( age >= life ) {
        return true;
    }
    else {
        return false;
    }
}