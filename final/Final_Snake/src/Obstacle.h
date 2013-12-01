//
//  Obstacle.h
//  Final_Obstacle
//
//  Created by Owen Herterich on 11/25/13.
//
//

#pragma once

#include "ofMain.h"
#include "ObstacleShape.h"

class Obstacle {
    public:
        Obstacle();
        void update();
        void draw();
    
        void addForce( ofVec2f force );
        void addDamping();
        void checkKeyPress( int key, int player );
        void screenBoundaryCheck();
        void addObstacle();
        void updateObstacle();
        void drawObstacle();
    
        ofVec2f pos, vel, acc;
    
        vector<ObstacleShape> obList;
    
        float obSize;
        float obLife;
    
        float moveForce;
        float damping;
    
        float lastObTime;
    
        ofColor c;
};
