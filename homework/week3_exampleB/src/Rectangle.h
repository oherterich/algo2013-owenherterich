//
//  Rectangle.h
//  week3_exampleB
//
//  Created by Owen Herterich on 9/16/13.
//
//

#pragma once

#include "ofMain.h"

class Rectangle{
public:
    Rectangle();
    void update();
    void draw();
    bool dead();
    
    ofVec3f pos;
    ofVec3f vel;
    float width;
    float height;
};
