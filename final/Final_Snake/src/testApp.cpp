#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofSetVerticalSync( true );
    ofBackground( 0 );
    ofSetRectMode(OF_RECTMODE_CENTER);
    
    //Set up Gamepad stuff
    ofxGamepadHandler::get()->enableHotplug();
	
	//CHECK IF THERE EVEN IS A GAMEPAD CONNECTED
	if(ofxGamepadHandler::get()->getNumPads()>0){
        ofxGamepad* pad = ofxGamepadHandler::get()->getGamepad(0);
        ofAddListener(pad->onAxisChanged, this, &testApp::axisChanged);
        ofAddListener(pad->onButtonPressed, this, &testApp::buttonPressed);
        ofAddListener(pad->onButtonReleased, this, &testApp::buttonReleased);
	}
    
    gameState = 0; //Intro
    
    roundNum = 1;
    
    player1Score = 0;
    player2Score = 0;
    
    snakePlayer = 1;
    scoreModifier = 13;
    
    ofTrueTypeFont::setGlobalDpi(72);
    bitdustLarge.loadFont("fonts/bitdust2.ttf", 72);
    bitdustMedium.loadFont("fonts/bitdust2.ttf", 36);
    bitdustSmall.loadFont("fonts/bitdust2.ttf", 18);
    
    lastTime = ofGetElapsedTimef();
    timeScale = 1.0;
    currentTimeScale = 1.0;
    
    currentSnakeLength = 25;
    currentObstacleSize = 50;
    
    powerupStartTime = 0.0;
    powerupTimeBetween = 5.0;
    
    bIsPlayer1Ready = false;
    bIsPlayer2Ready = false;
    
    timeLeft = 5;
    
    mainSong.loadSound("audio/akumulator.mp3");
}

//--------------------------------------------------------------
void testApp::update(){
    
    switch (gameState) {
        case 0:
            updateIntro();
            break;
            
        case 1:
            updateGameplay();
            break;
            
        case 2:
            updateInterlude();
            break;
            
        case 3:
            updateEnd();
            break;
    }
    
    // update the sound playing system:
	ofSoundUpdate();
    
}

void testApp::updateIntro() {
    float hTitle = sin(ofGetElapsedTimef() * 0.4) * 20 + 20;
    cTitle.setHsb(hTitle, 230, 255);
    
    if ( timeLeft <= 0 ) {
        gameState = 1;
        startGameplayTime = ofGetElapsedTimef();
        powerupStartTime = ofGetElapsedTimef();
        mainSong.play();
    }
}

void testApp::updateGameplay() {
    
    //Used to figure out how long the round has been in play
    elapsedGameplayTime = ofGetElapsedTimef() - startGameplayTime;
    
    //Delta Time Stuff
    float dt = ofGetElapsedTimef() - lastTime;
    
    //Add to the length of the snake every second
    currentTime = (int)ofGetElapsedTimef();
    
    //If short powerup is active, cut the length of the snake in half
    if (bIsShort) {
        //Only reduce length once...otherwise length will end up at 1
        if (snake.snakePos.size()-1 > currentSnakeLength / 2) {
            snake.snakePos.erase(snake.snakePos.begin(), snake.snakePos.begin() + currentSnakeLength / 2);
        }
    }
    //If long powerup is active, double length of snake
    else if (bIsLong) {
        //Only add to length once...otherwise that shit cray
        if (snake.snakePos.size() - 1 < currentSnakeLength) {
            for (int i = 0; i < currentSnakeLength / 2; i++) {
                snake.addTail();
            }
        }
    }
    else {
        if (prevTime != currentTime) {
            snake.addTail();
            obstacle.obSize += 2.0;
            obstacle.obLife += 5.0;
        }
        
        currentSnakeLength = snake.snakePos.size();
    }
    
    prevTime = currentTime;
    
    //Update the snake
    snake.update( dt * timeScale );
    
    //Loop through obstacles and see if the snake has collided
    //Only check the collision if the invincible powerup is not active though
    if (!bIsInvincible) {
        for( int i = 0; i < obstacle.obList.size(); i++ ) {
            snake.checkCollision(obstacle.obList[i].pos, obstacle.obSize);
        }
    }
    
    //If wall bonus, check to see if snake has collided with wall
    if (bIsWall) {
        snake.checkBoundaryCollision();
    }
    
    //Update powerup stuff
    managePowerups();

    for (int i = 0; i < powerups.size(); i++) {
        if ( powerups[i].isDead() ) {
            powerups.erase(powerups.begin() + i);
        }
        else {
            powerups[i].checkCollision(snake.pos, obstacle.pos);
            powerups[i].update();
        }
    }
    
    if (ofGetElapsedTimef() - powerupStartTime > powerupTimeBetween) {
        Powerup p1(true, &bitdustLarge);
        Powerup p2(false, &bitdustLarge);
        powerups.push_back( p1 );
        powerups.push_back( p2 );
        
        powerupStartTime = ofGetElapsedTimef();
    }
    
    //If bomb powerup is actived, erase all obstacles on screen
    if (bIsBomb) {
        explodeObstacles();
    }
    
    for ( int i = 0; i < squares.size(); i++) {
        if (squares[i].kill()) {
            squares.erase(squares.begin() + i);
        }
        squares[i].update();
    }
    
    //Obstacle stuff
    obstacle.update( dt * timeScale );
    
    if (bIsLarge) {
        obstacle.obSize = currentObstacleSize * 2;
    }
    else {
        obstacle.obSize = currentObstacleSize;
        currentObstacleSize = obstacle.obSize;
    }
    
    //Depending on who is playing as the snake, add to the score
    if ( snakePlayer == 1) {
        //If the bonus points powerup is active, you get DOUBLE POINTS!
        if (bIsBonus) {
            player1Score += scoreModifier * 1.5;
        }
        else {
            player1Score += scoreModifier;
        }
    }
    else if ( snakePlayer == 2) {
        //If the bonus points powerup is active, you get DOUBLE POINTS!
        if (bIsBonus) {
            player2Score += scoreModifier * 1.5;
        }
        else {
            player2Score += scoreModifier;
        }
    }
    
    //If there is a collision, go to the next state
    if (snake.bHasCollided && roundNum < 6) {
        resetGameplay();
    }
    //If it's the end of the game, go to the end screen
    else if ( snake.bHasCollided && roundNum >= 6 ) {
        gameState = 3;
    }
    
    lastTime = ofGetElapsedTimef();
    
    //If slow powerup is active, we pull a Neo and go into bullet-time.
    if (bIsSlow) {
        timeScale = currentTimeScale / 2;
        timeScale += 0.005;
    }
    //If fast powerup is active, speed that shit up.
    else if (bIsFast) {
        timeScale = currentTimeScale * 1.5;
    }
    else {
        timeScale = currentTimeScale;
        timeScale += .001;
        currentTimeScale = timeScale;
    }
}

void testApp::updateInterlude() {
    introCountdown();
    
    if ( timeLeft <= 0 ) {
        roundNum++;
        gameState = 1;
        startGameplayTime = ofGetElapsedTimef();
        if (snakePlayer == 1) {
            snakePlayer = 2;
        }
        else {
            snakePlayer = 1;
        }
    }
}

void testApp::updateEnd() {
    
}

//--------------------------------------------------------------
void testApp::draw(){
    switch (gameState) {
        case 0:
            drawIntro();
            break;
        
        case 1:
            drawGameplay();
            break;
        
        case 2:
            drawInterlude();
            break;
            
        case 3:
            drawEnd();
            break;
    }
    
}

void testApp::drawIntro() {
    ofSetColor(cTitle);
    bitdustLarge.drawString("Super Snake", 350, 300);
    
    ofSetColor(255);
    bitdustMedium.drawString("Press Enter to Begin", 385, 450);
    
    ofSetColor(255);
    bitdustSmall.drawString("Player 1: ", 500, 550);
    bitdustSmall.drawString("Player 2: ", 500, 580);
    
    if (bIsPlayer1Ready) {
        ofSetColor(30,240,12);
        bitdustSmall.drawString("READY!", 625, 550);
    }
    else {
        ofSetColor(150);
        bitdustSmall.drawString("WAITING", 625, 550);
    }
    
    if (bIsPlayer2Ready) {
        ofSetColor(30,240,12);
        bitdustSmall.drawString("READY!", 625, 580);
    }
    else {
        ofSetColor(150);
        bitdustSmall.drawString("WAITING", 625, 580);
    }
    
    if ( bIsPlayer1Ready && bIsPlayer2Ready ) {
        introCountdown();
        
        ofSetColor( 255 );
        bitdustLarge.drawString(ofToString(timeLeft), 600, 680);
    }
    
}

void testApp::drawGameplay() {
    
    if (!bIsInvisible) {
        snake.draw();
    }
    obstacle.draw();
    
    if (bIsWall) {
        ofNoFill();
        ofSetLineWidth( 10.0 );
        ofSetColor(255,0,0);
        ofRect(ofGetWindowSize() / 2, ofGetWindowWidth(), ofGetWindowHeight());
    }
    
    for ( int i = 0; i < powerups.size(); i++) {
        powerups[i].draw();
    }
    
    for ( int i = 0; i < squares.size(); i++) {
        squares[i].draw();
    }
    
    //Draw interface
    ofSetColor(255);
    bitdustMedium.drawString("TIME: " + nf(elapsedGameplayTime), 20, 40);
    
    ofSetColor(255);
    bitdustMedium.drawString("ROUND " + ofToString(roundNum), 400, 40);
    
    bitdustMedium.drawString("Player 1: " + ofToString(player1Score), 830, 40);
    bitdustMedium.drawString("Player 2: " + ofToString(player2Score), 830, 80);
}

void testApp::drawInterlude() {
    ofSetColor(255);
    bitdustLarge.drawString("ROUND " + ofToString(roundNum) + " END" , 360, 200);
    
    ofNoFill();
    ofSetLineWidth(6.0);
    ofRect(ofGetWindowWidth() / 2, 350, 490, 150);
    bitdustMedium.drawString("Player 1: " + ofToString(player1Score), 430, 340);
    bitdustMedium.drawString("Player 2: " + ofToString(player2Score), 430, 390);
    
    bitdustMedium.drawString("CONTINUE IN", 500, 550);
    bitdustLarge.drawString(ofToString(timeLeft), 600, 650);
}

void testApp::drawEnd() {
    ofSetColor(255);
    
    if (player1Score > player2Score) {
        bitdustLarge.drawString("PLAYER 1 IS THE WINNER", 100, ofGetWindowHeight() / 2);
        bitdustSmall.drawString("SORRY PLAYER 2. YOU WEREN'T GOOD ENOUGH.", 380, 500);
    }
    else {
        bitdustLarge.drawString("PLAYER 2 IS THE WINNER", 100, ofGetWindowHeight() / 2);
        bitdustSmall.drawString("SORRY PLAYER 1. YOU WEREN'T GOOD ENOUGH.", 380, 500);
    }
}

//--------------------------------------------------------------
void testApp::introCountdown() {
    if (!bIsCountdownTriggered) {
        startCountdown = ofGetElapsedTimef();
        bIsCountdownTriggered = true;
    }
    
    currentTime = (int)ofGetElapsedTimef();
    
    if (prevTime != currentTime) {
        timeLeft--;
    }
    
    prevTime = currentTime;
    
}

void testApp::resetGameplay() {
    gameState = 2;
    snake.bHasCollided = false;
    
    
    timeLeft = 5;
    startCountdown = ofGetElapsedTimef();
    
    //Reset snake attributes
    snake.pos = ofGetWindowSize() /2;
    snake.snakePos.erase(snake.snakePos.begin(), snake.snakePos.end() - 25);
    
    for (int i = 0; i < snake.snakePos.size(); i++) {
        snake.snakePos[i] = snake.pos - snake.snakeSize;
    }
    
    //Destroy all obstacles and reset their attributes.
    obstacle.obList.clear();
    obstacle.obSize = 50.0;
    obstacle.obLife = 250.0;
    obstacle.moveForce = 5.0;
    
    timeScale = 1.0;
    currentTimeScale = 1.0;
    
    //Reset powerups
    bIsBonus = false;
    bIsShort = false;
    bIsSlow = false;
    bIsInvincible = false;
    bIsBomb = false;
    bIsFast = false;
    bIsLong = false;
    bIsLarge = false;
    bIsInvisible = false;
    bIsWall = false;
}

void testApp::managePowerups() {
    
    for (int i = 0; i < powerups.size(); i++) {
        //If the powerup is unactive, turn the switch to false
        if (!powerups[i].bIsActive) {
            //Snake Powerups
            if (powerups[i].name == "Bonus") {
                bIsBonus = false;
            }
            else if (powerups[i].name == "Short") {
                bIsShort = false;
            }
            else if (powerups[i].name == "Slow") {
                bIsSlow = false;
            }
            else if (powerups[i].name == "Invincible") {
                bIsInvincible = false;
            }
            else if (powerups[i].name == "Bomb") {
                bIsBomb = false;
            }
            
            //Obstacle Powerups
            else if (powerups[i].name == "Fast") {
                bIsFast = false;
            }
            else if (powerups[i].name == "Long") {
                bIsLong = false;
            }
            else if (powerups[i].name == "Large") {
                bIsLarge = false;
            }
            else if (powerups[i].name == "Invisible") {
                bIsInvisible = false;
            }
            else if (powerups[i].name == "Wall") {
                bIsWall = false;
            }
        }
        //If it is active, override the switch to false and make it true
        else if (powerups[i].bIsActive) {
            //Snake Powerups
            if (powerups[i].name == "Bonus") {
                bIsBonus = true;
            }
            else if (powerups[i].name == "Short") {
                bIsShort = true;
            }
            else if (powerups[i].name == "Slow") {
                bIsSlow = true;
            }
            else if (powerups[i].name == "Invincible") {
                bIsInvincible = true;
            }
            else if (powerups[i].name == "Bomb") {
                bIsBomb = true;
            }
            
            //Obstacle Powerups
            else if (powerups[i].name == "Fast") {
                bIsFast = true;
            }
            else if (powerups[i].name == "Long") {
                bIsLong = true;
            }
            else if (powerups[i].name == "Large") {
                bIsLarge = true;
            }
            else if (powerups[i].name == "Invisible") {
                bIsInvisible = true;
            }
            else if (powerups[i].name == "Wall") {
                bIsWall = true;
            }
        }
    }
}

void testApp::explodeObstacles() {
    if (obstacle.obList.size() > 1) {
        for (int i = 0; i < obstacle.obList.size(); i++) {
            for (int j = 0; j < 50; j++) {
                addSquares(obstacle.obList[i].pos);
            }
        }
        obstacle.obList.clear();
    }
}

void testApp::addSquares( ofVec2f pos ){
    Square s( pos );
    squares.push_back( s );
}


//--------------------------------------------------------------

//Thanks to companje for the function, from OF Forums
//Takes in a number and converts to a rounded string
string testApp::nf(float number) {
    char buffer[5];
    sprintf(buffer, "%.1f", number);
    return (string)buffer;
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    switch (key) {
        case '0':
            gameState = 0;
            break;
        
        case '1':
            gameState = 1;
            startGameplayTime = ofGetElapsedTimef();
            break;
            
        case '2':
            gameState = 2;
            break;
            
        case '3':
            gameState = 3;
            break;
    }
    
    switch (gameState) {
        case 0:
            if ( key == OF_KEY_RETURN) {
                bIsPlayer1Ready = true;
            }
            if ( key == OF_KEY_SHIFT) {
                bIsPlayer2Ready = true;
            }
            break;
            
        case 1:
            if ( snakePlayer == 1 ) {
                snake.checkKeyPress( key, 1 );
                obstacle.checkKeyPress( key, 2 );
            }
            else if ( snakePlayer == 2 ) {
                snake.checkKeyPress( key, 2 );
                obstacle.checkKeyPress( key, 1 );
            }
            break;
            
        case 2:
            break;
            
        case 3:
            break;
    }
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

    Powerup p1(true, &bitdustLarge);
    Powerup p2(false, &bitdustLarge);
    powerups.push_back( p1 );
    powerups.push_back( p2 );
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------

void testApp::axisChanged(ofxGamepadAxisEvent& e)
{
	switch (gameState) {
        case 0:
            break;
            
        case 1:
            if ( snakePlayer == 1 ) {
                if ( e.axis == 2 ) {
                    if ( e.value < -0.95 ) {
                        snake.checkGamepad(2, 1);
                    }
                    else if ( e.value > 0.95) {
                        snake.checkGamepad(3, 1);
                    }
                }
                
                if ( e.axis == 3 ) {
                    if ( e.value < -0.95 ) {
                        snake.checkGamepad(0, 1);
                    }
                    else if ( e.value > 0.95) {
                        snake.checkGamepad(1, 1);
                    }
                }
                //obstacle.checkKeyPress( key, 2 );
            }
            else if ( snakePlayer == 2 ) {
                //snake.checkKeyPress( key, 2 );
                if ( e.axis == 2 ) {
                    if ( e.value < -0.95 ) {
                        obstacle.checkGamepad(2, 1);
                    }
                    else if ( e.value > 0.95) {
                        obstacle.checkGamepad(3, 1);
                    }
                }
                
                if ( e.axis == 3 ) {
                    if ( e.value < -0.95 ) {
                        obstacle.checkGamepad(0, 1);
                    }
                    else if ( e.value > 0.95) {
                        obstacle.checkGamepad(1, 1);
                    }
                }
            }
            break;
            
        case 2:
            break;
            
        case 3:
            break;
    }

}

void testApp::buttonPressed(ofxGamepadButtonEvent& e)
{

}

void testApp::buttonReleased(ofxGamepadButtonEvent& e)
{
    switch (gameState) {
        case 0:
            if ( e.button == 11) {
                bIsPlayer1Ready = true;
                bIsPlayer2Ready = true;
            }
            break;
            
        case 1:
            if ( snakePlayer == 1 ) {
                snake.checkGamepad((int)e.button, 1);
                //obstacle.checkKeyPress( key, 2 );
            }
            else if ( snakePlayer == 2 ) {
                //snake.checkKeyPress( key, 2 );
                obstacle.checkGamepad((int)e.button, 1);
            }
            break;
            
        case 2:
            break;
            
        case 3:
            break;
    }
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
