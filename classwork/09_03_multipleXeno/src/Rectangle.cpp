//
//  Rectangle.cpp
//  09_03_multipleXeno
//
//  Created by Owen Herterich on 9/3/13.
//
//

#include "Rectangle.h"

Rectangle::Rectangle() {
    ofSetRectMode( OF_RECTMODE_CENTER );
    catchUpSpeed = 0.3;
    size = 50;
}

void Rectangle::xenoToPoint(float catchX, float catchY) {
    pos.x = catchUpSpeed * catchX + (1-catchUpSpeed) * pos.x;
    pos.y = catchUpSpeed * catchY + (1-catchUpSpeed) * pos.y;
}

void Rectangle::draw() {
    ofSetColor(255 * pos.y / ofGetWindowHeight(), 20, 20);
    ofRect( pos.x, pos.y, size, size);
}