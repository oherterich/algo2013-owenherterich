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
    Powerup( bool _bIsSnake, ofTrueTypeFont *_type );
    void update();
    void draw();
    
    void checkCollision( ofVec2f snake, ofVec2f obstacle);
    void timer();
    void drawName();
    bool isDead();
    
    ofVec2f pos;
    ofImage img;
    
    float age;
    float life;
    
    float trans;
    
    //When the powerup is touched, use these times
    float startActive;
    float timeActive;
    
    //Name Animation
    float nameTrans;
    float nameSize;
    float nameHue;
    
    string name;
    int iconSize;
    
    bool bIsSnake;
    bool bIsActive;
    
    ofColor c;
    ofTrueTypeFont *type;
};
