//
//  Powerup.h
//  Final_Snake
//
//  Created by Owen Herterich on 11/30/13.
//
//

#pragma once

#include "ofMain.h"

class Powerup {
public:
    Powerup();
    void update();
    void draw();
    
    void checkCollision( ofVec2f snake, ofVec2f obstacle);
    void timer();
    bool isDead();
    
    ofVec2f pos;
    ofImage img;
    
    float age;
    float life;
    
    float trans;
    
    float startActive;
    float timeActive;
    
    string name;
    int iconSize;
    
    bool bIsSnake;
    bool bIsActive;
    
    ofColor c;
};
