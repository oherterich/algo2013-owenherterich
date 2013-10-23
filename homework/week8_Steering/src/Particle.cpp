//
//  Particle.cpp
//  Forces
//
//  Created by Charlie Whitney on 9/30/13.
//
//

#include "Particle.h"

Particle::Particle(ofImage *tmpImg) {
    mass = 1.0;
    pos = ofGetWindowSize() / 2.0;
    
    maxSpeed = 3.0;
    maxForce = 0.4;
    slowDownRadius = 100.0;
    
    img = tmpImg;
}

void Particle::applyForce(ofVec2f force){
    accel += force;
    //accel += (force / mass);
    
    accel.limit(5.0);
}

void Particle::update(){
    vel += accel;
    pos += vel;

    accel.set(0);
}

void Particle::addRepulsion(ofVec2f &fromPos) {
    ofVec2f diff = pos - fromPos;
    
    float strength = 1.0 - ( diff.lengthSquared() / (100.0 * 100.0) );
    
    applyForce( diff.normalized() * strength );
}

void Particle::seek() {
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
    ofSetColor( 255, 255);
    ofPushMatrix();
    ofTranslate(pos);
    float rotAmt = atan2(vel.y, vel.x);
    ofRotate( ofRadToDeg( rotAmt ) + 90 );
    img->draw(0,0);
    //ofRect(0, 0, 20, 40);
    ofPopMatrix();
//    
//    ofSetColor(255, 255, 0);
//    ofCircle( dest, 5 );
}