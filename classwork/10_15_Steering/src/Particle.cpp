//
//  Particle.cpp
//  Forces
//
//  Created by Charlie Whitney on 9/30/13.
//
//

#include "Particle.h"

Particle::Particle() {
    mass = 1.0;
    pos = ofGetWindowSize() / 2.0;
    
    maxSpeed = 10.0;
    maxForce = 0.4;
    slowDownRadius = 200.0;
}

void Particle::applyForce(ofVec2f force){
    accel += force;
    //accel += (force / mass);
}

void Particle::update(){
    vel += accel;
    pos += vel;

    accel.set(0);
}

void Particle::seek( ofVec2f dest ) {
    ofVec2f desired = dest - pos;
    
    if ( desired.length() < slowDownRadius ) {
        float newMag = ofMap( desired.length(), 0, slowDownRadius, 0, maxSpeed);
        desired.normalize();
        desired *= newMag;
    }
    else {
    desired.normalize();
    desired *= maxSpeed;
    }
    

    
    ofVec2f steer = desired - vel;
    steer.limit( maxForce );
    
    applyForce( steer );
    
}

void Particle::draw() {
    ofSetRectMode(OF_RECTMODE_CENTER);
    ofSetColor( 255, 150);
    ofPushMatrix();
    ofTranslate(pos);
    float rotAmt = atan2(vel.y, vel.x);
    ofRotate( ofRadToDeg( rotAmt ) + 90 );
    ofRect(0, 0, 20, 40);
    ofPopMatrix();
}