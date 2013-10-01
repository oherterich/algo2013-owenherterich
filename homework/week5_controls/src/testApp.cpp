//--------------------------------------------------------------
// Nice settings to use:
// 1) Size: 2.0, Speed: 5 - 25, Rate: 10.0, Trail: 10.0, Explosion Size: 50.0
// 2) Size: 27.0, Speed: 20 - 30, Rate: 5.0, Trail: 80.0, Explosion Size: 100.0
// 3) Size: 1.0, Speed: 5 - 30, Rate: 10.0, Trail: 70.0, Explosion Size: 200.0, WHITE Color




#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofSetVerticalSync(true);
    ofSetBackgroundAuto(false);
    ofEnableAlphaBlending();
    ofBackground(0);
    
    gui = new ofxUICanvas(10, 10, 200, 500);
    gui->addLabel("Firework Controls");
    gui->addSpacer();
    gui->addLabel("Color");
    gui->addSlider("Red", 0, 255, 255);
    gui->addSlider("Green", 0, 255, 255);
    gui->addSlider("Blue", 0, 255, 255);
    gui->addToggle("Random Color", true);
    gui->addSpacer();
    gui->addLabel("Physics");
    gui->addSlider("Size", 1, 30, 10);
    gui->addRangeSlider("Speed", 5, 30, 10, 25);
    gui->addSlider("Rate", 1, 10, 2);
    gui->addSpacer();
    gui->addLabel("Misc.");
    gui->addSlider("Trail", 0, 100, 50);
    gui->addSlider("Explosion Size", 25, 250, 100);
    gui->addSpacer();
    gui->addToggle("Start / Stop", false);

    //gui->loadSettings("myGuiSettings.xml");
    
    ofAddListener( gui->newGUIEvent, this, &testApp::onGuiEvent) ;
    
    particleSize = 10.0;
    particleSpeedLow = 10.0;
    particleSpeedHigh = 25.0;
    particleRate = 2.0;
    r = 255;
    g = 255;
    b = 255;
    trailAmount = 50.0;
    explosionSize = 100.0;
    
    start = false;
    randomColor = true;

}

void testApp::exit() {
    //gui->saveSettings("myGuiSettings.xml");
    delete gui;
}

void testApp::onGuiEvent( ofxUIEventArgs &e ) {
    
    
    //Colors
    if ( e.getName() == "Red" ) {
        ofxUISlider *redSlider = (ofxUISlider*)e.widget;
        r = redSlider->getScaledValue();
    }
    
    if ( e.getName() == "Green" ) {
        ofxUISlider *greenSlider = (ofxUISlider*)e.widget;
        g = greenSlider->getScaledValue();
    }
    
    if ( e.getName() == "Blue" ) {
        ofxUISlider *blueSlider = (ofxUISlider*)e.widget;
        b = blueSlider->getScaledValue();
    }
    
    if (e.getName() == "Random Color") {
        ofxUIToggle *colorToggle = (ofxUIToggle*)e.widget;
        randomColor = colorToggle->getValue();
    }
    
    //Physics
    if (e.getName() == "Size") {
        ofxUISlider *size = (ofxUISlider*)e.widget;
        particleSize = size->getScaledValue();
    }
    
    if (e.getName() == "Speed") {
        ofxUIRangeSlider *speed = (ofxUIRangeSlider*)e.widget;
        particleSpeedLow = speed->getScaledValueLow();
        particleSpeedHigh = speed->getScaledValueHigh();
    }
    
    if (e.getName() == "Rate") {
        ofxUISlider *rate = (ofxUISlider*)e.widget;
        particleRate = rate->getScaledValue();
    }
    
    //Misc
    if (e.getName() == "Trail") {
        ofxUISlider *trail = (ofxUISlider*)e.widget;
        trailAmount = trail->getScaledValue();
    }
    
    if (e.getName() == "Explosion Size") {
        ofxUISlider *explosion = (ofxUISlider*)e.widget;
        explosionSize = explosion->getScaledValue();
    }
    
    //On/Off
    if (e.getName() == "Start / Stop") {
        ofxUIToggle *on = (ofxUIToggle*)e.widget;
        start = on->getValue();
    }
    
}

//--------------------------------------------------------------
void testApp::update(){
    
    //Update the twinkling stars background
    myBackground.update();
    
    
    //If our random color toggle is true, set a random hue
    if (randomColor) {
        hue.setHsb(ofRandom(255), 255, 255);
    }
    //if not, get the r,g,b values from the slider
    else {
        hue = ofColor(r, g, b);
    }
    
    //Map the rate of particles from the slider to a number we can use in our modulo
    int rate = ofMap(particleRate, 1, 10, 100, 5);
    
    //If we've clicked start, create new "single" particles at the designated rate
    if (start) {
        if (ofGetElapsedTimeMillis() % rate == 0) {
            InitParticle tmp(particleSpeedLow, particleSpeedHigh, particleSize, hue);
            single.push_back( tmp );
        }
    }
    
    //Loop through our particle list and update them.
    for ( vector<Particle>::iterator it = particles.begin(); it!=particles.end(); ) {
        it->update();
        
        //Check to see if the particle's age > life. If so, remove it.
        if ( it->kill() ) {
            it = particles.erase(it);
        }
        else {
            it++;
        }
    }
    
    //Loop through our list of single particles and update them.
    for ( int i = 0; i < single.size(); i++ ) {
        single[i].update();
        
        //If the single particle has slowed sufficiently, create a new firework
        //by adding particles to the list at that location
        if (single[i].kill()) {
            for ( int j = 0; j < explosionSize; j ++ ) {
                createParticle(single[i].pos, single[i].initVel, single[i].c, particleSize);
            }
            
            single.erase(single.begin() + i);
        }
    }
    
    
}

//--------------------------------------------------------------
void testApp::draw(){
    
    //Make the trails slider number a percentage so that we can use it as opacity.
    float trails = 255.0 * ((100 - trailAmount) * .01);
    
    //Draw background rectangle
    ofSetRectMode(OF_RECTMODE_CORNER);
    ofSetColor(10, 10, 30, trails);
    ofRect(0, 0, ofGetWindowWidth(), ofGetWindowHeight());
    
    myBackground.draw();
    
    //Loop through particles and draw them
    for ( vector<Particle>::iterator it=particles.begin(); it!=particles.end(); ) {
        it->draw();
        it++;
    }
    
    //Loop through single particles and draw them
    for ( int i = 0; i < single.size(); i++ ) {
        single[i].draw();
    }
}

//--------------------------------------------------------------
void testApp::createParticle(ofVec2f pos, float velMult, ofColor c, float size){
    Particle tmp;
    tmp.setup(pos, velMult, c, size);
    cout << velMult << endl;
    particles.push_back( tmp );
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}