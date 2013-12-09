//
//  LargeShape.h
//  Final_Snake
//
//  Created by Owen Herterich on 12/9/13.
//
//

#pragma once

#include "ofMain.h"

class LargeShape {
    public:
    LargeShape( int _shape );
    void update();
    void draw();
    void addForce( ofVec2f force );
    void screenBoundaryCheck();
    
    void drawTriangle();
    void drawSquare();
    
    ofVec2f pos, vel, acc;
    
    float rotation, scale;
    float rotationSpeed;
    float trans;
    
    int shape; // 0 (tri), 1 (sq)
    
    ofColor c;
};
