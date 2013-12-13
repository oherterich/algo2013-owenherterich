#pragma once

#include "ofMain.h"

#include "ofxGamepadHandler.h"

#include "Snake.h"
#include "Obstacle.h"
#include "Powerup.h"
#include "Square.h"
#include "LargeShape.h"

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
     4: Instructions
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
    
    ofImage background;
    
    /*********************
        INTRO STUFF
    **********************/
    void updateIntro();
    void drawIntro();
    void introCountdown();

    ofColor cTitle;
    float tEnter;
    
    bool bIsPlayer1Ready;
    bool bIsPlayer2Ready;
    bool bIsCountdownTriggered;
    
    float startCountdown;
    int timeLeft;
    int currentTime;
    int prevTime;
    
    ofPoint screenMiddle;
    bool bToggleMiddleLine;
    
    /*********************
        GAMEPLAY STUFF
     **********************/
    void updateGameplay();
    void drawGameplay();
    void resetGameplay();
    
    float startGameplayTime; //When did you start round 1?
    float elapsedGameplayTime; //How long have you been playing?
    
    int snakePlayer; //Who is playing as the snake?
    int obstaclePlayer; //Who is playing as the obstacle?
    
    int scoreModifier; //Increase for faster points
    float currentTimeScale; //Keep track of orig. game speed
    
    int currentSnakeLength; //Keep track of orig. snake length
    float currentObstacleSize; //Keep track of orig. obst. size
 
    float originalObstacleSize; //Original size, in px
    
    float invisibleLength;
    
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
    void addSquares( ofVec2f pos );
    
    //Snake Powerups
    bool bIsBonus = false;
    bool bIsShort = false;
    bool bIsSlow = false;
    bool bIsInvincible = false;
    bool bIsBomb = false;
    
    //Obstacle Powerups
    bool bIsFast = false;
    bool bIsLong = false;
    bool bIsLarge = false;
    bool bIsInvisible = false;
    bool bIsWall = false;
    
    float powerupStartTime;
    float powerupTimeBetween;
        
    /*********************
        AUDIO STUFF
     **********************/
    ofSoundPlayer mainSong;
    ofSoundPlayer bomb, countdown, place_obstacle, powerup_pickup, powerup_spawn, snake_collide, start_round; //Effects
    
    
    /*********************
        GAMEPAD STUFF
     **********************/
    ofxGamepad* pad;
    ofxGamepad* pad2;
    
    void axisChanged(ofxGamepadAxisEvent &e);
    void buttonPressed(ofxGamepadButtonEvent &e);
    void buttonReleased(ofxGamepadButtonEvent &e);
    
    void axisChanged2(ofxGamepadAxisEvent &e);
    void buttonPressed2(ofxGamepadButtonEvent &e);
    void buttonReleased2(ofxGamepadButtonEvent &e);

    
    
    string nf(float number);
    
    Snake snake;
    Obstacle obstacle;
    vector<Powerup> powerups;
    vector<Square>  squares;
    vector<Square>  explosionSquares;
    vector<LargeShape> shapes;
};
