//
//  thing.cpp
//  week1_assignmentA
//
//  Created by Owen Herterich on 8/27/13.
//  Copyright (c) 2013 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include "thing.h"

Thing::Thing() {
    ofSetRectMode(OF_RECTMODE_CENTER);
}

void Thing::update() {
    pos.x += speed;
}

void Thing::draw() {
    ofSetColor(255,0,0);
    ofRect(pos.x, pos.y, w, w);
}