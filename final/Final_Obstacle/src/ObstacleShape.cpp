//
//  ObstacleShape.cpp
//  Final_Obstacle
//
//  Created by Owen Herterich on 11/25/13.
//
//

#include "ObstacleShape.h"

ObstacleShape::ObstacleShape( float _size ) {
    age = 0;
    size = _size;
    c.setHsb(ofRandom(20, 60), 255, 255);
}

void ObstacleShape::update() {
    age += 1;
    
    float pct = 1.0 - (age / life);
    
    if (pct <= 0.05) {
        trans = 255.0 * (pct / 0.05);
    }
    else {
        trans = 255.0;
    }
    

}

void ObstacleShape::draw() {
    ofSetColor(c, trans);
    ofRect(pos, size, size);
}

bool ObstacleShape::isDead() {
    if ( age >= life ) {
        return true;
    }
    else return false;
}