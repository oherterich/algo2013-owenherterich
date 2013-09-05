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
    void draw();
    
    ofVec2f pos, mousePos;
    ofVec2f accel, vel;
};
