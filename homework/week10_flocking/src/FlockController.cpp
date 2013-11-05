//
//  FlockController.cpp
//  week10_flocking
//
//  Created by Owen Herterich on 11/5/13.
//
//

#include "FlockController.h"

FlockController::FlockController() {
    
}

void FlockController::addBoid() {
    Boid b;
    b.pos = ofVec2f(ofRandomWidth(), ofRandomHeight());
    b.vel = ofVec2f(ofRandom(-5, 5), ofRandom(-5, 5));

    boidList.push_back( b );
}

void FlockController::addForces( float attractRadius, float alignPct, float repulsePct ) {
    for (vector<Boid>::iterator i1 = boidList.begin(); i1 != boidList.end(); i1++) {
        
        vector<Boid>::iterator i2 = i1 + 1;
        
        for (i2; i2 != boidList.end(); i2++) {
         
            ofVec2f diff = i1->pos - i2->pos;
            
            float angle = i1->pos.angle( i2->pos );
            
            i1->c = ofColor(255);
            i1->c = ofColor(255);
            
            if ( diff.lengthSquared() < (attractRadius * attractRadius) && angle > -45 && angle < 45) {
                
                i1->c = ofColor(255,0,0);
                i1->c = ofColor(255,0,0);
                
                float pct = diff.lengthSquared() / (attractRadius * attractRadius);
                
                if (pct == 0.0) {
                    pct = 0.00001;
                }
                
                if ( pct <= repulsePct ) {
                    float adjPct = 1.0 - ofMap(pct, 0, repulsePct, 0, 1.0);
                    
                    ofVec2f F = adjPct * diff.normalized() * 0.03;
                    
                    i1->addForce( F );
                    i2->addForce( -F );
                }
                else if ( pct > repulsePct && pct < alignPct ) {
                    float adjPct = 1.0 - ofMap(pct, repulsePct, alignPct, 0.0, 1.0);
                    float F = adjPct * 0.005;
                    
                    i1->addForce( i2->vel.normalized() * F);
                    i2->addForce( i1->vel.normalized() * F);
                }
                else {
                    float adjPct = ofMap(pct, alignPct, 1.0, 0.0, 1.0);
                    
                    ofVec2f F = adjPct * diff.normalized() * 0.007;
                    
                    i1->addForce( -F );
                    i2->addForce( F );
                }
            }
        }
    }
}

void FlockController::update() {
    for (vector<Boid>::iterator i1 = boidList.begin(); i1 != boidList.end(); i1++) {
        i1->pullToCenter();
        i1->update();
    }
}

void FlockController::draw() {
    for (vector<Boid>::iterator i1 = boidList.begin(); i1 != boidList.end(); i1++) {
        i1->draw();
    }
}