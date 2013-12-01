//
//  Obstacle.cpp
//  Final_Obstacle
//
//  Created by Owen Herterich on 11/25/13.
//
//

#include "Obstacle.h"

Obstacle::Obstacle() {
    pos.set(ofGetWindowSize() / 2);
    vel.set( 0 );
    
    obSize = 50.0;
    obLife = 250.0;
    
    moveForce = 10.0;
    damping = 0.95;
    
    lastObTime = ofGetElapsedTimef();
    
    c.set(255,255,0);
}

void Obstacle::addForce( ofVec2f force ) {
    acc += force;
}

void Obstacle::addDamping() {
    vel *= damping;
}

void Obstacle::checkKeyPress( int key, int player ) {
    if (player == 1) {
    if ( key == OF_KEY_UP) {
            addForce( ofVec2f(0, -moveForce) );
        }
        
        if ( key == OF_KEY_RIGHT) {
            addForce( ofVec2f(moveForce, 0) );
        }
        
        if ( key == OF_KEY_DOWN) {
            addForce( ofVec2f(0, moveForce) );
        }
        
        if ( key == OF_KEY_LEFT) {
            addForce( ofVec2f(-moveForce, 0) );
        }
        
        if ( key == OF_KEY_ALT ) {
            addObstacle();
        }
    }
    
    if (player == 2) {
        if ( key == 'w') {
            addForce( ofVec2f(0, -moveForce) );
        }
        
        if ( key == 'd') {
            addForce( ofVec2f(moveForce, 0) );
        }
        
        if ( key == 's') {
            addForce( ofVec2f(0, moveForce) );
        }
        
        if ( key == 'a') {
            addForce( ofVec2f(-moveForce, 0) );
        }
        
        if ( key == ' ' ) {
            addObstacle();
        }
    }
}

void Obstacle::screenBoundaryCheck() {
    if ( pos.x > ofGetWindowWidth() ) {
        pos.x = 0;
    }
    
    if ( pos.x < 0 ) {
        pos.x = ofGetWindowWidth();
    }
    
    if ( pos.y > ofGetWindowHeight() ) {
        pos.y = 0;
    }
    
    if ( pos.y < 0 ) {
        pos.y = ofGetWindowHeight();
    }
}

void Obstacle::addObstacle() {
    if (ofGetElapsedTimef() - lastObTime > 0.4) {
        ObstacleShape ob(obSize);
        ob.pos.set( pos );
        ob.life = obLife;
        
        obList.push_back( ob );
        
        lastObTime = ofGetElapsedTimef();
    }
}

void Obstacle::updateObstacle() {
    for ( int i = 0; i < obList.size(); i++ ) {
        if (obList[i].isDead()) {
            obList.erase(obList.begin() + i);
        }
        else {
            obList[i].update();
        }
    }
}

void Obstacle::drawObstacle() {
    for ( int i = 0; i < obList.size(); i++ ) {
        obList[i].draw();
    }
}

void Obstacle::update() {
    screenBoundaryCheck();
    
    updateObstacle();
    
    vel += acc;
    pos += vel;
    
    acc.set(0);
    addDamping();
}

void Obstacle::draw() {
    
    drawObstacle();
    
    ofFill();
    ofSetColor( c, 100 );
    ofRect(pos, obSize, obSize);
}