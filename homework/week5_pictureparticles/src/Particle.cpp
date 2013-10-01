//
//  Particle.cpp
//  week5_pictureparticles
//
//  Created by Owen Herterich on 9/29/13.
//
//

#include "Particle.h"

Particle::Particle( ofImage _img, ofVec2f _pos ) {
    img = _img;
    pos = _pos;
    theta = ofRandom(360);
    thetaMod = ofRandom( -0.1, 0.1 );
    
    scale = ofRandom( 0.8, 1.2 );

}

void Particle::update( ofVec2f wind ) {
    thetaMod = thetaMod + 0.01 * vel.x;
    theta += thetaMod;
    
    wind.x *= ofRandom( 0.5, 2 );
    wind.y *= ofRandom( 0.5, 2 );
    
    accel += wind;
    vel += accel;
    pos += vel;
    
    accel *= 0.9;
}

void Particle::draw() {
    ofPushMatrix();{
        ofTranslate(pos);
        ofRotate(theta);
        ofScale(scale, scale);
        ofSetColor(255);
        img.setAnchorPercent(0.5, 1.0);
        img.draw(0,0);
    }ofPopMatrix();
}

bool Particle::kill() {
    if ( pos.x > ofGetWindowWidth()+100 || pos.x < -100 || pos.y > ofGetWindowHeight()+100 || pos.y < -100) {
        return true;
    }
    else return false;
}