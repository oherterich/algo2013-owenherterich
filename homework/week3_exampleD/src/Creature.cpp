//
//  Creature.cpp
//  week3_exampleD
//
//  Created by Owen Herterich on 9/15/13.
//
//

#include "Creature.h"

Creature::Creature() {
    ofSetCircleResolution(40);
    pos.x = ofRandom( ofGetWindowWidth() );
    pos.y = ofRandom( ofGetWindowHeight() );
    r = 50;
    c = ofColor(ofRandom(100,200), ofRandom(100, 200), ofRandom(100, 200));
    catchUpSpeed = ofRandom(0.0005, 0.005);
    breatheOffset = ofRandom(0,5);
    mouthOffset = ofRandom(0,5);
    vel.x = 0;
    vel.y = 0;
}

void Creature::update() {
    float breathe = sin( ofGetElapsedTimef() * 2 + breatheOffset );
    r = ofMap(breathe, -2, 2, .8, 1.2);
    d = ofDist(pos.x, pos.y, mousePos.x, mousePos.y);
    
    diff = mousePos - pos;
    angle = atan2( diff.y, diff.x );
    
    vel *= 0.96;
    pos += vel;
}

void Creature::draw() {
    ofPushMatrix();{
        ofTranslate(pos);
        ofRotate( ofDegToRad( angle ) );
        ofScale(r, r);
        ofFill();
        ofSetColor(c);
        ofCircle(0, 0, 50);
        drawEye();
        drawEyebrow();
        drawArms();
        drawMouth();
    }ofPopMatrix();
}

void Creature::drawEye() {
    ofSetColor(240);
    ofCircle(0, -10, 20);
    ofPushMatrix();{
        ofTranslate( 0, -7.5);
        ofRotate( ofRadToDeg( angle ) + 90);
        ofSetColor(10);
        ofCircle(0,-5, 15);
    }ofPopMatrix();
}

void Creature::drawEyebrow() {
    float offset = ofMap(d, 0, ofGetWindowWidth(), -32, -43);
    
    ofNoFill();
    ofSetLineWidth( 3.0 );
    ofSetColor( 0 );
    ofCurve(0, -10, -15, offset, 15, offset, 0, -10);
}

void Creature::drawArms() {
    ofPushMatrix();{
        ofRotate( ofRadToDeg( angle ) );
        ofSetColor( c );
        ofFill();
        ofSetLineWidth( 10.0 );
        ofLine(50, 0, 100, 0);
        ofEllipse(100, 0, 17, 20);
    }ofPopMatrix();
    
    ofPushMatrix();{
        ofRotate( ofRadToDeg( -angle ) );
        ofSetColor( c );
        ofFill();
        ofSetLineWidth( 10.0 );
        ofLine(-50, 0, -100, 0);
        ofEllipse(-100, 0, 17, 20);
    }ofPopMatrix();
}

void Creature::drawMouth() {
    ofSetColor(30);
    float height = 6 * cos(ofGetElapsedTimef() + mouthOffset);
    ofEllipse(0,25, 40, height);
}

void Creature::xenoToPoint(float catchX, float catchY) {
    pos.x = catchUpSpeed * catchX + (1 - catchUpSpeed) * pos.x;
    pos.y = catchUpSpeed * catchY + (1 - catchUpSpeed) * pos.y;
}

bool Creature::kill() {
    if (d <= 60) {
        return true;
    }
    else return false;
}