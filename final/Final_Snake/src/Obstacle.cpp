//
//  Obstacle.cpp
//  Final_Obstacle
//
//  Created by Owen Herterich on 11/25/13.
//
//

#include "Obstacle.h"

Obstacle::Obstacle( ) {
    pos.set(ofGetWindowSize() / 2);
    vel.set( 0 );
    
    theta = 0;
    
    obSize = 100.0;
    obLife = 400.0;
    
    moveForce = 11.0;
    damping = 0.95;
    
    lastObTime = ofGetElapsedTimef();
    
    player1Ob.loadImage("img/player1_obst.png");
    player2Ob.loadImage("img/player2_obst.png");
    transOb.loadImage("img/shadow_obst.png");
    
    obstaclePlayer = 2;
    
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
            addForce( ofVec2f(0, -moveForce / 2) );
            vel.set( 0, -moveForce );
        }
        
        if ( key == OF_KEY_RIGHT) {
            addForce( ofVec2f(moveForce / 2, 0) );
            vel.set( moveForce, 0 );
        }
        
        if ( key == OF_KEY_DOWN) {
            addForce( ofVec2f(0, moveForce / 2) );
            vel.set( 0, moveForce );
        }
        
        if ( key == OF_KEY_LEFT) {
            addForce( ofVec2f(-moveForce / 2, 0) );
            vel.set( -moveForce, 0 );
        }
        
        if ( key == OF_KEY_ALT ) {
            addObstacle();
        }
    }
    
    if (player == 2) {
        if ( key == 'w') {
            addForce( ofVec2f(0, -moveForce / 2) );
            vel.set( 0, -moveForce );
        }
        
        if ( key == 'd') {
            addForce( ofVec2f(moveForce / 2, 0) );
            vel.set( moveForce, 0 );
        }
        
        if ( key == 's') {
            addForce( ofVec2f(0, moveForce / 2) );
            vel.set( 0, moveForce );
        }
        
        if ( key == 'a') {
            addForce( ofVec2f(-moveForce / 2, 0) );
            vel.set( -moveForce, 0 );
        }
        
        if ( key == ' ' ) {
            addObstacle();
        }
    }
}

void Obstacle::checkGamepad( int button, int player ) {
    if (player == 1) {
        if ( button == 0 ) {
            addForce( ofVec2f(0, -moveForce / 2) );
            vel.set( 0, -moveForce );
        }
        
        if ( button == 3 ) {
            addForce( ofVec2f(moveForce / 2, 0) );
            vel.set( moveForce, 0 );
        }
        
        if ( button == 1 ) {
            addForce( ofVec2f(0, moveForce / 2) );
            vel.set( 0, moveForce );
        }
        
        if ( button == 2 ) {
            addForce( ofVec2f(-moveForce / 2, 0) );
            vel.set( -moveForce, 0 );
        }
        
        if ( button == 11 ) {
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
    if (ofGetElapsedTimef() - lastObTime > 0.2) {
        if ( obstaclePlayer == 1 ) {
            ObstacleShape ob(obSize, &player1Ob, theta);
            ob.pos.set( pos );
            ob.life = obLife;
            
            obList.push_back( ob );
        }
        else {
            ObstacleShape ob(obSize, &player2Ob, theta);
            ob.pos.set( pos );
            ob.life = obLife;
            
            obList.push_back( ob );
        }
        
        lastObTime = ofGetElapsedTimef();
    }
}

void Obstacle::updateObstacle( float dt ) {
    for ( int i = 0; i < obList.size(); i++ ) {
        if (obList[i].isDead()) {
            obList.erase(obList.begin() + i);
        }
        else {
            obList[i].update( dt );
        }
    }
}

void Obstacle::drawObstacle() {
    for ( int i = 0; i < obList.size(); i++ ) {
        obList[i].draw();
    }
}

void Obstacle::update( float dt ) {
    screenBoundaryCheck();
    
    updateObstacle( dt );
    
    vel += acc;
    pos += (vel * dt * 50);
    
    acc.set(0);
    
    if (vel.x > 10.0 || vel.x < -10.0 || vel.y > 10.0 || vel.y < -10.0) {
        addDamping();
    }
    
    theta += 1 * dt * 50;
    
    if (obstaclePlayer == 1) {
        c.setHsb( sin(ofGetElapsedTimef() * 0.5) * 20 + 20, 230, 255 );
    }
    else {
        c.setHsb( sin(ofGetElapsedTimef()) * 40 + 100, 230, 255 );
    }
}

void Obstacle::draw() {
    
    drawObstacle();
    
    ofFill();
    ofSetColor( c, 150 );
    ofPushMatrix();
        ofTranslate(pos);
        ofRotate(theta);
        transOb.draw(0,0);
    ofPopMatrix();
}