//
//  rectangle.h
//  08_27_rectangle
//
//  Created by Owen Herterich on 8/27/13.
//  Copyright (c) 2013 __MyCompanyName__. All rights reserved.
//

#ifndef _8_27_rectangle_rectangle_h
#define _8_27_rectangle_rectangle_h
#pragma once
#endif

#include "ofMain.h"


class Rectangle {
    
public:
    Rectangle();
    
    void update();
    void draw();
    
    void xenoToPoint(float catchX, float catchY);
    
    ofVec2f pos;
    
    float catchUpSpeed;
    float size; 
    
    ofColor c;
    
};



