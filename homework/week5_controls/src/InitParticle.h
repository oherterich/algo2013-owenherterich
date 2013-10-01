//
//  InitParticle.h
//  week4_particles
//
//  Created by Owen Herterich on 9/21/13.
//
//

#pragma once
#include "ofMain.h"

class InitParticle {
public:
    InitParticle(float velA, float velB, float _size, ofColor _hue);
    void update();
    void draw();
    bool kill();
    
    ofVec2f pos;
    ofVec2f vel;
    ofColor c;
    float size;
    float initVel;
    float rotation;
};
