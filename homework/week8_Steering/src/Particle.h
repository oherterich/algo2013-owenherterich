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
    Particle(ofImage *tmpImg);
    
    ofVec2f pos;
    ofVec2f vel;
    ofVec2f accel;
    float mass;
    
    ofVec2f dest;

    void applyForce( ofVec2f force );
    void addRepulsion( ofVec2f &fromPos );
    void update();
    void draw();
    
    void seek();
    
    float maxSpeed;
    float maxForce;
    float slowDownRadius;

    ofImage *img;
};