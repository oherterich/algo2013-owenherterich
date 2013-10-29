//
//  Circle.h
//  week9_animation
//
//  Created by Owen Herterich on 10/28/13.
//
//

#pragma once

#include "ofMain.h"

class Circle {
public:
    Circle( float _size, float _offset );
    void update();
    void draw();
    bool changeColor();
    
    ofVec2f     pos;
    float       size, initSize;
    float       offset;
    float       numTri, sizeTri;
    float       amplitude;
    ofColor     c;
};
