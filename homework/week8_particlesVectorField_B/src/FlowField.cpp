//
//  FlowField.cpp
//  week7_vectorfields
//
//  Created by Owen Herterich on 10/12/13.
//
//

#include "FlowField.h"

FlowField::FlowField() {
    
}

void FlowField::setup(int width, int height, int res) {
    fieldWidth = width;
    fieldHeight = height;
    resolution = res;
    
    int cols = width / res;
    int rows = height / res;
    
    for (int y = 0; y < rows; y++) {
        VectorList list;
        flowList.push_back( list );
        
        for (int x = 0; x < cols; x++) {
            ofVec2f dir(0,0);
            flowList[y].push_back( dir );
        }
    }
}

ofVec2f FlowField::getForceAtPosition(ofVec2f pos) {
    float pctX = pos.x / fieldWidth;
    float pctY = pos.y / fieldHeight;
    
    int cols = fieldWidth / resolution;
    int rows = fieldHeight / resolution;
    
    int xVal = ofClamp(pctX * cols, 0, cols-1);
    int yVal = ofClamp(pctY * rows, 0, rows-1);
    
    ofVec2f newPos;
    newPos.set( flowList[yVal][xVal] );
    
    return newPos;
}

void FlowField::setDirectional() {
    for (int y = 0; y < flowList.size(); y++) {
        for (int x = 0; x < flowList[y].size(); x++) {
            int rand = (int)ofRandom(4);
            
            switch (rand) {
                case 0:
                    flowList[y][x].set(0,1 * (int)ofRandom(1, 5));
                    break;
                
                case 1:
                    flowList[y][x].set(1 * (int)ofRandom(1, 5),0);
                    break;
                    
                case 2:
                    flowList[y][x].set(-1 * (int)ofRandom(1, 5),0);
                    break;
                    
                case 3:
                    flowList[y][x].set(0,-1 * (int)ofRandom(1, 5));
                    break;
            }
        }
    }
}

void FlowField::setPerlin() {
    for( int y=0; y<flowList.size(); y++){
        for( int x=0; x<flowList[y].size(); x++){
            float noise = ofMap( ofNoise(x*0.07, y*0.07), 0, 1, 0, TWO_PI);
            flowList[y][x].set( ofVec2f( cos(noise) * 20.0, sin(noise) * 20.0 ) );
        }
    }
}

void FlowField::setHorizontal() {
    for( int y=0; y<flowList.size(); y++){
        for( int x=0; x<flowList[y].size(); x++){
            if (y % 2 == 0) {
                int rand = ofRandom(25);
                if (rand > 0) {
                    flowList[y][x].set(1,0);
                }
                else {
                    flowList[y][x].set(0,1);
                }
            }
            if (y % 2 == 1) {
                int rand = ofRandom(25);
                if (rand > 0) {
                    flowList[y][x].set(-1,0);
                }
                else {
                    flowList[y][x].set(0,-1);
                }
            }
        }
    }
}

void FlowField::draw() {
    for( int y=0; y<flowList.size(); y++){
        for( int x=0; x<flowList[y].size(); x++){
            ofVec2f np( x*resolution, y*resolution );
            drawVectorAt( flowList[y][x], np );
        }
    }
}

void FlowField::drawVectorAt( const ofVec2f &vec, const ofVec2f &pos ) {
    ofVec2f np = pos - (vec.normalized()) * 5.0;
    drawVector( np, np + vec.normalized() * 10.0, 5, 3 );
}

/**
 * This is a complicated one!  It's a translation of the one right out of the Cinder source, no need to understand it,
 * but it's an interesting one to look at anyway!
 * https://github.com/cinder/Cinder/blob/master/src/cinder/gl/gl.cpp line 915 if you're interested
 */
void FlowField::drawVector( const ofVec3f &start, const ofVec3f &end, float headLength, float headRadius ) {
	const int NUM_SEGMENTS = 32;
	float lineVerts[3*2];
	ofVec3f coneVerts[NUM_SEGMENTS+2];
	glEnableClientState( GL_VERTEX_ARRAY );
	glVertexPointer( 3, GL_FLOAT, 0, lineVerts );
	lineVerts[0] = start.x; lineVerts[1] = start.y; lineVerts[2] = start.z;
	lineVerts[3] = end.x; lineVerts[4] = end.y; lineVerts[5] = end.z;
	glDrawArrays( GL_LINES, 0, 2 );
	
	// Draw the cone
	ofVec3f axis = ( end - start ).normalized();
    ofVec3f temp = ( axis.dot( ofVec3f(0,1,0) ) > 0.999f ) ? axis.crossed( ofVec3f(1,0,0) ) : axis.crossed( ofVec3f(0,1,0) );
	ofVec3f left = ofVec3f(axis.crossed( temp )).normalized();
	ofVec3f up = axis.crossed( left ).normalized();
    
	glVertexPointer( 3, GL_FLOAT, 0, &coneVerts[0].x );
	coneVerts[0] = ofVec3f( end + axis * headLength );
	for( int s = 0; s <= NUM_SEGMENTS; ++s ) {
		float t = (float)s / (float)NUM_SEGMENTS;
		coneVerts[s+1] = ofVec3f( end + left * headRadius * cos( t * 2.0f * 3.14159f )
                                 + up * headRadius * sin( t * 2.0f * 3.14159f ) );
	}
	glDrawArrays( GL_TRIANGLE_FAN, 0, NUM_SEGMENTS+2 );
    
	// draw the cap
	glVertexPointer( 3, GL_FLOAT, 0, &coneVerts[0].x );
	coneVerts[0] = end;
	for( int s = 0; s <= NUM_SEGMENTS; ++s ) {
		float t = s / (float)NUM_SEGMENTS;
		coneVerts[s+1] = ofVec3f( end - left * headRadius * (float)cos( t * 2 * 3.14159f )
                                 + up * headRadius * (float)sin( t * 2 * 3.14159f ) );
	}
	glDrawArrays( GL_TRIANGLE_FAN, 0, NUM_SEGMENTS+2 );
    
	glDisableClientState( GL_VERTEX_ARRAY );
}