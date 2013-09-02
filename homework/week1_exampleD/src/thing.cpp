//
//  rectangle.cpp
//  08_27_rectangle
//
//  Created by Owen Herterich on 8/27/13.
//  Copyright (c) 2013 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include "thing.h"

Thing::Thing(){
    ofSetRectMode(OF_RECTMODE_CENTER);
    
    size = ofRandom(5.0f,10.0f);
    initSize = size;
    
    pos.x = ofGetWindowWidth() / 2;
    pos.y = ofGetWindowHeight() / 2;
    
    float randomStart = ofRandom(ofGetWindowWidth());
    
    posA.x = randomStart;
    posA.y = -size / 2;
    
    posB.x = randomStart;
    posB.y = ofGetWindowHeight() + size / 2;
    
    pct = 0.0f;
    powPct = ofRandom(1.2f, 2.0f);
    pctAdd = ofRandom(0.005f, 0.01f);
    pctGrow = 0.0f;
    cosPct = 1.0f;
    trigger = false;
    
}

void Thing::update() {

}

void Thing::draw() {
    ofEnableAlphaBlending();
    ofSetColor(220,220,245, 120);
    ofEllipse(pos.x, pos.y, size, size);
}

void Thing::interpolateByPct(float myPct, float rad) {
    
    pct = powf(myPct, powPct);
    size = powf(size, 1.001);
        
    pos.x = cos(rad)*cosPct+(1-pct) * posA.x + pct * posB.x;
    pos.y = (1-pct) * posA.y + pct * posB.y;
    
}

void Thing::horizontalMovement() {
    if (cosPct >= 30.0f) {
        trigger = false;
    }
    
    if (trigger) {
        cosPct += 0.2;
    }
    else if (!trigger && cosPct > 1.0f) {
        cosPct -= 0.2;
    }
}
