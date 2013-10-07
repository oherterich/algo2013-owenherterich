//
//  Card.cpp
//  week6_solitare
//
//  Created by Owen Herterich on 10/5/13.
//
//

#include "Card.h"

Card::Card( ofImage &tmpImg, ofVec2f _pos, ofVec2f _vel ) {
    img = &tmpImg;
    pos = _pos;
    vel = _vel;
    damping = 0.01;
    kill = false;
    scaleFactor = 1.0;
}

void Card::addForce( ofVec2f force ) {
    acc += force;
}

void Card::dampingForce() {
    acc.x = acc.x - vel.x * damping;
    acc.y = acc.y - vel.y * damping;
}

void Card::update() {
    vel += acc;
    pos += vel;
    
    if ( pos.x > ofGetWindowWidth() - (36 * scaleFactor) ) {
        vel.x = -vel.x;
        pos.x = ofGetWindowWidth() - (36 * scaleFactor);
    }
    
    if ( pos.x < (36 * scaleFactor) ) {
        vel.x = -vel.x;
        pos.x = (36 * scaleFactor);
    }
    
    if ( pos.y > ofGetWindowHeight() - (48 * scaleFactor) ) {
        vel.y = -vel.y;
        pos.y = ofGetWindowHeight() - (48 * scaleFactor);
        kill = true;
    }
    
    if ( pos.y < (48 * scaleFactor) ) {
        vel.y = -vel.y;
        pos.y = (48 * scaleFactor);
    }
    
    acc.set(0);
}

void Card::draw() {
    ofSetRectMode( OF_RECTMODE_CENTER );
    ofPushMatrix();{
        ofTranslate(pos.x, pos.y);
        ofScale(scaleFactor, scaleFactor);
        img->draw(0, 0);
    }ofPopMatrix();
}