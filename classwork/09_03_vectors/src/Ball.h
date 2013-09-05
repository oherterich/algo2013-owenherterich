//
//  Ball.h
//  09_03_vectors
//
//  Created by Owen Herterich on 9/3/13.
//
//

#pragma once

#include "ofMain.h"

class Ball {
public:
    Ball();
    
    void update();
    void draw();
    
    ofVec2f pos;
    float xVel;
    float yVel;
};
