//
//  SpringJoint.cpp
//  week12_SpringJoints
//
//  Created by Owen Herterich on 11/12/13.
//
//

#include "SpringJoint.h"

SpringJoint::SpringJoint(){
    
}

void SpringJoint::applyForce( ofVec2f force ){
    acc += force;
}

void SpringJoint::update(){
    vel += acc;
    pos += vel;
    
    vel *= 0.95;
    
    acc.set(0);

}

void SpringJoint::draw(){
    ofSetColor(255,255,0);
    ofCircle( pos, 10 );
}