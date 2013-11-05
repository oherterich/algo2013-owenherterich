//
//  FlockController.h
//  week10_flocking
//
//  Created by Owen Herterich on 11/5/13.
//
//

#pragma once

#include "ofMain.h"
#include "Boid.h"

class FlockController {
public:
    FlockController();
    void update();
    void draw();
    void addBoid();
    void addForces( float attractRadius=100.0, float alignPct=0.7, float repulsePct=0.4 );    
    vector<Boid> boidList;
};
