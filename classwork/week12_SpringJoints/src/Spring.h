//
//  Spring.h
//  week12_SpringJoints
//
//  Created by Owen Herterich on 11/12/13.
//
//

#pragma once

#include "ofMain.h"
#include "SpringJoint.h"

class Spring {
public:
    Spring();
    
    void set( SpringJoint *_s1, SpringJoint *_s2, float _k, float _restLength);
    void update();
    void draw();
    
    SpringJoint *s1, *s2;
    float       k, restLength;
};