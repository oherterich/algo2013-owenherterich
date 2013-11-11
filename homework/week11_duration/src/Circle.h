//
//  Circle.h
//  week11_duration
//
//  Created by Owen Herterich on 11/10/13.
//
//

#pragma once

#include "ofMain.h"

class Circle {
public:
    Circle();
    void update();
    void draw();
    
    ofVec2f pos;
    float outerSize, innerSize;
    ofColor outerColor, innerColor;
};
