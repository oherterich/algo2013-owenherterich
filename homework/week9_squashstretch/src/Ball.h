//
//  Ball.h
//  week9_squashstretch
//
//  Created by Owen Herterich on 10/29/13.
//
//

#pragma once

#include "ofMain.h"

class Ball {
public:
    Ball( ofImage *tmpAnimation );
    void update();
    void draw();
    void addForce( ofVec2f frc );
    void addBoundaries();
    ofVec2f addSquashStretch();
    
    ofVec2f     pos, vel, pVel, acc;
    float       size;
    ofColor     c;
    ofImage     imgs[12];
    int         frame, startFrame;
};
