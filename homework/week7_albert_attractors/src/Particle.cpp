//
//  Particle.cpp
//  wk6_attractorRepulsor
//
//  Created by TheAlkimist on 10/5/13.
//
//

#include "Particle.h"
#include "ofMain.h"

Particle::Particle(){
    setInitCondition(ofGetWindowWidth()/2, ofGetWindowHeight()/2, 0, 0);
    damping = 0.09f;
    size = 10.0;
    r = ofRandom(230,250);
    g = ofRandom(210,230);
    b = ofRandom(140,160);
    
}

void Particle::resetForce(){
    force.set(0,0);
}

void Particle::addDamping(){
    force.x = force.x - vel.x * damping;
    force.y = force.y - vel.y * damping;
}

void Particle::addRepulsion( float px, float py, float radius, float strength ){
    
    ofVec2f posOfForce;             // vector position of force
    posOfForce.set(px,py);          // initialize
    
    ofVec2f diff = pos - posOfForce;    // difference
    
    if (diff.length() < radius){
        float percent = 1 - (diff.length() / radius );
        diff.normalize();
        force.x += diff.x * percent * strength;
        force.y += diff.y * percent * strength;
    }
}

void Particle::addAttraction( float px, float py, float radius, float strength ){
    
    ofVec2f posOfForce;
    posOfForce.set(px,py);
    
    ofVec2f diff = pos - posOfForce;
    
    if (diff.length() < radius){
        float percent = 1 - (diff.length() / radius );
        diff.normalize();
        force.x -= diff.x * percent * strength;
        force.y -= diff.y * percent * strength;
    }
}

void Particle::addBoundaries() {
    if (pos.x > ofGetWindowWidth() - size / 2) {
        vel.x = -vel.x;
        pos.x = ofGetWindowWidth() - size / 2;
    }
    
    if (pos.x < size / 2) {
        vel.x = -vel.x;
        pos.x = size / 2;
    }
    
    if (pos.y > ofGetWindowHeight() - size / 2) {
        vel.y = -vel.y;
        pos.y = ofGetWindowHeight() - size / 2;
    }
    
    if (pos.y < size / 2) {
        vel.y = -vel.y;
        pos.y = size / 2;
    }
}

void Particle::trail(float catchX, float catchY){
 
    float catchUpSpeed = 0.1f;
    pos.x = catchUpSpeed * catchX + (1-catchUpSpeed) * pos.x;
	pos.y = catchUpSpeed * catchY + (1-catchUpSpeed) * pos.y;
}

void Particle::setInitCondition( float px, float py, float vx, float vy ){
    pos.set(px,py);
    vel.set(vx,vy);
}

void Particle::update(){
    vel += force;
    pos += vel;
}

void Particle::draw(){
    ofSetColor(r, g, b);
    ofFill();
    ofCircle(pos.x, pos.y, size);
}