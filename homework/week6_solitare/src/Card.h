//
//  Card.h
//  week6_solitare
//
//  Created by Owen Herterich on 10/5/13.
//
//

#pragma once

#include "ofMain.h"

class Card {
public:
    Card( ofImage *tmpImg, ofVec2f _pos, ofVec2f _vel);
    void update();
    void draw();
    void addForce( ofVec2f force );
    void dampingForce();
    
    ofVec2f pos, vel, acc;
    
    float damping;
    float scaleFactor;
    
    ofImage *img;
    
    bool kill;
};
