//
//  line.h
//  emptyExample
//
//  Created by Owen Herterich on 8/27/13.
//  Copyright (c) 2013 __MyCompanyName__. All rights reserved.
//

#pragma once
#include "ofMain.h"

class Lines {
  
public:
    Lines();
    void update();
    void draw();
    
    ofPoint p1;
    ofPoint p2;
    ofPoint c1;
    ofPoint c2;
    bool whichPoint;
    
};
