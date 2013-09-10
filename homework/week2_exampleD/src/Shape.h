//
//  Shape.h
//  week2_exampleD
//
//  Created by Owen Herterich on 9/4/13.
//
//

#pragma once

#include "ofMain.h"

class Shape {
public:
    Shape();
    void update();
    void draw();
    void changeColor();

    ofVec3f pos;
    ofVec3f vel;

    float wall;
    float r;
    float c;
    
};
