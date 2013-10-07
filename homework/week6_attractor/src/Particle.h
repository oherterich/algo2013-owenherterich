//
//  Particle.h
//  week6_attractor
//
//  Created by Owen Herterich on 10/4/13.
//
//

#pragma once

#include "ofMain.h"

class Particle {
public:
    Particle();
    void update();
    void draw();
    void applyForce( ofVec2f force );
    void attractForce ( float px, float py, float radius, float strength );
    void repulseForce ( float px, float py, float radius, float strength );
    void dampingForce();
    
    ofVec2f pos, vel, acc;
    ofVec2f noiseOffset;
    float size;
    float damping;
    ofColor c;
};
