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
    catchUpSpeed = ofRandom(.01f, .03f);
    size = ofRandom(25,50);
    widthMod = ofRandom(1,3);
    heightMod = ofRandom(1,3);
    c.r = ofRandom(255);
    c.g = ofRandom(255);
    c.b = ofRandom(255);
    
}

void Rectangle::update() {

}

void Rectangle::draw() {
    ofEnableAlphaBlending();
    ofSetColor(c, 150);
    ofRect(pos.x, pos.y, size*widthMod, size*heightMod);
}

void Rectangle::xenoToPoint(float catchX, float catchY) {
    
    pos.x = catchUpSpeed * catchX + ( 1 - catchUpSpeed) * pos.x;
    pos.y = catchUpSpeed * catchY + ( 1 - catchUpSpeed) * pos.y;

}
