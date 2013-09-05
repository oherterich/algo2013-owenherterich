//
//  Rectangle.h
//  09_03_multipleXeno
//
//  Created by Owen Herterich on 9/3/13.
//
//

#pragma once

#include "ofMain.h"

class Rectangle {
public:
    Rectangle();
    
    void xenoToPoint( float catchX, float catchY );
    void draw();
    
    ofPoint pos;
    ofPoint targetPos;
    
    float catchUpSpeed;
    float size;
    
};
