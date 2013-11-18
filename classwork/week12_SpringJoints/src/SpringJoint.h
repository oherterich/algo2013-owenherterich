//
//  SpringJoint.h
//  week12_SpringJoints
//
//  Created by Owen Herterich on 11/12/13.
//
//

#pragma once

#include "ofMain.h"

class SpringJoint {

public:
    SpringJoint();
    void update();
    void draw();
    void applyForce( ofVec2f force );
    
    ofVec2f pos, vel, acc;

};