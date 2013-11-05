//
//  Boid.cpp
//  week10_flocking
//
//  Created by Owen Herterich on 11/5/13.
//
//

#include "Boid.h"

Boid::Boid() {
    size = 10.0;
    c = ofColor(255);
    
    center.set( ofGetWindowWidth() / 2, ofGetWindowHeight() / 2 );
    centerRadius = 300;
    
    damping = ofRandom(0.96, 0.98);
    maxVel = ofRandom(3.0, 6.0);
}

void Boid::addForce( ofVec2f frc ) {
    acc += frc;
}

void Boid::pullToCenter() {
    ofVec2f diff = center - pos;
    
    if (diff.lengthSquared() > (centerRadius * centerRadius) ) {
        float pct = diff.lengthSquared() / (centerRadius * centerRadius);
        addForce( diff.normalized() * pct * 0.01 );
    }

}

void Boid::update() {
    
    vel += acc;
    pos += vel;
    
    vel.limit(maxVel);
    
    if (vel.lengthSquared() < 1.0) {
        vel = vel.normalized() * 1.0;
    }
    
    lSide = vel.rotated(-45);
    rSide = vel.rotated(45);
    
    vel *= damping;
    acc.set(0);
}

void Boid::draw() {
    
    ofSetColor( c );
    ofCircle(pos, size);
    
    ofSetColor( 255, 0, 0 );
    ofLine( pos, pos - vel*10.0);
    
    ofSetColor( 0, 255, 0 );
    ofLine( pos, (pos - vel*-10.0));
    
    ofSetColor(255,255,0);
    ofLine(pos, pos + lSide.normalized() * 25);
    ofLine(pos, pos + rSide.normalized() * 25);
}