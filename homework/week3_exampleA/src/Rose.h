//
//  Rose.h
//  week3_exampleA
//
//  Created by Owen Herterich on 9/13/13.
//
//

#pragma once

#include "ofMain.h"

class Rose {
  
public:
    Rose();
    void update();
    void draw();

    vector <ofVec3f> pointList;
    float amplitude;
    float angle;
    float petals;
    float scaleFactor;
    float rotateFactor;

    bool keepAdding;
    
    ofColor c;

};
