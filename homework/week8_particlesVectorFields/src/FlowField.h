//
//  FlowField.h
//  week7_vectorfields
//
//  Created by Owen Herterich on 10/12/13.
//
//

#pragma once

#include "ofMain.h"

typedef vector<ofVec2f> VectorList;

class FlowField {
public:
    FlowField();
    void setup( int width, int height, int res);
    void setDirectional();
    void draw();
    
    void drawVector( const ofVec3f &start, const ofVec3f &end, float headLength = 0.2f, float headRadius = 0.05f );
    void drawVectorAt( const ofVec2f &vec, const ofVec2f &pos );
    
    ofVec2f getForceAtPosition( ofVec2f pos );
    
    int fieldWidth, fieldHeight, resolution;
    vector<VectorList>  flowList;

};
