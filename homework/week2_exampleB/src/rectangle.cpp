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
    ofSetCircleResolution(24);
    
    pos = ofGetWindowSize();
    
    catchUpSpeed = 0.2;
    
    c = 240;
    
    size = 30;
    
    randomLength = ofRandom(150);
    
}

void Rectangle::update() {
    randomLength = ofRandom(150);
}

void Rectangle::draw() {
    ofEnableAlphaBlending();
    //ofNoFill();
    ofSetLineWidth(5);
    ofSetColor(c, c, c, 100);
    ofLine(pos.x + randomLength, pos.y, pos.x - randomLength, pos.y);
}

void Rectangle::xenoToPoint(float catchX, float catchY) {
    
    pos.x = catchUpSpeed * catchX + ( 1 - catchUpSpeed) * pos.x;
    pos.y = catchUpSpeed * catchY + ( 1 - catchUpSpeed) * pos.y;
    
}
