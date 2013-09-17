//
//  Creature.h
//  week3_exampleD
//
//  Created by Owen Herterich on 9/15/13.
//
//

#pragma once

#include "ofMain.h"

class Creature {
  
public:
    Creature();
    void update();
    void draw();
    void drawEye();
    void drawEyebrow();
    void drawArms();
    void drawMouth();
    void xenoToPoint(float catchX, float catchY);
    bool kill();
    
    ofVec2f pos;
    ofVec2f mousePos;
    ofVec2f diff;
    ofVec2f vel;
    float r;
    float d;
    float angle;
    float catchUpSpeed;
    float breatheOffset;
    float mouthOffset;
    ofColor c;
    
};
