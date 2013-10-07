//
//  Particle.cpp
//  week6_strangeAttractor
//
//  Created by Owen Herterich on 10/6/13.
//
//

#include "Particle.h"

Particle::Particle() {

}

void Particle::draw() {
    ofSetColor(255, 30);
    ofPushMatrix();{
        ofTranslate( ofGetWindowSize() / 2 );
        ofRect(pos, 1, 1);
    }ofPopMatrix();
}
