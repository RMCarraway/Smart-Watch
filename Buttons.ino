// Functions for Buttons
#include <Bounce2.h>                  // Include Debounce Library

int buttonPins[] = {25, 26, 27};      // Set Button Pins
int numButtons = 3;                   // Declare Number of Buttons
Bounce * buttons = new Bounce[3];     // Declare Button Object Array

// Initialize All Buttons
void initButtons(){
  for (int i = 0; i < numButtons; i++) {
    buttons[i].attach( buttonPins[i], INPUT);
    buttons[i].interval(25);
  }
}

// Read All Buttons
void readButtons(){
  // Write a few lines of code that checks if buttons[0] has been pushed. If it has, call the sleepToggle() function
  buttons[0].update();
  if(buttons[0].rose()){
    sleepToggle(); 
    }

  // Write a few lines of code tthat checks if buttons[1] has been pushed. If it has, increase the value of curMode. 
  // Use the mod function (%) to make curMode go back to 0 if that last mode has been reached
   buttons[1].update();
   if(buttons[1].rose()){
   curMode= (curMode +1) % numModes;
      
  }
}
