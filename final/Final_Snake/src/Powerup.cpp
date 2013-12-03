//
//  Powerup.cpp
//  Final_Snake
//
//  Created by Owen Herterich on 11/30/13.
//
//

#include "Powerup.h"

Powerup::Powerup() {
    iconSize = 100;
    trans = 255;
    age = 0;
    life = 300;
    
    timeActive = 3.0;
    
    c = ofColor(255);
    
    bIsActive = false;
    
    int rand = ofRandom(10);
    
    switch (rand) {
        case 0:
            name = "Bonus";
            img.loadImage("powerups/bonus.png");
            bIsSnake = true;
            break;
            
        case 1:
            name = "Short";
            img.loadImage("powerups/shortsnake.png");
            bIsSnake = true;
            break;
            
        case 2:
            name = "Slow";
            img.loadImage("powerups/timeslow.png");
            bIsSnake = true;
            break;
            
        case 3:
            name = "Invincible";
            img.loadImage("powerups/invincible.png");
            bIsSnake = true;
            break;
            
        case 4:
            name = "Bomb";
            img.loadImage("powerups/bomb.png");
            bIsSnake = true;
            break;
            
        case 5:
            name = "Fast";
            img.loadImage("powerups/timefast.png");
            bIsSnake = false;
            break;
            
        case 6:
            name = "Long";
            img.loadImage("powerups/longsnake.png");
            bIsSnake = false;
            break;
            
        case 7:
            name = "Large";
            img.loadImage("powerups/largeobst.png");
            bIsSnake = false;
            break;
            
        case 8:
            name = "Invisible";
            img.loadImage("powerups/invisible.png");
            bIsSnake = false;
            break;
            
        case 9:
            name = "Wall";
            img.loadImage("powerups/wall.png");
            bIsSnake = false;            
            break;
    }
    
    pos.set(ofRandomWidth(), ofRandomHeight());
}

void Powerup::checkCollision( ofVec2f snake, ofVec2f obstacle ) {

    if (bIsSnake) {
        if ( pos.distance(snake) < iconSize / 2) {
            bIsActive = true;
            startActive = ofGetElapsedTimef();
        }
    }
    else {
        if ( pos.distance(obstacle) < iconSize / 2) {
            bIsActive = true;
            startActive = ofGetElapsedTimef();
        }
    }
}

void Powerup::timer() {
    if (ofGetElapsedTimef() - startActive >= timeActive) {
        bIsActive = false;
        age += 250;
    }
}

void Powerup::update() {
    if (bIsActive) {
        timer();
    }
    else {
        age += 1;
    
        float pct = 1.0 - (age / life);
    
        if (pct <= 0.05) {
            trans = 255.0 * (pct / 0.05);
        }
        else {
            trans = 255.0;
        }
    }
}

void Powerup::draw() {
    ofSetRectMode(OF_RECTMODE_CENTER);
    ofSetColor(c, trans);
    ofPushMatrix();{
        ofTranslate(pos);
        if (!bIsActive) {
            img.draw(0,0);
        }
    }ofPopMatrix();
}

bool Powerup::isDead() {
    if ( age >= life ) {
        return true;
    }
    else return false;
}