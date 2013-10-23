//
//  Particle.h
//  VectorField
//
//  Created by Charlie Whitney on 10/7/13.
//
//

#pragma once

#include "ofMain.h"

class Particle {
  public:
    Particle(ofTrueTypeFont *_type);
    
    ofVec2f pos;
    ofVec2f pPos;
    ofVec2f vel;
    ofVec2f accel;
    ofColor c;
    string letter;
    float theta;
    
    void applyForce( ofVec2f force );
    void addRepelForce( ofVec2f repelPos, float rad, float strength);
    void boundaries();
    void update();
    void draw();
    
    ofTrueTypeFont *type;
};