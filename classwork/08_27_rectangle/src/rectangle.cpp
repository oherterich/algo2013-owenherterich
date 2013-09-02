//
//  rectangle.cpp
//  08_27_rectangle
//
//  Created by Owen Herterich on 8/27/13.
//  Copyright (c) 2013 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include "rectangle.h"

Rectangle::Rectangle(){
    ofSetRectMode(OF_RECTMODE_CENTER);
    
}

void Rectangle::update() {
    //pos.x = pos.x + ofRandom(-1,1);
    //pos.y = pos.y + ofRandom(-1,1);
}

void Rectangle::draw() {
    ofEnableAlphaBlending();
    ofSetColor(0,255,0, 255);
    ofRect(pos.x, pos.y, 50, 50);
}

void Rectangle::interpolateByPct(float myPct) {
//    pct = myPct;
    
    pct = powf(myPct, .5);
    
    pos.x = (1-pct) * posA.x + pct * posB.x;
    pos.y = (1-pct) * posA.y + pct * posB.y;

}

void Rectangle::xenoToPoint(float catchX, float catchY) {
    float catchUpSpeed = 0.07f;
    
    pos.x = catchUpSpeed * catchX + ( 1 - catchUpSpeed) * pos.x;
    pos.y = catchUpSpeed * catchY + ( 1 - catchUpSpeed) * pos.y;

}
