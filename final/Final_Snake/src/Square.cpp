//
//  Square.cpp
//  Final_Snake
//
//  Created by Owen Herterich on 12/5/13.
//
//

#include "Square.h"

Square::Square( ofVec2f _pos, int hue ) {
    pos = _pos;
    vel.set(ofRandom(-6, 6), ofRandom(-6, 6));
    
    size = ofRandom(1, 3);
    age = 0;
    life = ofRandom(30, 70);
    
    damping = ofRandom(0.95, 0.99);
    
    c.setHsb(ofRandom(hue-20, hue+20), 230, 255);
    trans = 255;
    initTrans = 255;
}

void Square::addForce( ofVec2f force ) {
    acc += force;
}

void Square::update() {
    float pct = age / life;
    trans = initTrans * (1.0 - pct);
    
    float noise = ofNoise(pos.x * 0.005, pos.y*0.005, ofGetElapsedTimef() * 0.1) * ofRandom(5, 15);
    
    vel += acc;
    pos += vel;
    pos += ofVec2f( cos(noise), sin(noise) ) * (1.0-pct);
    
    vel *= damping;
    acc.set(0);

    age++;
}

void Square::draw() {
    ofSetColor(c, trans);
    ofRect( pos, size, size);
}

bool Square::kill() {
    if (age >= life) {
        return true;
    }
    else {
        return false;
    }
}