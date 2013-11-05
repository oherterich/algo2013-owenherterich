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
}

void Particle::applyForce(ofVec2f force){
    accel += (force / mass);
}

void Particle::update( float dt ){
    vel += accel;
    pos += ( vel * dt );
    
    if (pos.x < 0 || pos.x > ofGetWindowWidth()) {
        vel.x = -vel.x;
    }

    if (pos.y < 0 || pos.y > ofGetWindowHeight()) {
        vel.y = -vel.y;
    }
    
    accel.set(0);
}

void Particle::draw() {
    ofSetColor(255, 200);
    ofCircle(pos, 3);
}