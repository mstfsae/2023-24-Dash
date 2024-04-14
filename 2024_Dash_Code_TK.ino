

#include <CAN_config.h>
#include <ESP32CAN.h>



// ------------------- PIN Definitions -------------------------
// LOOK INTO -> Pins may not be accurate, not sure if gpio or schematic pins should be used. Currently schematic pin numbers are used with the corresponding gpio pins commented out

#define CANLOW 39 // GPIO 43
#define CANHIGH 40 // GPIO 44

#define radiator_Out_Sig 5 // GPIO 1, Analog input, LOOK INTO -> Rad temps may need calibrated due to no thermocouple circuitry
#define radiator_In_Sig 6 // GPIO 2, Analog input ^
#define rotor_FR_Sig 7 // GPIO 3 LOOK INTO -> Not sure what kind of sensor this is
#define rotor_FL_Sig 8 // GPIO 4  ^
#define pitot_Sig 9 // GPIO 5 , Analog Input, LOOK INTO -> Not entirerly sure what kind of output this will give. I think its a linearly varying voltage w/ air speed
#define flow_Out_Sig 10 // GPIO 6, Note, this one will be a bitch b/c we need to measure the frequency. I will add notes about a test plan for this
#define flow_In_Sig 11 // GPIO 7 ^
#define eight_V_Sense 12 // GPIO 8 Note, this is currently not connected on the board due to KiCAD being shit and creating stupid fucking shorts going against its entire fucking purpose... sore subject sorry
#define five_V_Sense 13 // GPIO 9 , Used for removing any offset in signal measurements usin 5V divider
#define three_V3_Sense 14 // GPIO 10, ^ except with 3V3 divider

#define shiftFive 15 // GPIO 11
#define shiftFour 16 // GPIO 12
#define shiftThree 17 // GPIO 13
#define shiftTwo 18 // GPIO 14
#define shiftOne 21 // GPIO 17
#define allShift 18 // GPIO 18

#define page 25 // This is not connected cause i am a lazy piece of shit.... this can be ignored, only here for debugging...heaven forbid

#define MISO 33 // GPIO 37
#define SCLK 32 // GPIO 36
#define MOSI 31 // GPIO 35
#define lcdCS 29 // GPIO 34
#define lcdINT 28 // GPIO 33
#define adc1CS 19 // GPIO 15
#define adc2CS 20 // GPIO 16
//--------------------------------------------------------------------------

// --------------------- Global Definitions --------------------

int dutyCycle = 255; // between 0 & 255 -> value/255 * 100 -> Percent of time lights are on.... aka brightness ----- May need debugging
bool shiftLightsActive = false;
unsigned long previousMillis = 0;
bool instage6 = true; // LOOK INTO -> i dont remember what this was for
int ledState = LOW; // LOOK INTO -> ^
const long interval = 200; // RPM Blink interval (in millis)



// ------------------------------------------------------ Functions -----------------------------------------------
// --------- Shift Lights --------
void stage0() { // Turns off all lights
  analogWrite(shiftOne, 0);
  analogWrite(shiftTwo, 0);
  analogWrite(shiftThree, 0);
  analogWrite(shiftFour, 0);
  analogWrite(shiftFive, 0);
  analogWrite(shiftAll, 0);

  shiftLightsActive = false;
}
void stage1() {
  analogWrite(shiftOne, dutyCycle);
  analogWrite(shiftTwo, 0);
  analogWrite(shiftThree, 0);
  analogWrite(shiftFour, 0);
  analogWrite(shiftFive, 0);
  analogWrite(shiftAll, 0);

  shiftLightsActive = true;
}


void stage2() {
  analogWrite(shiftOne, dutyCycle);
  analogWrite(shiftTwo, dutyCycle);
  analogWrite(shiftThree, 0);
  analogWrite(shiftFour, 0);
  analogWrite(shiftFive, 0);
  analogWrite(shiftAll, 0);

  shiftLightsActive = true;
}


void stage3() {
  analogWrite(shiftOne, dutyCycle);
  analogWrite(shiftTwo, dutyCycle);
  analogWrite(shiftThree, dutyCycle);
  analogWrite(shiftFour, 0);
  analogWrite(shiftFive, 0);
  analogWrite(shiftAll, 0);

  shiftLightsActive = true;
}


void stage4() {
  analogWrite(shiftOne, dutyCycle);
  analogWrite(shiftTwo, dutyCycle);
  analogWrite(shiftThree, dutyCycle);
  analogWrite(shiftFour, dutyCycle);
  analogWrite(shiftFive, 0);
  analogWrite(shiftAll, 0);

  shiftLightsActive = true;
}

void stage5() {
  analogWrite(shiftOne, dutyCycle);
  analogWrite(shiftTwo, dutyCycle);
  analogWrite(shiftThree, dutyCycle);
  analogWrite(shiftFour, dutyCycle);
  analogWrite(shiftFive, dutyCycle);
  analogWrite(shiftAll, 0);

  shiftLightsActive = true;
}

void stage6() {// this is the blinking red stage
  // executes while in stage 6
  int currentMillis = millis(); // Blinks lights without holding up code or using interrupt
  
  if(currentMillis - previousMillis >= interval){
    previousMillis = millis();
    if(ledState == LOW){
     analogWrite(shiftOne, 0);
     analogWrite(shiftTwo, 0);
     analogWrite(shiftThree, 0);
     analogWrite(shiftFour, 0);
     analogWrite(shiftFive, dutyCycle);
     analogWrite(shiftAll, dutyCycle);
     ledState = HIGH;
    }
     else {
     analogWrite(shiftOne, 0);
     analogWrite(shiftTwo, 0);
     analogWrite(shiftThree, 0);
     analogWrite(shiftFour, 0);
     analogWrite(shiftFive, 0);
     analogWrite(shiftAll, 0);
     ledState = LOW;
     }
  }

  shiftLightsActive = true;
 
}
// -------------------------------





// ------------------------------------------------- SETUP --------------------------------------------
void setup() {
 


// -------------------------- Multi Core Setup -------------------------------
  TaskCreatePinnedToCore(
                      CoreACode,   /* Task function. */
                      "CoreA",     /* name of task. */
                      10000,       /* Stack size of task */ // LOOK INTO THIS 
                      NULL,        /* parameter of the task */
                      1,           /* priority of the task */
                      &TaskA,      /* Task handle to keep track of created task */
                      0);          /* pin task to core 0 */                  
    delay(500); 
 //create a task that will be executed in the Task2code() function, with priority 1 and executed on core 1
  xTaskCreatePinnedToCore(
                    CoreBCode,   /* Task function. */
                    "CoreB",     /* name of task. */
                    10000,       /* Stack size of task */
                    NULL,        /* parameter of the task */
                    1,           /* priority of the task */
                    &TaskB,      /* Task handle to keep track of created task */
                    1);          /* pin task to core 1 */
  delay(500);
// -------------------------------------------------------------------------------------------------------

}// end of Void Setup


// ------------------------------------ MAIN LOOPS -----------------------------------------------
void CoreACode( void * pvParameters )
{
  // Core A Code
}

//Code running on core 2
void CoreBCode( void * pvParameters )
{
  // Core B Code
}
void loop() {
  // put your main code here, to run repeatedly:

}
