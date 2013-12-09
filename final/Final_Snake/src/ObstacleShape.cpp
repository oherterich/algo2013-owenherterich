//
//  ObstacleShape.cpp
//  Final_Obstacle
//
//  Created by Owen Herterich on 11/25/13.
//
//

#include "ObstacleShape.h"

ObstacleShape::ObstacleShape( float _size, ofImage *_img, float _theta ) {
    age = 0;
    size = _size;
    c.setHsb(ofRandom(20, 60), 255, 255);
    
    theta = _theta;
    
    img = _img;
}

void ObstacleShape::update( float dt ) {
    age += 1;
    
    float pct = 1.0 - (age / life);
    
    if (pct <= 0.05) {
        trans = 255.0 * (pct / 0.05);
    }
    else {
        trans = 255.0;
    }
    
    theta += 1 * dt * 50;
}

void ObstacleShape::draw() {
    ofFill();
    //ofSetColor(c, trans);
    ofSetColor(255, 255);
    ofPushMatrix();
        ofTranslate( pos );
    ofRotate(theta);
        img->draw(0,0);
    ofPopMatrix();
}

bool ObstacleShape::isDead() {
    if ( age >= life ) {
        return true;
    }
    else return false;
}