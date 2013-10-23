//
//  Particle.cpp
//  Forces
//
//  Created by Charlie Whitney on 9/30/13.
//
//

#include "Particle.h"

Particle::Particle() {
    mass = 1.0;
    size = 2.0;
}

void Particle::applyForce(ofVec2f force){
    accel += (force / mass);
}

void Particle::boundaries() {
    if (pos.x < 0) {
        pos.x = ofGetWindowWidth();
    }
    
    if (pos.x > ofGetWindowWidth()) {
        pos.x = 0;
    }
    
    if (pos.y < 0) {
        pos.y = ofGetWindowHeight();
    }
    
    if (pos.y > ofGetWindowHeight()) {
        pos.y = 0;
    }
}

void Particle::update(){
    vel += accel;
    pos += vel;
    
    vel*= 0.97;
    
    accel.set(0);
}

void Particle::draw() {
    c.setHsb( ofMap( pos.y, 0, ofGetWindowHeight(), 30, 80 ), ofMap( pos.x, 0, ofGetWindowWidth(), 120, 180), 200 );
    ofSetColor(c);
    ofCircle( pos, size );
}