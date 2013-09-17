//
//  Rectangle.cpp
//  week3_exampleB
//
//  Created by Owen Herterich on 9/16/13.
//
//

#include "Rectangle.h"

Rectangle::Rectangle() {
    pos.x = ofRandom(-500, ofGetWindowWidth()+500);
    pos.y = ofRandom(-500, ofGetWindowHeight()+500);
    pos.z = ofRandom(-100);
    
    width = ofRandom(50, 100);
    height = ofRandom(10, 20);
}

void Rectangle::update() {
    pos.z -= 1.0;
}

void Rectangle::draw() {
    ofPushMatrix();{
        ofTranslate(pos);
       ofRotateY(90);
        ofFill();
        ofSetColor(255, 70);
        ofRect(0,0,width,height);
    }ofPopMatrix();
}

bool Rectangle::dead() {
    if (pos.z <= -10000) {
        return true;
    }
    else return false;
}