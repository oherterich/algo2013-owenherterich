//
//  Mover.h
//  09_03_accelerationExample
//
//  Created by Owen Herterich on 9/3/13.
//
//

#pragma once

#include "ofMain.h"

class Mover {
public:
    Mover();
    
    void update();
    void draw( ofColor c);
    void wallCollision();
    void xenoToPoint(ofVec2f catchPos);
    
    ofVec2f pos, mousePos;
    ofVec2f accel, vel;
    
    bool dragged;
    bool leader;
    
    float r;
    float catchUpSpeed;
};
