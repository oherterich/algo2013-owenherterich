//
//  Boid.h
//  10_22_Flocking
//
//  Created by Owen Herterich on 10/22/13.
//
//

#pragma once

#include "ofMain.h"

class Boid {
 public:
    Boid();
    
    void applyForce( ofVec3f force );
    void pullToCenter( ofVec3f center );
    
    void update();
    void draw();
    
    float damping;
    ofVec3f pos, vel, acc;
};