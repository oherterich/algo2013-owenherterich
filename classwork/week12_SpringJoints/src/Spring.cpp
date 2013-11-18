//
//  Spring.cpp
//  week12_SpringJoints
//
//  Created by Owen Herterich on 11/12/13.
//
//

#include "Spring.h"

Spring::Spring(){
    
}

void Spring::set( SpringJoint *_s1, SpringJoint *_s2, float _k, float _restLength){
    s1 = _s1;
    s2 = _s2;
    k = _k;
    restLength = _restLength;
}

void Spring::update(){
    ofVec2f force = s1->pos - s2->pos;
    float length = force.length();
    float stretchLength = length - restLength;
    
    force.normalize();
    force *= -1 * k * stretchLength;
    
    s1->applyForce( force );
    s2->applyForce( -force );
}

void Spring::draw(){
    ofSetColor( 220 );
    ofLine( s1->pos, s2->pos );
}