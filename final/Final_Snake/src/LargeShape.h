//
//  LargeShape.h
//  Final_Snake
//
//  Created by Owen Herterich on 12/9/13.
//
//

#pragma once

#include "ofMain.h"

class LargeShape {
    public:
    LargeShape();
    void update();
    void draw();
    void addForce( ofVec2f force );
    
    ofVec2f pos, vel, acc;
    
    float rotation, scale;
    float trans;
    
    ofColor c;
};
