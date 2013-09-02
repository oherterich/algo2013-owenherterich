//
//  line.cpp
//  emptyExample
//
//  Created by Owen Herterich on 8/27/13.
//  Copyright (c) 2013 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include "line.h"

Lines::Lines() {
    
}

void Lines::update() {
    c1.x += ofRandom(-2, 2);
    c1.y += ofRandom(-2, 2);
    c2.x += ofRandom(-2, 2);
    c2.y += ofRandom(-2, 2);
    
}

void Lines::draw() {
    ofEnableAlphaBlending();
    ofEnableSmoothing();
    ofSetLineWidth(2.0);
    
    ofSetColor(180, 50);
    ofEllipse(p1.x, p1.y, 10, 10);
    ofEllipse(p2.x, p2.y, 10, 10);
    
    ofSetColor(220, 50);
    ofBezier(p1.x, p1.y, c1.x, c1.y, c2.x, c2.y, p2.x, p2.y);
}
