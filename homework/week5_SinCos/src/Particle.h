//
//  Particle.h
//  week5_trig
//
//  Created by Owen Herterich on 9/28/13.
//
//

#pragma once

#include "ofMain.h"

class Particle {
public:
    Particle( float _sin, float _cos, float _velX, float _size );
    void update( float _sin, float _cos, float _velX, float _size );
    void draw();
    bool kill();
    
    ofVec2f pos;
    ofVec2f vel;
    
    float life;
    float age;
    
    float size;
    float sinChange;
    float cosChange;
    float theta;
    float amp;
    
};