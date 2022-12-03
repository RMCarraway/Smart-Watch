// Digital Watch Functions

long digitalTimer=0;
long digitalInterval= 15000;

void initDigital(){
  modeStates[0] = false;  // Uninitialize Analog
  modeStates[1] = true;   // Initialize Digital
  clearScreen();

  //draw image
  TJpgDec.drawJpg(0,0, space1,sizeof(space1));
}

void digital(){
  if(!modeStates[1]){initDigital();}
 // screenText("Digital Time", 10, 100, 4);

  if(!timeSet){
    initTime(); 
   }

   int nowSec = rtc.getSecond();
   int nowMin = rtc.getMinute();
   int nowHr = rtc.getHour();
   int nowDay = rtc.getDay();
   int nowMonth = rtc.getMonth();
   int nowYear = rtc.getYear();

   if(millis() - digitalTimer >= digitalInterval){ 
   TJpgDec.drawJpg(0,0, space1,sizeof(space1));
   tft.setTextColor(TFT_WHITE);
   if(nowHr == 0){nowHr=12;}
   tft.drawCentreString(String(nowHr),120,60,6);
   tft.drawCentreString(String(nowMin),120,120,6);
   tft.drawCentreString(String(rtc.getDate().substring(0,12)),120,20,4);
    if(nowSec<=15){
      tft.fillCircle(80, 110, 4, TFT_WHITE);
      tft.fillCircle(100, 110, 4, TFT_YELLOW);
      tft.fillCircle(140, 110, 4, TFT_YELLOW);
      tft.fillCircle(160, 110, 4, TFT_YELLOW);
      }
      if(nowSec>15 && nowSec<=30){
      tft.fillCircle(80, 110, 4, TFT_YELLOW);
      tft.fillCircle(100, 110, 4, TFT_WHITE);
      tft.fillCircle(140, 110, 4, TFT_YELLOW);
      tft.fillCircle(160, 110, 4, TFT_YELLOW);
      }
      if(nowSec>30 && nowSec<=45){
      tft.fillCircle(80, 110, 4, TFT_YELLOW);
      tft.fillCircle(100, 110, 4, TFT_YELLOW);
      tft.fillCircle(140, 110, 4, TFT_WHITE);
      tft.fillCircle(160, 110, 4, TFT_YELLOW);
      }
      if(nowSec>45){
      tft.fillCircle(80, 110, 4, TFT_YELLOW);
      tft.fillCircle(100, 110, 4, TFT_YELLOW);
      tft.fillCircle(140, 110, 4, TFT_YELLOW);
      tft.fillCircle(160, 110, 4, TFT_WHITE);
      }

   digitalTimer = millis();
   }
}
