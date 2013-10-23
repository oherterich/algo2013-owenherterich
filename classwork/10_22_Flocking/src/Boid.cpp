//
//  Boid.cpp
//  10_22_Flocking
//
//  Created by Owen Herterich on 10/22/13.
//
//

#include "Boid.h"

Boid::Boid() {
    damping = ofRandom(0.96, 0.99);
}

void Boid::applyForce(ofVec3f force) {
    acc += force;
}

void Boid::pullToCenter(ofVec3f center) {
    ofVec3f dir = pos - center;
    float dist = dir.length();
    float maxDistance = 300.0;
    
    if (dist > maxDistance) {
        dir.normalize();
        vel -= dir * (dist / maxDistance) * 0.0001f;
    }
}

void Boid::update() {
    float minSpeed = 1.0;
    
    vel += acc;
    vel.limit(3.0);
    
    if (vel.lengthSquared() < minSpeed * minSpeed) {
        vel.normalized() * minSpeed;
    }
    
    pos += vel;
    vel *= damping;
    
    acc.set(0);
}

void Boid::draw() {
    ofSetColor(255);
    ofCircle(pos, 2);
    
    ofSetColor(255, 255, 0);
    ofLine(pos, pos-vel *5.0);
}