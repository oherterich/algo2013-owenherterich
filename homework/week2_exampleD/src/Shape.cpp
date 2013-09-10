//
//  Shape.cpp
//  week2_exampleD
//
//  Created by Owen Herterich on 9/4/13.
//
//

#include "Shape.h"

Shape::Shape() {
    wall = 500;
    pos.x = wall / 2;
    pos.y = wall / 2;
    pos.z = wall / 2;
    vel.x = ofRandom(-5.0, 5.0);
    vel.y = ofRandom(-5.0, 5.0);
    vel.z = ofRandom(-5.0, 5.0);
    c = 0;
}

void Shape::update() {
    
    changeColor();
    
    if (pos.x < r || pos.x > wall-r) {
        vel.x *= -1.0;
        c = 255;
    }
    
    if (pos.y < r || pos.y > wall-r) {
        vel.y *= -1.0;
        c = 255;
    }
    
    if (pos.z < r || pos.z > wall-r) {
        vel.z *= -1.0;
        c = 255;
    }
    
    pos += vel;
}

void Shape::draw() {
    ofSetColor(255,c,c);
    ofDrawSphere(pos, 20);    
}

void Shape::changeColor() {
    if (c > 0) {
        c-=7;
    }
}