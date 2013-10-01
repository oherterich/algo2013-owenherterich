//
//  Particle.cpp
//  week5_trig
//
//  Created by Owen Herterich on 9/28/13.
//
//

#include "Particle.h"

Particle::Particle( float _sin, float _cos, float _velX, float _size ) {
    pos.set(0, 0);
    sinChange = _sin;
    cosChange = _cos;
    amp = _velX;
    
    life = 500.0;
    age = 0.0;
    
    vel.y = sin( sinChange ) + cos ( cosChange );
    size = _size;
    theta = 0.0;
}

void Particle::update( float _sin, float _cos, float _velX, float _size) {
    sinChange = _sin;
    cosChange = _cos;
    amp = _velX;
    
    vel.x = cos( cosChange * theta ) * amp;
    vel.y = sin( sinChange * theta ) * amp;
    pos += vel;
    size = _size;
    theta += 0.01;
    age++;
}

void Particle::draw() {
    ofPushMatrix();{
        ofTranslate(ofGetWindowWidth() / 2, ofGetWindowHeight() / 2);
        ofSetColor(200, 150);
        ofCircle(pos, size);
    }ofPopMatrix();
}

bool Particle::kill() {
    if (age >= life) {
        return true;
    }
    else return false;
}