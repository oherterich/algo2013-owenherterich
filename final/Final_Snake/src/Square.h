//
//  Square.h
//  Final_Snake
//
//  Created by Owen Herterich on 12/5/13.
//
//

#pragma once

#include "ofMain.h"

class Square {
    public:
        Square( ofVec2f _pos, int hue );
        void update();
        void draw();
        void addForce( ofVec2f force );
        bool kill();
    
        ofVec2f pos, vel, acc;
    
        float size;
        float age, life;
        float theta;
        float damping;
    
        ofColor c;
        float trans;
        float initTrans;
};
