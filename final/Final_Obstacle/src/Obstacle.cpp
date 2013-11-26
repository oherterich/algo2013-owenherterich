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
    
    moveForce = 5.0;
    damping = 0.95;
    
    c.set(255,255,0);
}

void Obstacle::addForce( ofVec2f force ) {
    acc += force;
}

void Obstacle::addDamping() {
    vel *= damping;
}

void Obstacle::checkKeyPress( int key ) {
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
    
    if ( key == ' ' ) {
        addObstacle();
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
    ObstacleShape ob(obSize);
    ob.pos.set( pos );
    ob.life = 250;
    
    obList.push_back( ob );
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
    ofSetColor(255);
    ofDrawBitmapString(ofToString(obList.size()), ofPoint(20, 20));
    
    drawObstacle();
    
    ofSetColor( c, 100 );
    ofRect(pos, obSize, obSize);
}