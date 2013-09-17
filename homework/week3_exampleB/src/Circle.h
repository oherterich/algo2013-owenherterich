//
//  Circle.h
//  week3_exampleB
//
//  Created by Owen Herterich on 9/16/13.
//
//

#pragma once

#include "ofMain.h"

class Circle {
public:
    Circle();
    void update();
    void draw(float hue);

ofPoint pos;
float size;
ofColor c;
float opacity;
};
