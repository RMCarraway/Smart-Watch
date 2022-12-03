// Analog Watch Functions

TFT_eSprite sTime = TFT_eSprite(&tft);
TFT_eSprite mTime = TFT_eSprite(&tft);
TFT_eSprite hTime = TFT_eSprite(&tft);
int lastSec=0;


void initAnalog(){
  modeStates[3] = false; // Uninitialize Game
  modeStates[0] = true;  // Initialize Analog
  clearScreen();         // Clear the Screen

  TJpgDec.drawJpg(0,0,space2,sizeof(space2));
}

void analog(){
  if(!modeStates[0]){initAnalog();}                                 // Initialize Analog Time
  //screenText("Analog Time", 10, 100, 4);
  if(!timeSet){
    initTime();
    }
  
  if(lastSec != rtc.getSecond()){
   TJpgDec.drawJpg(0,0,space2,sizeof(space2));
   lastSec=rtc.getSecond();
    }
    drawSecond();
    drawMinute();
    drawHour();
}


void drawSecond(){
  int w = 2;
  int h = 70;  
  int nowSec = rtc.getSecond();
  int sAngle = (360/60)* nowSec;

  tft.setPivot(120,120);
  sTime.createSprite(w, h);
  sTime.fillSprite(0x76fb);
  sTime.setPivot(w/2, h);
  sTime.pushRotated(sAngle);
}

void drawMinute(){
  int w = 4;
  int h = 70;  
  int nowMin = rtc.getMinute();
  int mAngle = (360/60)* nowMin;

  tft.setPivot(120,120);
  mTime.createSprite(w, h);
  mTime.fillSprite(0xF79E);
  mTime.setPivot(w/2, h);
  mTime.pushRotated(mAngle);
}

void drawHour(){
  int w = 6;
  int h = 55;  
  int nowHour = rtc.getHour();
  int hAngle = (360/12)* nowHour;

  tft.setPivot(120,120);
  hTime.createSprite(w, h);
  hTime.fillSprite(0xF79E);
  hTime.setPivot(w/2, h);
  hTime.pushRotated(hAngle);
}
