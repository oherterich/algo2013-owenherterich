//
//  Mover.cpp
//  week6_attractor
//
//  Created by Owen Herterich on 10/5/13.
//
//

#include "Mover.h"

Mover::Mover() {
    
    rAttract = 300.0;
    rRepulse = 50.0;
    sAttract = 0.2;
    sRepulse = 15.0;
    initRepulse = rRepulse;
    repulseSwitch = true;
    
    pos.set(ofRandomWidth(), ofRandomHeight());
    vel.set(ofRandom(1.0, 2.0) * 2.0, ofRandom(1.0, 2.0) * 2.0);
    
}

void Mover::update() {
    
    pos += vel;
    
    if (pos.x > ofGetWindowWidth() - rRepulse / 2) {
        vel.x = -vel.x;
    }
    
    if (pos.x < rRepulse / 2) {
        vel.x = -vel.x;
    }
    
    if (pos.y > ofGetWindowHeight() - rRepulse / 2) {
        vel.y = -vel.y;
    }
    
    if (pos.y < rRepulse / 2) {
        vel.y = -vel.y;
    }

}

void Mover::switchForces() {
    if (repulseSwitch) {
        rRepulse = 0;
        repulseSwitch = !repulseSwitch;
    }
    else {
        rRepulse = initRepulse;
        repulseSwitch = !repulseSwitch;
    }
}