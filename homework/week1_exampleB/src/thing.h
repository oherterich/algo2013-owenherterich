//
//  thing.h
//  week1_assignmentA
//
//  Created by Owen Herterich on 8/27/13.
//  Copyright (c) 2013 __MyCompanyName__. All rights reserved.
//

#pragma once
#include "ofMain.h"

class Thing {
public:
    Thing();
    
    void update();
    void draw();
    
    ofPoint pos;
    int w;
    float speed;
};
