//
//  Particle.h
//  week5_pictureparticles
//
//  Created by Owen Herterich on 9/29/13.
//
//

#pragma once

#include "ofMain.h"

class Particle {
public:
    Particle( ofImage _img, ofVec2f _pos);
    void update( ofVec2f wind );
    void draw();
    bool kill();
    
    ofVec2f pos;
    ofVec2f vel;
    ofVec2f accel;
    
    ofImage img;
    
    float theta;
    float thetaMod;
    float scale;
};
