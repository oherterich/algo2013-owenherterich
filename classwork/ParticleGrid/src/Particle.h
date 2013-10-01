//
//  Particle.h
//  ParticleGrid
//
//  Created by Owen Herterich on 9/24/13.
//
//

#pragma once

#include "ofMain.h"

class Particle {
public:
    Particle( ofVec2f position );
    void draw();
    void update( const ofImage &img);

    ofVec2f pos;
    float radius;
    float grayValue;
};
