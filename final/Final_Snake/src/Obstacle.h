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
        Obstacle( );
        void update( float dt );
        void draw();
    
        void addForce( ofVec2f force );
        void addDamping();
        void checkKeyPress( int key, int player );
        void checkGamepad( int button, int player );
        void screenBoundaryCheck();
        void addObstacle();
        void updateObstacle( float dt );
        void drawObstacle();
    
        ofVec2f pos, vel, acc;
    
        float theta;
    
        vector<ObstacleShape> obList;
    
        float obSize;
        float obLife;
    
        float moveForce;
        float damping;
    
        float lastObTime;
    
        ofImage player1Ob, player2Ob, transOb;
    
        int obstaclePlayer;
    
        ofColor c;
        float sat;
        float bright;
    
        ofSoundPlayer placeOb;
};
