//
//  KochLine.cpp
//  week13_koch
//
//  Created by Owen Herterich on 11/19/13.
//
//

#include "KochLine.h"

KochLine::KochLine( ofVec2f _start, ofVec2f _end ) {
    start = _start;
    end = _end;
}

void KochLine::draw() {
    ofSetColor(0,0,255);
    ofLine(start, end);
}

ofVec2f KochLine::a() {
    return start;
}

ofVec2f KochLine::b() {
    ofVec2f line = (end - start) * 0.333333333;
    return start + line;
}

ofVec2f KochLine::c() {
    ofVec2f line = (end - start) * 0.333333333;
    line.rotate( -60 );
    return b() + line;
}

ofVec2f KochLine::d() {
    ofVec2f line = (end - start) * 0.666666667;
    return start + line;
}

ofVec2f KochLine::e() {
    return end;
}

float KochLine::getLength() {
    return start.distance(end);
}


