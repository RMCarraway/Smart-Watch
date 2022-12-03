// Weather App Functions



//need weather icon and 4 other representations of conditions, numerically, graphically, words, etc.
//9 weather conditions: 9-18 icons

int tempNow = 0;
int tempMin =0;
int tempMax =0;
String humidNow;
String weatherNow;
String weatherIcon;

void initWeather(){
  modeStates[1] = false; // Uninitialize Analog
  modeStates[2] = true;  // Initialize Weather
  getWiFiWeather();
 

  clearScreen();

 TJpgDec.drawJpg(0,0,wFewClouds,sizeof(wFewClouds));
 drawWeatherIcon();
 

}

void weather(){
  if(!modeStates[2]){initWeather();}
  drawWeatherIcon();
  //screenText("Weather", 10, 100, 4);
  tft.setTextColor(TFT_WHITE);
  
  tft.drawCentreString("Temp:",100,110,4);
  tft.drawCentreString(String(tempNow),180,110,4);
  tft.drawCentreString("o",195,90,2);
  
  tft.drawCentreString("Humid %:",100,150,4);
  tft.drawCentreString(String(humidNow),180,150,4);
  
  tft.drawCentreString("Min Temp:",100,180,2);
  tft.drawCentreString(String(tempMin),180,180,2);
  
  tft.drawCentreString("Max Temp:",100,200,2);
  tft.drawCentreString(String(tempMax),180,200,2);
}

void getWiFiWeather(){
  openWiFi();
  String jsonBuffer;
  if(WiFi.status() == WL_CONNECTED){                                   //city        //key (linked to weather api account -> create your own
  String serverPath= "http://api.openweathermap.org/data/2.5/weather?id=4219762&appid=eb18358c4923620e621ee2dd2f150551";
  jsonBuffer = httpGETRequest(serverPath.c_str());
  JSONVar myObject = JSON.parse(jsonBuffer);

   String weatherNow = JSON.stringify(myObject["weather"][0]["main"]);
   weatherNow.replace("\"",0);

   String weatherIcon = JSON.stringify(myObject["weather"][0]["icon"]);
   weatherIcon.replace("\"",0);

   Serial.println(weatherIcon);
  

   // get temp info
   String tNow = JSON.stringify(myObject["main"]["temp"]);      tempNow = ktof(tNow);    
   String tMin = JSON.stringify(myObject["main"]["temp_min"]);  tempMin = ktof(tMin);
   String tMax = JSON.stringify(myObject["main"]["temp_max"]);  tempMax = ktof(tMax);
   humidNow= JSON.stringify(myObject["main"]["humidity"]);
   //String windNow= JSON.stringify(myObject["wind"]["speed"];

   
 }

closeWiFi();
}

// Converts Kelvin (as String) to Farenheit (as float)
int ktof(String k){
    float degreesK = k.toFloat();
    float degreesF = ((degreesK - 273.15) * 1.8) + 32;
    int intF = degreesF;
    return intF;
}

void drawWeatherIcon(){
  if(weatherIcon.equals("01d")){TJpgDec.drawJpg(0,0,wClear,sizeof(wClear)) ;}
  if(weatherIcon.equals("01n")){TJpgDec.drawJpg(0,0,wClear,sizeof(wClear)) ;}
  
  if(weatherIcon.equals("02d")){TJpgDec.drawJpg(0,0,wFewClouds,sizeof(wFewClouds)) ;}
  if(weatherIcon.equals("02n")){TJpgDec.drawJpg(0,0,wFewClouds,sizeof(wFewClouds)) ;}
  
  if(weatherIcon.equals("03d")){TJpgDec.drawJpg(0,0,wScatterClouds,sizeof(wScatterClouds)) ;}
  if(weatherIcon.equals("03n")){TJpgDec.drawJpg(0,0,wScatterClouds,sizeof(wScatterClouds)) ;}
  
  if(weatherIcon.equals("04d")){TJpgDec.drawJpg(0,0,wBrokenClouds,sizeof(wBrokenClouds)) ;}
  if(weatherIcon.equals("04d")){TJpgDec.drawJpg(0,0,wBrokenClouds,sizeof(wBrokenClouds)) ;}

  if(weatherIcon.equals("09d")){TJpgDec.drawJpg(0,0,wShowerRain,sizeof(wShowerRain)) ;}
  if(weatherIcon.equals("09n")){TJpgDec.drawJpg(0,0,wShowerRain,sizeof(wShowerRain)) ;}
  
  if(weatherIcon.equals("10d")){TJpgDec.drawJpg(0,0,wRain,sizeof(wRain)) ;}
  if(weatherIcon.equals("10n")){TJpgDec.drawJpg(0,0,wRain,sizeof(wRain)) ;}
  
  if(weatherIcon.equals("11d")){TJpgDec.drawJpg(0,0,wThunder,sizeof(wThunder)) ;}
  if(weatherIcon.equals("11n")){TJpgDec.drawJpg(0,0,wThunder,sizeof(wThunder)) ;}
  
  if(weatherIcon.equals("13d")){TJpgDec.drawJpg(0,0,wSnow,sizeof(wSnow)) ;}
  if(weatherIcon.equals("13n")){TJpgDec.drawJpg(0,0,wSnow,sizeof(wSnow)) ;}
  
  if(weatherIcon.equals("50d")){TJpgDec.drawJpg(0,0,wMist,sizeof(wMist)) ;}
  if(weatherIcon.equals("50n")){TJpgDec.drawJpg(0,0,wMist,sizeof(wMist)) ;}
  
 }
