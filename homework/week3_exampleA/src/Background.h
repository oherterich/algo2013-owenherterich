//
//  Background.h
//  week3_exampleA
//
//  Created by Owen Herterich on 9/13/13.
//
//

#pragma once

#include "ofMain.h"

class Background {
public:
    Background();
    void update();
    void draw();

    vector <ofPoint> pointList;
    vector <float> brightness;
};
