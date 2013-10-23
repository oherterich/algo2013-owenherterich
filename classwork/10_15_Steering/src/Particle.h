//
//  Particle.h
//  Forces
//
//  Created by Charlie Whitney on 9/30/13.
//
//

#pragma once

#include "ofMain.h"

class Particle {
  public:
    Particle();
    
    ofVec2f pos;
    ofVec2f vel;
    ofVec2f accel;
    float mass;

    void applyForce( ofVec2f force );
    void update();
    void draw();
    
    void seek( ofVec2f dest );
    
    float maxSpeed;
    float maxForce;
    float slowDownRadius;

};