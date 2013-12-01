#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofSetVerticalSync( true );
    ofBackground( 0 );
    ofSetRectMode(OF_RECTMODE_CENTER);
    
    gameState = 0; //Intro
    
    roundNum = 1;
    
    player1Score = 0;
    player2Score = 0;
    
    snakePlayer = 1;
    
    ofTrueTypeFont::setGlobalDpi(72);
    bitdustLarge.loadFont("fonts/bitdust2.ttf", 72);
    bitdustMedium.loadFont("fonts/bitdust2.ttf", 36);
    bitdustSmall.loadFont("fonts/bitdust2.ttf", 18);
    
    lastTime = ofGetElapsedTimef();
    timeScale = 1.0;
    
    bIsPlayer1Ready = false;
    bIsPlayer2Ready = false;
    
    timeLeft = 5;
    
    mSender.setup("localhost", 12345);
    mReceiver.setup(12345);
    
    obstacleSize = 25.0;
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
    
}

void testApp::updateIntro() {
    float hTitle = sin(ofGetElapsedTimef() * 0.4) * 20 + 20;
    cTitle.setHsb(hTitle, 230, 255);
    
    if ( timeLeft <= 0 ) {
        gameState = 1;
        startGameplayTime = ofGetElapsedTimef();
    }
}

void testApp::updateGameplay() {
    
    //Used to figure out how long the round has been in play
    elapsedGameplayTime = ofGetElapsedTimef() - startGameplayTime;
    
    //Delta Time Stuff
    float dt = ofGetElapsedTimef() - lastTime;
    
    
  //  if (snakePlayer == 1) {
    
        //Add to the length of the snake every second
        currentTime = (int)ofGetElapsedTimef();
        
        if (prevTime != currentTime) {
            snake.addTail();
            obstacle.obSize += 2.0;
            obstacle.obLife += 5.0;
        }
        
        prevTime = currentTime;
        
        //Update the snake
        snake.update( dt * timeScale );
        
        //Loop through obstacles and see if the snake has collided
        for( int i = 0; i < obstacle.obList.size(); i++ ) {
            snake.checkCollision(obstacle.obList[i].pos, obstacle.obSize);
        }
        
  //  }
    
   // else if ( snakePlayer == 2 ) {
        obstacle.update();
   // }
    
    //Depending on who is playing as the snake, add to the score
    if ( snakePlayer == 1) {
        player1Score += 13;
    }
    else if ( snakePlayer == 2) {
        player2Score += 13;
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
    timeScale += .001;
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
    
    ofSetColor(255);
    bitdustMedium.drawString("TIME: " + nf(elapsedGameplayTime), 20, 40);
    
    bitdustMedium.drawString("ROUND " + ofToString(roundNum), 400, 40);
    
    bitdustMedium.drawString("Player 1: " + ofToString(player1Score), 830, 40);
    bitdustMedium.drawString("Player 2: " + ofToString(player2Score), 830, 80);
    
   // if ( snakePlayer == 1 ) {
        snake.draw();
   // }
   // else if ( snakePlayer == 2 ) {
        obstacle.draw();
   // }
    
    for( int i = 0; i < obstacles.size(); i++ ) {
        ofSetColor(255,255,0);
        ofRect(obstacles[i], obstacleSize, obstacleSize);
    }
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
    
    obstacle.obList.clear();
    obstacle.obSize = 50.0;
    obstacle.obLife = 250.0;
    obstacle.moveForce = 5.0;
    
    snake.snakePos.erase(snake.snakePos.begin(), snake.snakePos.end() - 25);
    snake.pos.set(ofGetWindowSize() / 2);
    
    timeScale = 1.0;
}



//--------------------------------------------------------------
void testApp::sendMsg() {
    ofxOscMessage m;
    m.setAddress("/snake/pos");
    m.addFloatArg(snake.pos.x);
    m.addFloatArg(snake.pos.y);
    
    mSender.sendMessage( m );
}

void testApp::receiveMsg() {
    while ( mReceiver.hasWaitingMessages() ) {
        ofxOscMessage m;
        mReceiver.getNextMessage( &m );
        
        string addr = m.getAddress();
    }
    
}


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
            drawInterlude();
            break;
            
        case 3:
            drawEnd();
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

    ofVec2f p;
    p.set(x, y);
    obstacles.push_back( p );
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
