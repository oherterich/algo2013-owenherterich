//
//  Powerup.cpp
//  Final_Snake
//
//  Created by Owen Herterich on 11/30/13.
//
//

#include "Powerup.h"

Powerup::Powerup( bool _bIsSnake, ofTrueTypeFont *_type, int _snakePlayer ) {
    iconSize = 100;
    trans = 255;
    age = 0;
    life = 300;
    
    c = ofColor(255);
    
    type = _type;
    
    bIsActive = false;
    bIsSnake = _bIsSnake;
    
    nameTrans = 255.0;
    nameSize = 0.8;
    
    snakePlayer = _snakePlayer;
    
    
    int rand;
    if (bIsSnake) {
        rand = ofRandom(5);
        if (snakePlayer == 1) {
            nameHue = 100.0;
        }
        else {
            nameHue = 20.0;
        }
    }
    else {
        rand = ofRandom(8, 9);
        if (snakePlayer == 1) {
            nameHue = 100.0;
        }
        else {
            nameHue = 20.0;
        }
    }
    
    switch (rand) {
        case 0:
            name = "Bonus";
            img.loadImage("img/powerups/player" + ofToString(snakePlayer) + "_bonus.png");
            timeActive = 3.0;
            break;
            
        case 1:
            name = "Short";
            img.loadImage("img/powerups/player" + ofToString(snakePlayer) + "_shortsnake.png");
            timeActive = 2.0;
            break;
            
        case 2:
            name = "Slow";
            img.loadImage("img/powerups/player" + ofToString(snakePlayer) + "_timeslow.png");
            timeActive = 3.0;
            break;
            
        case 3:
            name = "Invincible";
            img.loadImage("img/powerups/player" + ofToString(snakePlayer) + "_invincible.png");
            timeActive = 2.0;
            break;
            
        case 4:
            name = "Bomb";
            img.loadImage("img/powerups/player" + ofToString(snakePlayer) + "_bomb.png");
            timeActive = 1.0;
            break;
            
        case 5:
            name = "Fast";
            img.loadImage("img/powerups/player" + ofToString(snakePlayer) + "_timefast.png");
            timeActive = 3.0;
            break;
            
        case 6:
            name = "Long";
            img.loadImage("img/powerups/player" + ofToString(snakePlayer) + "_longsnake.png");
            timeActive = 2.0;
            break;
            
        case 7:
            name = "Large";
            img.loadImage("img/powerups/player" + ofToString(snakePlayer) + "_largeobst.png");
            timeActive = 3.0;
            break;
            
        case 8:
            name = "Invisible";
            img.loadImage("img/powerups/player" + ofToString(snakePlayer) + "_invisible.png");
            timeActive = 2.0;
            break;
            
        case 9:
            name = "Wall";
            img.loadImage("img/powerups/player" + ofToString(snakePlayer) + "_wall.png");
            timeActive = 3.0;
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
        age += 1000;
        howLong = 0;
    }
}

void Powerup::drawName() {
    if (bIsActive) {
        float w = type->stringWidth(name) * nameSize;
        float h = type->stringHeight(name) * nameSize;
        
        ofColor n;
        n.setHsb( nameHue, 230, 255 );
        ofSetColor( n , nameTrans);
        ofPushMatrix();{
            ofTranslate(ofGetWindowWidth() / 2 - w / 2, ofGetWindowHeight() / 2 + h / 2);
            ofScale(nameSize, nameSize);
            type->drawString(name, 0, 0);
        }ofPopMatrix();
        
        nameTrans -= 6.0;
        nameSize += 0.07;
        if (bIsSnake) {
            nameHue = sin(ofGetElapsedTimef() * 3.0) * 20 + 150;
        }
        else {
            nameHue = sin(ofGetElapsedTimef() * 3.0) * 20 + 20;
        }
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
        if (!bIsActive && age < life) {
            img.draw(0,0);
        }
    }ofPopMatrix();
    
    drawName();
}

bool Powerup::isDead() {
    if ( age >= life ) {
        return true;
    }
    else return false;
}