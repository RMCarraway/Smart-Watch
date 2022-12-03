// Game App Functions
long gameTimer=0;
long gameInterval= 4000;

int xRead;
int yRead;  //accelerometer readings
int zRead;

int pressCount=0;
String message;

int blastNum = random(6, 12);

void initGame(){
  modeStates[2] = false; // Unitialize Weather
  modeStates[3] = true;  // Initiallize Game

  //TJpgDec.drawJpg(0,0,catGround,sizeof(catGround)) ;
  
  clearScreen();
}

void game(){                      
  if(!modeStates[3]){initGame();}
  

  buttons[2].update();
   if(buttons[2].fell()){
   pressCount++;
      
  }

   //screenText("Game", 10, 100, 4);
  tft.drawCentreString(message,120,190,2);

  if(pressCount<=blastNum){
      TJpgDec.drawJpg(0,0,catGround,sizeof(catGround)) ;
      message="Encourage him!";
    }

  if(pressCount>blastNum){
      TJpgDec.drawJpg(0,0,catFly,sizeof(catFly)) ;
      message="Blastoff!";
    }  
  
 
  
  if(millis() - gameTimer >= gameInterval){

   pressCount= pressCount-1;

    gameTimer=millis();
  }

  Serial.println(pressCount);

  }
