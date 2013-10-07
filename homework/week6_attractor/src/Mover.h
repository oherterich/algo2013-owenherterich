//
//  Mover.h
//  week6_attractor
//
//  Created by Owen Herterich on 10/5/13.
//
//

#pragma once

#include "ofMain.h"

class Mover {
public:
    Mover();
    void update();
    void switchForces();
    
    ofVec2f pos, vel;
    float rAttract, rRepulse;
    float initRepulse;
    float sAttract, sRepulse;
    
    bool repulseSwitch;
};
