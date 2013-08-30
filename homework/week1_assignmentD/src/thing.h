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


class Thing {
    
public:
    Thing();
    
    void update();
    void draw();
    
    void interpolateByPct(float myPct, float rad);
    void horizontalMovement();
    
    ofPoint pos;
    ofPoint posA, posB;
    
    float pct;
    float size;
    float initSize;
    float powPct;
    float pctAdd;
    float pctGrow;
    float cosPct;
    
    bool trigger;
    
};



