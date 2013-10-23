//
//  FlockController.h
//  10_22_Flocking
//
//  Created by Owen Herterich on 10/22/13.
//
//

#pragma once

#include "ofMain.h"
#include "Boid.h"

class FlockController {
public:
    FlockController();
    
    void applyForces( float zoneRadius, float separateThreshold=0.4, float alignThreshold=0.7 );
    
    void addParticle( int numParticles=1 );
    void update();
    void draw();
    
    vector<Boid>    boidList;
};
