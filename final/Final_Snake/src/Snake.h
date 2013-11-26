//
//  Snake.h
//  Final_Snake
//
//  Created by Owen Herterich on 11/25/13.
//
//

#pragma once

#include "ofMain.h"

class Snake {
    public:
        Snake();
        void update( float dt );
        void draw();
    
        void addForce( ofVec2f force );
        void addDamping();
        void checkCollision( ofVec2f p, float size );
        void checkSelfCollision();
    
        void addTail();
        void updateTail();
        void drawTail();
        void screenBoundaryCheck();
        void checkKeyPress( int key );
    
        ofVec2f pos, vel, acc; //controls main snake
        vector<ofVec2f> snakePos; //position of tail of snake
    
        int     snakeLength; //the length of the snake
        int     snakeSize; //the size (radius) of snake
    
        float   desiredSpeed; //the speed the snake wants to go
        float   damping; //slows down snake
        float   turnForce; //acceleration after turn
    
        bool    bHasCollided; //if collision occurs, this is true
    
        ofColor c;
    
};