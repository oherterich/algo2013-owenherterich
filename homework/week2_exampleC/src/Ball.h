//
//  Ball.h
//  week2_exampleC
//
//  Created by Owen Herterich on 9/4/13.
//
//

#pragma once

#include "ofMain.h"

class Ball {
public:
    Ball();
    void update();
    void draw();
    void wallCollide();
    void setup(float gravity, float initVel);
    
    bool kill();
    
    ofVec2f pos;
    ofVec2f vel;
    ofVec2f accel;
    
    float initVel;
    float r;
    float gravity;
};
