#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    
    ofBackground(255, 255, 255);
	bIsRecording = false;
	playbackStartTime = 0;
	
}


//--------------------------------------------------------------
void testApp::update(){
    
}

//--------------------------------------------------------------
void testApp::draw(){
    
	
	
	// -------------------------- draw the line
	ofSetColor(0,0,0);
	ofNoFill();
	ofBeginShape();
	for (int i = 0; i < points.size();i++){
		ofVertex(points[i].x, points[i].y);
	}
	ofEndShape();
	
	// -------------------------- draw the point at the current time
	ofPoint pos = getPositionForTime(ofGetElapsedTimef() - playbackStartTime);
	ofFill();
	ofSetColor(255,0,0);
	ofCircle(pos.x, pos.y, 10);
	
	
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){
    
}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){
    
}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){
    
	TimePoint temp;
	temp.x = x;
	temp.y = y;
	temp.t = ofGetElapsedTimef() - startTime;
	points.push_back(temp);
	
	printf("adding point %i at time %f \n", points.size(), ofGetElapsedTimef() - startTime);
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
    
	
	bIsRecording = true;
	points.clear();
	startTime = ofGetElapsedTimef();
	TimePoint temp;
	temp.x = x;
	temp.y = y;
	temp.t = 0;
	points.push_back(temp);
	
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){
    
	bIsRecording = false;
	playbackStartTime = ofGetElapsedTimef();
    
}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){
    
}

//--------------------------------------------------------------
ofPoint testApp::getPositionForTime(float time){
	
	// are we recording?
	
	if (bIsRecording == true){
		return ofPoint(0,0,0);
	} else if (points.size() < 2){
		return ofPoint(0,0,0);
	}
	
	// now, let's figure out where we are in the drawing....
	
	// (a) figure out where we are in the cycle
	
	// (like % but for floats)
	while (time > points[points.size()-1].t){
		time -= points[points.size()-1].t;
	}
	
	
	ofPoint pos;
	
	for (int i = 0; i < points.size()-1; i++){
		if (time >= points[i].t && time < points[i+1].t){
			
			// calculate pct:
			
			float part = time - points[i].t;
			float whole = points[i+1].t - points[i].t;
			float pct = part / whole;
			
			// figure out where we are between a and b
			
			
			pos.x = (1-pct) * points[i].x + (pct) * points[i+1].x;
			pos.y = (1-pct) * points[i].y + (pct) * points[i+1].y;
			
			
		}
	}
	
	return pos;
    
}