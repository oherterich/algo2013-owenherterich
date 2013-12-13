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
        pad = ofxGamepadHandler::get()->getGamepad(0);
        ofAddListener(pad->onAxisChanged, this, &testApp::axisChanged);
        ofAddListener(pad->onButtonPressed, this, &testApp::buttonPressed);
        ofAddListener(pad->onButtonReleased, this, &testApp::buttonReleased);
	}
    if(ofxGamepadHandler::get()->getNumPads()>1){
        pad2 = ofxGamepadHandler::get()->getGamepad(1);
        ofAddListener(pad2->onAxisChanged, this, &testApp::axisChanged2);
        ofAddListener(pad2->onButtonPressed, this, &testApp::buttonPressed2);
        ofAddListener(pad2->onButtonReleased, this, &testApp::buttonReleased2);
	}
    
    gameState = 0; //Intro
    
    roundNum = 1;
    
    player1Score = 0;
    player2Score = 0;
    
    snakePlayer = 1;
    obstaclePlayer = 2;
    scoreModifier = 13;
    
    ofTrueTypeFont::setGlobalDpi(72);
    bitdustLarge.loadFont("fonts/bitdust2.ttf", 84);
    bitdustMedium.loadFont("fonts/bitdust2.ttf", 36);
    bitdustSmall.loadFont("fonts/bitdust2.ttf", 18);
    
    lastTime = ofGetElapsedTimef();
    timeScale = 1.0;
    currentTimeScale = 0.8;
    
    screenMiddle.set(ofGetWindowWidth() / 2, ofGetWindowHeight() / 2);
    
    background.loadImage("img/background.png");
    instructions01.loadImage("img/instructions_01.png");
    instructions02.loadImage("img/instructions_02.png");
    player1Snake.loadImage("img/player1_snake.png");
    player2Snake.loadImage("img/player2_snake.png");
    player1Obstacle.loadImage("img/player1_obst.png");
    player2Obstacle.loadImage("img/player2_obst.png");
    
    currentSnakeLength = 25;
    currentObstacleSize = 0.5;
    
    powerupStartTime = 0.0;
    powerupTimeBetween = 5.0;
    
    bIsPlayer1Ready = false;
    bIsPlayer2Ready = false;
    
    originalObstacleSize = 150.0;
    
    timeLeft = 6;
    
    mainSong.loadSound("audio/akumulator.mp3");
    mainSong.setVolume(0.7);
    
    bomb.loadSound("audio/effects/bomb.wav");
    countdown.loadSound("audio/effects/countdown.wav");
    countdown.setVolume(0.6);
    place_obstacle.loadSound("audio/effects/place_obstacle.wav");
    place_obstacle.setMultiPlay(true);
    powerup_pickup.loadSound("audio/effects/powerup_pickup.wav");
    powerup_pickup.setMultiPlay(true);
    powerup_pickup.setVolume(0.8);
    powerup_spawn.loadSound("audio/effects/powerup_spawn.wav");
    powerup_spawn.setMultiPlay(true);
    powerup_spawn.setVolume(0.4);
    snake_collide.loadSound("audio/effects/snake_collide.wav");
    start_round.loadSound("audio/effects/start_round.wav");
    start_round.setVolume(0.8);
    
    //Add some initial particles
    for (int i = 0; i < 300; i++) {
        Square s( ofVec2f( ofRandom(-500, -100), ofRandomHeight() ), ofRandom(0, 40) );
        s.vel.set( ofRandom( 0, 2 ), ofRandom(-1, 1 ) );
        s.damping = 1.0;
        s.initTrans = 100;
        s.life = ofRandom(1000, 2500);
        s.c = ofColor( ofRandom(220, 255) );
        
        squares.push_back( s );
    }
    
    for (int i = 0; i < 25; i++) {
        LargeShape s( (int)ofRandom(2) );
        s.pos.set( ofRandomWidth(), ofRandomHeight() );
        s.vel.set( ofRandom(0, 2), ofRandom(-1, 1) );
        s.trans = 10;
        shapes.push_back( s );
    }
    
}

//--------------------------------------------------------------
void testApp::update(){
    
    for (int i = 0; i < shapes.size(); i++) {
        shapes[i].update();
    }
    
    for (int i = 0; i < squares.size(); i++) {
        if (squares[i].kill()) {
            squares.erase(squares.begin() + i);
        }
        
        if (squares[i].pos.x > ofGetWindowWidth()) {
            squares[i].pos.set( ofRandom(-500, -100), ofRandomHeight() );
            squares[i].vel.set( ofRandom( 0, 2 ), ofRandom(-1, 1 ) );
            squares[i].age = 0;
            squares[i].c = ofColor( ofRandom(220, 255) );
        }
        
        squares[i].update();
    }
    
    if (squares.size() < 300 ) {
        Square s( ofVec2f( ofRandom(-500, -100), ofRandomHeight() ), ofRandom(0, 40) );
        s.vel.set( ofRandom( 0, 2 ), ofRandom(-1, 1 ) );
        s.damping = 1.0;
        s.initTrans = 100;
        s.life = ofRandom(1500, 2000);
        s.c = ofColor( ofRandom(220, 255) );
        
        squares.push_back( s );
    }
    
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
            
        case 4:
            updateInst1();
            break;
            
        case 5:
            updateInst2();
            break;
    }
    
    // update the sound playing system:
	ofSoundUpdate();
    
}

void testApp::updateIntro() {
    float hTitle = sin(ofGetElapsedTimef() * 0.05) * 100 + 100;
    cTitle.setHsb(hTitle, 230, 255);
    
    tEnter = ofMap( sin(ofGetElapsedTimef() * 3.5), -1, 1, 0, 255 );
    
    if ( timeLeft <= 0 ) {
        gameState = 1;
        startGameplayTime = ofGetElapsedTimef();
        powerupStartTime = ofGetElapsedTimef();
        start_round.play();
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
            snake.checkCollision(obstacle.obList[i].pos, obstacle.obList[i].size * originalObstacleSize);
        }
    }
    
    //If wall bonus, check to see if snake has collided with wall
    if (bIsWall) {
        snake.checkBoundaryCollision();
    }
    
    for ( int i = 0; i < squares.size(); i++) {
        if (squares[i].kill()) {
            squares.erase(squares.begin() + i);
        }
        squares[i].update();
    }
    
    //Update powerup stuff
    managePowerups();

    for (int i = 0; i < powerups.size(); i++) {
        if (powerups[i].bIsActive) {
            powerups[i].timer();
        }
        else {
            if ( powerups[i].isDead() ) {
                powerups.erase(powerups.begin() + i);
            }
            
            powerups[i].checkCollision(snake.pos, obstacle.pos);
            powerups[i].update();
        }
    }
    
    if (ofGetElapsedTimef() - powerupStartTime > powerupTimeBetween) {
        Powerup p1(true, &bitdustLarge, snakePlayer, &powerup_pickup);
        Powerup p2(false, &bitdustLarge, obstaclePlayer, &powerup_pickup);
        powerups.push_back( p1 );
        powerups.push_back( p2 );
        
        powerupStartTime = ofGetElapsedTimef();
        
        powerup_spawn.play();
    }
    
    //If bomb powerup is actived, erase all obstacles on screen
    if (bIsBomb) {
        explodeObstacles();
    }
    
    for ( int i = 0; i < explosionSquares.size(); i++) {
        explosionSquares[i].update();
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
            snake.snakePlayer = 2;
            obstaclePlayer = 1;
            obstacle.obstaclePlayer = 1;
        }
        else {
            snakePlayer = 1;
            snake.snakePlayer = 1;
            obstaclePlayer = 2;
            obstacle.obstaclePlayer = 2;
        }
    }
}

void testApp::updateEnd() {
    
}

void testApp::updateInst1() {
    
}

void testApp::updateInst2() {
    
}

//--------------------------------------------------------------
void testApp::draw(){
    ofSetColor(255,255);
    ofPushMatrix();
    ofTranslate(ofGetWindowWidth() / 2, ofGetWindowHeight() / 2);
    background.draw(0, 0);
    ofPopMatrix();
    
    
    for ( int i = 0; i < squares.size(); i++) {
        squares[i].draw();
    }
    
    for (int i = 0; i < shapes.size(); i++) {
        shapes[i].draw();
    }
    
    ofPushMatrix();{
        float h = sin(ofGetElapsedTimef() * 0.05) * 100 + 100;
        ofColor c;
        c.setHsb(h, 230, 120);
        ofFill();
        ofSetColor(c, 30);
        ofTranslate(ofGetWindowWidth() / 2, ofGetWindowHeight() /2 );
        ofRect(0,0, ofGetWindowWidth(), ofGetWindowHeight());
    }ofPopMatrix();
        
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
            
        case 4:
            drawInst1();
            break;
            
        case 5:
            drawInst2();
            break;
    }
    if ( bToggleMiddleLine ){
    ofSetColor(255,0,0);
    ofLine(0, screenMiddle.y, ofGetWindowWidth(), screenMiddle.y);
    ofLine(screenMiddle.x, 0, screenMiddle.x, ofGetWindowHeight());
    }
}

void testApp::drawIntro() {
    ofSetColor(cTitle);
    bitdustLarge.drawString("Super Snake", screenMiddle.x - 340, screenMiddle.y);
    
    if (!bIsCountdownTriggered) {
        ofSetColor(255, tEnter);
        bitdustMedium.drawString("Press 'A' to Begin", screenMiddle.x-210, screenMiddle.y + 100);
        
        ofSetColor(255);
        bitdustSmall.drawString("Player 1: ", screenMiddle.x - 100, screenMiddle.y + 190);
        bitdustSmall.drawString("Player 2: ", screenMiddle.x - 100, screenMiddle.y + 220);
        
        if (bIsPlayer1Ready) {
            ofSetColor(30,240,12);
            bitdustSmall.drawString("READY!", screenMiddle.x + 25, screenMiddle.y + 190);
        }
        else {
            ofSetColor(150);
            bitdustSmall.drawString("WAITING", screenMiddle.x + 25, screenMiddle.y + 190);
        }
        
        if (bIsPlayer2Ready) {
            ofSetColor(30,240,12);
            bitdustSmall.drawString("READY!", screenMiddle.x + 25, screenMiddle.y + 220);
        }
        else {
            ofSetColor(150);
            bitdustSmall.drawString("WAITING", screenMiddle.x + 25, screenMiddle.y + 220);
        }
        
        ofSetColor(150);
        bitdustSmall.drawString("PRESS 'Y' FOR INSTRUCTIONS", screenMiddle.x - 160, ofGetWindowHeight() - 40);
    }
    
    if ( bIsPlayer1Ready && bIsPlayer2Ready ) {
        introCountdown();
        
        ofSetColor( 255 );
        bitdustLarge.drawString(ofToString(timeLeft), 600, 640);
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
        ofRect(ofGetWindowSize() / 2, ofGetScreenWidth(), ofGetScreenHeight());
    }
    
    for ( int i = 0; i < powerups.size(); i++) {
        powerups[i].draw();
    }
    
    for ( int i = 0; i < explosionSquares.size(); i++) {
        explosionSquares[i].draw();
    }
    
    
    //Draw interface
    ofSetColor(255);
    bitdustMedium.drawString("TIME: " + nf(elapsedGameplayTime), 20, 40);
    
    ofSetColor(255);
    bitdustMedium.drawString("ROUND " + ofToString(roundNum), screenMiddle.x - 200, 40);
    
    bitdustMedium.drawString("Player 1: " + ofToString(player1Score), ofGetWindowWidth() - 460, 40);
    bitdustMedium.drawString("Player 2: " + ofToString(player2Score), ofGetWindowWidth() - 460, 80);
}

void testApp::drawInterlude() {
    ofSetColor(255);
    bitdustLarge.drawString("ROUND " + ofToString(roundNum) + " END" , screenMiddle.x - 320, screenMiddle.y - 200);
    
    ofNoFill();
    ofSetLineWidth(6.0);
    ofRect(screenMiddle.x, screenMiddle.y - 50, 490, 150);
    bitdustMedium.drawString("Player 1: " + ofToString(player1Score), screenMiddle.x - 215, screenMiddle.y - 65);
    bitdustMedium.drawString("Player 2: " + ofToString(player2Score), screenMiddle.x - 215, screenMiddle.y - 15);
    
    bitdustMedium.drawString("CONTINUE IN", screenMiddle.x - 135, screenMiddle.y + 200);
    bitdustLarge.drawString(ofToString(timeLeft), screenMiddle.x - 25, screenMiddle.y + 300);
    
    //Draw what role players will take next
    bitdustMedium.drawString("Player 1", screenMiddle.x - 500, screenMiddle.y + 150);
    bitdustMedium.drawString("Player 2", screenMiddle.x + 280, screenMiddle.y + 150);
    
    if (obstaclePlayer == 1) {
        ofPushMatrix();{
            ofTranslate(screenMiddle.x - 400, screenMiddle.y + 250);
            player1Snake.draw(0,0);
        }ofPopMatrix();
        
        ofPushMatrix();{
            ofTranslate(screenMiddle.x + 390, screenMiddle.y + 250);
            player2Obstacle.draw(0,0);
        }ofPopMatrix();
    }
    else {
        ofPushMatrix();{
            ofTranslate(screenMiddle.x - 400, screenMiddle.y + 250);
            player1Obstacle.draw(0,0);
        }ofPopMatrix();
        
        ofPushMatrix();{
            ofTranslate(screenMiddle.x + 390, screenMiddle.y + 250);
            player2Snake.draw(0,0);
        }ofPopMatrix();
    }
}

void testApp::drawEnd() {
    ofSetColor(255);
    
    if (player1Score > player2Score) {
        bitdustLarge.drawString("PLAYER 1 IS", screenMiddle.x - 300, screenMiddle.y);
        bitdustLarge.drawString("THE WINNER", screenMiddle.x - 290, screenMiddle.y + 80);
        bitdustSmall.drawString("SORRY PLAYER 2. YOU WEREN'T GOOD ENOUGH.", screenMiddle.x - 250, screenMiddle.y + 170);
    }
    else {
        bitdustLarge.drawString("PLAYER 2 IS", screenMiddle.x - 325, screenMiddle.y);
        bitdustLarge.drawString("THE WINNER", screenMiddle.x - 290, screenMiddle.y + 80);
        bitdustSmall.drawString("SORRY PLAYER 1. YOU WEREN'T GOOD ENOUGH.", screenMiddle.x - 250, screenMiddle.y + 170);
    }
}

void testApp::drawInst1() {
    ofPushMatrix();{
        ofSetColor(255,255);
        ofTranslate(screenMiddle);
        instructions01.draw(0,0);
    }ofPopMatrix();
    
    ofSetColor(150);
    bitdustSmall.drawString("PRESS 'A' TO CONTINUE", screenMiddle.x - 125, ofGetWindowHeight() - 40);
    
}

void testApp::drawInst2() {
    ofPushMatrix();{
        ofSetColor(255,255);
        ofTranslate(screenMiddle);
        instructions02.draw(0,0);
    }ofPopMatrix();
    
    ofSetColor(150);
    bitdustSmall.drawString("PRESS 'A' TO CONTINUE", screenMiddle.x - 125, ofGetWindowHeight() - 40);
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
        countdown.play();
    }
    
    prevTime = currentTime;
    
}

void testApp::resetGameplay() {
    gameState = 2;
    snake.bHasCollided = false;
    
    snake_collide.play();
    
    timeLeft = 6;
    startCountdown = ofGetElapsedTimef();
    
    //Reset snake attributes
    snake.pos.set(100, ofGetWindowHeight() / 2);
    snake.vel.set(5, 0);
    snake.snakePos.erase(snake.snakePos.begin(), snake.snakePos.end() - 25);
    
    for (int i = 0; i < snake.snakePos.size(); i++) {
        snake.snakePos[i] = snake.pos - snake.snakeSize;
    }
    
    //Destroy all obstacles and reset their attributes.
    obstacle.obList.clear();
    obstacle.obSize = 0.5;
    obstacle.obLife = 250.0;
    obstacle.moveForce = 5.0;
    obstacle.pos = ofGetWindowSize() / 2;
    obstacle.vel.set( 0, 0 );
    
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
    
    powerups.clear();
}

void testApp::resetEntireGame() {
    snake.bHasCollided = false;
    
    timeLeft = 6;
    startCountdown = ofGetElapsedTimef();
    
    //Reset snake attributes
    snake.pos.set(100, ofGetWindowHeight() / 2);
    snake.vel.set(5, 0);
    snake.snakePos.erase(snake.snakePos.begin(), snake.snakePos.end() - 25);
    
    for (int i = 0; i < snake.snakePos.size(); i++) {
        snake.snakePos[i] = snake.pos - snake.snakeSize;
    }
    
    //Destroy all obstacles and reset their attributes.
    obstacle.obList.clear();
    obstacle.obSize = 0.5;
    obstacle.obLife = 250.0;
    obstacle.moveForce = 5.0;
    obstacle.pos = ofGetWindowSize() / 2;
    obstacle.vel.set( 0, 0 );
    
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
    
    powerups.clear();
    
    gameState = 0; //Intro
    
    roundNum = 1;
    
    player1Score = 0;
    player2Score = 0;
    
    snakePlayer = 1;
    obstaclePlayer = 2;
    snake.snakePlayer = 1;
    obstacle.obstaclePlayer = 2;
    scoreModifier = 13;
    
    lastTime = ofGetElapsedTimef();
    timeScale = 1.0;
    currentTimeScale = 0.8;
    
    currentSnakeLength = 25;
    currentObstacleSize = 0.5;
    
    powerupStartTime = 0.0;
    powerupTimeBetween = 5.0;
    
    bIsPlayer1Ready = false;
    bIsPlayer2Ready = false;
    
    bIsCountdownTriggered = false;
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
        bomb.play();
    }
}

void testApp::addSquares( ofVec2f pos ){
    if (snakePlayer == 1) {
        Square s( pos, 140 );
        explosionSquares.push_back( s );
    }
    else {
        Square s( pos, 20);
        explosionSquares.push_back( s );
    }
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
            
        case '4':
            gameState = 4;
            break;
            
        case '5':
            gameState = 5;
            break;
            
        case 'l':
            bToggleMiddleLine = !bToggleMiddleLine;
            break;
    }
    
    switch (gameState) {
        case 0:
            if ( key == OF_KEY_ALT) {
                bIsPlayer1Ready = true;
            }
            if ( key == ' ' ) {
                bIsPlayer2Ready = true;
            }
            if ( key == 'i' || key == 'I' ) {
                gameState = 4;
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
            if ( key == ' ' || key == OF_KEY_ALT) {
                resetEntireGame();
            }
            break;
            
        case 4:
            if ( key == ' ' || key == OF_KEY_ALT) {
                gameState = 5;
            }
            break;
            
        case 5:
            if ( key == OF_KEY_ALT) {
                gameState = 0;
            }
            if ( key == ' ' ) {
                gameState = 0;
            }
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

    Powerup p1(true, &bitdustLarge, snakePlayer, &powerup_pickup);
    Powerup p2(false, &bitdustLarge, obstaclePlayer, &powerup_pickup);
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
            }
            else if ( snakePlayer == 2 ) {
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
            }
            if ( e.button == 14) {
                gameState = 4;
            }
            break;
            
        case 1:
            if ( snakePlayer == 1 ) {
                if ( e.button == 11 ){
                    snake.checkGamepad((int)e.button, 1);
                }
            }
            else if ( snakePlayer == 2 ) {
                if ( e.button == 11 ){
                    obstacle.checkGamepad((int)e.button, 1);
                }
            }
            break;
            
        case 2:
            break;
            
        case 3:
            if ( e.button == 11) {
                player1Score = 0;
                player2Score = 0;
                snakePlayer = 1;
                obstaclePlayer = 2;
                resetGameplay();
                gameState == 0;
            }
            break;
            
        case 4:
            if ( e.button == 11) {
                gameState = 5;
            }
            break;
            
        case 5:
            if ( e.button == 11) {
                gameState = 0;
            }
            break;
    }
}

void testApp::axisChanged2(ofxGamepadAxisEvent& e)
{
	switch (gameState) {
        case 0:
            break;
            
        case 1:
            if ( snakePlayer == 2 ) {
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
            }
            else if ( snakePlayer == 1 ) {
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

void testApp::buttonPressed2(ofxGamepadButtonEvent& e)
{
    
}

void testApp::buttonReleased2(ofxGamepadButtonEvent& e)
{
    switch (gameState) {
        case 0:
            if ( e.button == 11) {
                bIsPlayer2Ready = true;
            }
            if ( e.button == 14) {
                gameState = 4;
            }
            break;
            
        case 1:
            if ( snakePlayer == 2 ) {
                if ( e.button == 11 ){
                    snake.checkGamepad((int)e.button, 1);
                }
            }
            else if ( snakePlayer == 1 ) {
                if ( e.button == 11 ){
                    obstacle.checkGamepad((int)e.button, 1);
                }
            }
            break;
            
        case 2:
            break;
            
        case 3:
            if ( e.button == 11) {
                resetGameplay();
                player1Score = 0;
                player2Score = 0;
                snakePlayer = 1;
                obstaclePlayer = 2;
                gameState = 0;
                roundNum = 0;
            }
            break;
            
        case 4:
            if ( e.button == 11) {
                gameState = 5;
            }
            break;
            
        case 5:
            if ( e.button == 11) {
                gameState = 0;
            }
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
