//
//  Boid.h
//  week10_flocking
//
//  Created by Owen Herterich on 11/5/13.
//
//

#pragma once

#include "ofMain.h"

class Boid {
public:
    Boid();
    void update();
    void draw();
    void addForce( ofVec2f frc );
    void pullToCenter();
    
    ofVec2f     pos, vel, acc;
    ofVec2f     lSide, rSide;
    ofVec2f     center;
    ofColor     c;
    float       size, centerRadius, damping, maxVel;
};
