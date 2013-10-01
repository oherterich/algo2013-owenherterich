//
//  Particle.h
//  week4_particles
//
//  Created by Owen Herterich on 9/20/13.
//
//

#pragma once

#include "ofMain.h"

class Particle {
public:
    void setup(ofVec2f _pos, float velMult, ofColor hue, float _size);
    void update();
    void draw();
    bool kill();
    
    ofVec2f pos;
    ofVec2f vel;
    ofVec2f accel;
    
    float size;
    float age;
    float life;
    ofColor c;
};
