//
//  ObstacleShape.h
//  Final_Obstacle
//
//  Created by Owen Herterich on 11/25/13.
//
//

#pragma once

#include "ofMain.h"

class ObstacleShape {
    public:
    ObstacleShape( float _size, ofImage *_img, float _theta );
    void update( float dt );
    void draw();
    bool isDead();
    
    ofVec2f pos;
    float size;
    
    float theta;
    
    float age;
    float life;
    
    ofColor c;
    float trans;
    
    ofImage *img;
};
