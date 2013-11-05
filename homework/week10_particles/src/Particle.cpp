//
//  Particle.cpp
//  week6_attractor
//
//  Created by Owen Herterich on 10/4/13.
//
//

#include "Particle.h"

Particle::Particle() {
    pos.set(ofRandomWidth(), ofRandomHeight());
    vel.set(ofRandom(-2.0, 2.0), ofRandom(-2.0, 2.0));
    
    size = 1;
    damping = 0.01f;
    
    noiseOffset.x = ofRandom(0, 1000);
    noiseOffset.x = ofRandom(0, 1000) + 1000;
    
    c.setHsb(ofRandom(255), 230, 230);
}

void Particle::applyForce( ofVec2f force ) {
    acc += force;
}

void Particle::attractForce(float px, float py, float radius, float strength) {
    ofVec2f loc;
    loc.set(px, py);
    
    ofVec2f diff;
    diff = pos - loc;
    
    if ( diff.length() < radius ) {
        float pct = 1 - ( diff.length() / radius );
        diff.normalize();
        acc.x -= diff.x * pct * strength;
        acc.y -= diff.y * pct * strength;
        
        acc.x = acc.x - vel.x * damping;
        acc.y = acc.y - vel.y * damping;
    }
}

void Particle::repulseForce(float px, float py, float radius, float strength) {
    ofVec2f loc;
    loc.set(px, py);
    
    ofVec2f diff;
    diff = pos - loc;
    
    if ( diff.length() < radius ) {
        float pct = 1 - ( diff.length() / radius );
        diff.normalize();
        acc.x += diff.x * pct * strength;
        acc.y += diff.y * pct * strength;
        
        acc.x = acc.x - vel.x * damping;
        acc.y = acc.y - vel.y * damping;
    }
}

void Particle::dampingForce() {
    acc.x = acc.x - vel.x * damping;
    acc.y = acc.y - vel.y * damping;
}



void Particle::update( float dt ) {
    vel += acc;
    pos += (vel * dt * 50.0);
    
    pos.x += dt * 50.0 * ofMap( ofNoise(ofGetElapsedTimef() + noiseOffset.x), 0.0, 1.0, -1.0, 1.0 );
    pos.y += dt * 50.0 * ofMap( ofNoise(ofGetElapsedTimef() + noiseOffset.y), 0.0, 1.0, -1.0, 1.0 );
    
    if ( pos.x > ofGetWindowWidth() - size ) {
        vel.x = -vel.x;
        pos.x = ofGetWindowWidth() - size;
    }
    
    if ( pos.x < size ) {
        vel.x = -vel.x;
        pos.x = size;
    }
    
    if ( pos.y > ofGetWindowHeight() - size ) {
        vel.y = -vel.y;
        pos.y = ofGetWindowHeight() - size;
    }
    
    if ( pos.y < size ) {
        vel.y = -vel.y;
        pos.y = size;
    }
    
    acc.set(0);
}

void Particle::draw() {
    ofSetColor( c );
    ofRect(pos, size, size);
}