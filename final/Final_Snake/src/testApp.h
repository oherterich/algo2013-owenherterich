#pragma once

#include "ofMain.h"

#include "ofxOsc.h"

#include "Snake.h"
#include "Obstacle.h"

class testApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
    /*********************
     Game State Conditions
     0: Intro screen
     1: Regular Gameplay
     2: Between Rounds
     3: End Screen
    **********************/
    int gameState;
    int roundNum;
    
    int player1Score;
    int player2Score;
    
    ofTrueTypeFont bitdustLarge;
    ofTrueTypeFont bitdustMedium;
    ofTrueTypeFont bitdustSmall;
    
    float lastTime;
    float timeScale;
    
    /*********************
        INTRO STUFF
    **********************/
    void updateIntro();
    void drawIntro();
    void introCountdown();

    ofColor cTitle;
    
    bool bIsPlayer1Ready;
    bool bIsPlayer2Ready;
    bool bIsCountdownTriggered;
    
    float startCountdown;
    int timeLeft;
    int currentTime;
    int prevTime;
    
    /*********************
        GAMEPLAY STUFF
     **********************/
    void updateGameplay();
    void drawGameplay();
    void resetGameplay();
    
    float startGameplayTime;
    float elapsedGameplayTime;
    
    int snakePlayer;
    
    /*********************
        INTERLUDE  STUFF
     **********************/
    void updateInterlude();
    void drawInterlude();
    
    
    /*********************
        END STUFF
     **********************/
    void updateEnd();
    void drawEnd();
    
    /*********************
        OSC STUFF
     **********************/
    ofxOscSender mSender;
    ofxOscReceiver mReceiver;
    void sendMsg();
    void receiveMsg();
    
    string nf(float number);
    
    Snake snake;
    Obstacle obstacle;
    
    vector<ofVec2f> obstacles;
    float obstacleSize;
		
};