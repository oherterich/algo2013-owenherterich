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
    
    pos.x = ofRandom(ofGetWindowWidth());
    pos.y = ofRandom(ofGetWindowHeight());
    
    catchUpSpeed = 0.2;
    
    c = 240;
    
    size = 50;
    
}

void Rectangle::update() {
    
}

void Rectangle::draw() {
    ofEnableAlphaBlending();
    ofSetColor(c,100);
    ofRect(pos.x, pos.y, size, size);
}

void Rectangle::xenoToPoint(float catchX, float catchY) {
    
    pos.x = catchUpSpeed * catchX + ( 1 - catchUpSpeed) * pos.x;
    pos.y = catchUpSpeed * catchY + ( 1 - catchUpSpeed) * pos.y;
    
}
