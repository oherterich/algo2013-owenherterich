//
//  Particle.cpp
//  Forces
//
//  Created by Charlie Whitney on 9/30/13.
//
//

#include "Particle.h"

Particle::Particle(ofTrueTypeFont *_type) {
    type = _type;
}

void Particle::applyForce(ofVec2f force){
    accel += force;
}

void Particle::addRepelForce(ofVec2f repelPos, float radius, float strength) {
    ofVec2f diff = pos - repelPos;
    
    if (diff.lengthSquared() < radius * radius) {
        float pct = 1.0 - diff.lengthSquared() / (radius * radius);
        diff.normalize();
        pos.x += diff.x * radius * strength;
        pos.y += diff.y * radius * strength;
    }
}

void Particle::boundaries() {
    if (pos.x < 0) {
        pos.x = ofGetWindowWidth();
    }
    
    if (pos.x > ofGetWindowWidth()) {
        pos.x = 0;
    }
    
    if (pos.y < 0) {
        pos.y = ofGetWindowHeight();
    }
    
    if (pos.y > ofGetWindowHeight()) {
        pos.y = 0;
    }
}

void Particle::update(){
    
    pPos = pos;
    
    vel += accel;
    pos += vel;
    
    vel*= 0.97;
    
    accel.set(0);
    
    ofVec2f diff = (pos - pPos);
    theta = atan2(diff.y, diff.x);
}

void Particle::draw() {
    ofSetColor(255);
    ofPushMatrix(); {
        ofTranslate(pos);
        //ofRotate(ofRadToDeg(theta));
        type->drawString(letter, 0, 0);
    }ofPopMatrix();
}