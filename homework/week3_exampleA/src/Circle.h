//
//  Circle.h
//  week3_exampleA
//
//  Created by Owen Herterich on 9/13/13.
//
//

#pragma once

#include "ofMain.h"

class Circle {
public:
    Circle();
    void setup(ofVec3f _pt, float _amplitude);
    void update();
    void draw();
    
    ofVec3f pt;
    float amplitude;
    float ampA;
    float ampB;
    float pct;
    float shaper;
    float opacity;
};
