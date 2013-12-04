#pragma once

#include "ofMain.h"

#include "ofxGamepadHandler.h"

#include "Snake.h"
#include "Obstacle.h"
#include "Powerup.h"

class testApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
    
        void axisChanged(ofxGamepadAxisEvent &e);
        void buttonPressed(ofxGamepadButtonEvent &e);
        void buttonReleased(ofxGamepadButtonEvent &e);

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
    
    float startGameplayTime; //When did you start round 1?
    float elapsedGameplayTime; //How long have you been playing?
    
    int snakePlayer; //Who is playing as the snake?
    
    int scoreModifier; //Increase for faster points
    float currentTimeScale; //Keep track of orig. game speed
    
    int currentSnakeLength; //Keep track of orig. snake length
    int currentObstacleSize; //Keep track of orig. obst. size
    
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
     POWERUP STUFF
     **********************/
    
    void managePowerups(); //Turns on/off powerup switches
    void explodeObstacles(); //Removes obstacles (w/ bomb)
    
    //Snake Powerups
    bool bIsBonus = false; //DONE
    bool bIsShort = false; //DONE
    bool bIsSlow = false; //DONE
    bool bIsInvincible = false; //DONE
    bool bIsBomb = false; //DONE
    
    //Obstacle Powerups
    bool bIsFast = false; //DONE
    bool bIsLong = false; //DONE
    bool bIsLarge = false; //DONE
    bool bIsInvisible = false; //DONE
    bool bIsWall = false; //DONE
    
    float powerupStartTime;
    float powerupTimeBetween;
    
    /*********************
        AUDIO STUFF
     **********************/
    ofSoundPlayer mainSong;
    
    
    
    string nf(float number);
    
    Snake snake;
    Obstacle obstacle;
    vector<Powerup> powerups;
    
    vector<ofVec2f> obstacles;
    float obstacleSize;
		
};
