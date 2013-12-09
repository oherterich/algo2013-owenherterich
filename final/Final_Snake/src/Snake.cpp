//
//  Snake.cpp
//  Final_Snake
//
//  Created by Owen Herterich on 11/25/13.
//
//

#include "Snake.h"

Snake::Snake() {
    snakeLength = 25;
    snakeSize = 15;
    
    pos.set(ofGetWindowSize() / 2);
    vel.set(5, 0);
    
    desiredSpeed = 5.0;
    damping = 0.97;
    turnForce = 3.0;
    
    c.setHsb(ofRandom(255), 255, 255);
    
    for( int i = 0; i < snakeLength; i++) {
        ofVec2f p;
        p.set(pos.x - snakeSize, pos.y);
        snakePos.push_back(p);
    }
    
    snakePlayer = 1;
    
}

void Snake::addForce( ofVec2f force ) {
    acc += force;
}

void Snake::addDamping() {
    if ( abs(vel.x) > desiredSpeed || abs(vel.y) > desiredSpeed ) {
        vel *= 0.97;
    }
}

void Snake::checkCollision( ofVec2f p, float size ) {

    if (pos.distance(p) < size) {
        bHasCollided = true;
    }
    
    else return;
}

void Snake::checkSelfCollision() {
    for ( int i = 0; i < snakePos.size()-1; i++ ) {
        if (pos.distance(snakePos[i]) < snakeSize / 2 ) {
            bHasCollided = true;
        }
    }
}

void Snake::checkBoundaryCollision() {
    
    if (pos.x >= ofGetWindowWidth() || pos.x <= 0 || pos.y >= ofGetWindowHeight() || pos.y <= 0) {
        bHasCollided = true;
    }
}

void Snake::addTail() {
        ofVec2f p;
        p.set(snakePos[snakePos.size() - 1].x, snakePos[snakePos.size() - 1].y);
        snakePos.push_back(p);    
}

void Snake::updateTail() {
    for ( int i = 0; i < snakePos.size() - 1; i++ ) {
        snakePos[i].set(snakePos[i+1]);
    }
    
    snakePos[snakePos.size()-1] = pos;
}

void Snake::drawTail() {
    for ( int i = 0; i < snakePos.size(); i++ ) {
        if (snakePlayer == 1) {
            float r = ofMap(i, 0, snakePos.size()-1, 238, 255);
            float g = ofMap(i, 0, snakePos.size()-1, 42, 242);
            float b = ofMap(i, 0, snakePos.size()-1, 123, 0);
            ofSetColor(r, g, b, 255);
        }
        else {
            float r = ofMap(i, 0, snakePos.size()-1, 0, 146);
            float g = ofMap(i, 0, snakePos.size()-1, 192, 255);
            float b = ofMap(i, 0, snakePos.size()-1, 255, 52);
            ofSetColor(r, g, b, 255);
        }
        ofRect(snakePos[i], snakeSize, snakeSize);
    }
}

void Snake::screenBoundaryCheck() {
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

void Snake::checkKeyPress( int key, int player ) {
    if (player == 1) {
        if (key == OF_KEY_UP && vel.y == 0) {
            vel.set(0, -desiredSpeed);
            addForce( ofVec2f(0, -turnForce) );
        }
        
        if (key == OF_KEY_RIGHT && vel.x == 0) {
            vel.set(desiredSpeed, 0);
            addForce( ofVec2f(turnForce, 0) );
        }
        
        if (key == OF_KEY_DOWN && vel.y == 0) {
            vel.set(0, desiredSpeed);
            addForce( ofVec2f(0, turnForce) );
        }
        
        if (key == OF_KEY_LEFT && vel.x == 0) {
            vel.set(-desiredSpeed, 0);
            addForce( ofVec2f(-turnForce, 0) );
        }
    }
    else if (player == 2) {
        if (key == 'w' && vel.y == 0) {
            vel.set(0, -desiredSpeed);
            addForce( ofVec2f(0, -turnForce) );
        }
        
        if (key == 'd' && vel.x == 0) {
            vel.set(desiredSpeed, 0);
            addForce( ofVec2f(turnForce, 0) );
        }
        
        if (key == 's' && vel.y == 0) {
            vel.set(0, desiredSpeed);
            addForce( ofVec2f(0, turnForce) );
        }
        
        if (key == 'a' && vel.x == 0) {
            vel.set(-desiredSpeed, 0);
            addForce( ofVec2f(-turnForce, 0) );
        }
    }
}

void Snake::checkGamepad( int button, int player ) {
    if (player == 1) {
        if (button == 0 && vel.y == 0) {
            up = true;
            right = false;
            down = false;
            left = false;
            addForce( ofVec2f(0, -turnForce) );
            vel.x = 0;
            changeDirection();
        }
        
        else if (button == 3 && vel.x == 0) {
            up = false;
            right = true;
            down = false;
            left = false;
            addForce( ofVec2f(turnForce, 0) );
            vel.y = 0;
            changeDirection();
        }
        
        else if (button == 1 && vel.y == 0) {
            up = false;
            right = false;
            down = true;
            left = false;
            addForce( ofVec2f(0, turnForce) );
            vel.x = 0;
            changeDirection();
        }
        
        else if (button == 2 && vel.x == 0) {
            up = false;
            right = false;
            down = false;
            left = true;
            addForce( ofVec2f(-turnForce, 0) );
            vel.y = 0;
            changeDirection();
        }
    }
}

void Snake::changeDirection() {
    if (up) {
        vel.set(0, -desiredSpeed);
    }
    else if (right) {
        vel.set(desiredSpeed, 0);
    }
    
    else if (down) {
        vel.set(0, desiredSpeed);
    }
    
    else if (left) {
        vel.set(-desiredSpeed, 0);
    }
}

void Snake::update( float dt ) {
    
    updateTail();
    
    screenBoundaryCheck();
    //checkSelfCollision();
    
    vel += acc;
    pos += ( vel * dt * 50 );
    
    acc.set(0);
    addDamping();
}

void Snake::draw() {
    ofFill();
    ofSetColor(c);
    
    drawTail();
    
    ofRect(pos, snakeSize, snakeSize);
}