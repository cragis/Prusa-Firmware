#ifndef PINS_H
#define PINS_H

#include "boards.h"

#define LARGE_FLASH true









#if MOTHERBOARD == BOARD_MKS_BASE
  #define ELECTRONICS "MKS Base"
  #define KNOWN_BOARD
  #ifndef __AVR_ATmega2560__
    #error Oops!  Make sure you have 'Arduino Mega 2560' selected from the 'Tools -> Boards' menu.
  #endif



  // filament runout sensor (NOT SUPPORTED)
  #define FR_SENS 21

  // prusa multimaterial support (NOT SUPPORTED)
  #ifdef SNMM
  
  #define E_MUX0_PIN 17
  #define E_MUX1_PIN 16
  #define E_MUX2_PIN 84
  
  
  #endif

  
  #define LARGE_FLASH true

  // core pins
  #define X_STEP_PIN 54
  #define X_DIR_PIN 55
  #define X_MIN_PIN 3
  #define X_MAX_PIN 2
  #define X_ENABLE_PIN 38

  #define Y_STEP_PIN 60
  #define Y_DIR_PIN 61
  #define Y_MIN_PIN 14
  #define Y_MAX_PIN 15
  #define Y_ENABLE_PIN 56
  
  #define Z_STEP_PIN 46
  #define Z_DIR_PIN 48
  #define Z_MIN_PIN 18
  #define Z_MAX_PIN 19
  #define Z_ENABLE_PIN 62
  

  // no pins for microstepping on ramps - must be disabled because some map to pins RAMPS uses for thermistors.
 // #define X_MS1_PIN 40
 // #define X_MS2_PIN 41
 // #define Y_MS1_PIN 69
 // #define Y_MS2_PIN 39
 // #define Z_MS1_PIN 68
 // #define Z_MS2_PIN 67
 // #define E0_MS1_PIN 65
 // #define E0_MS2_PIN 66
  
  // The SDSS pin uses a different pin mapping from file Sd2PinMap.h
  #define SDSS               53

  #ifndef SDSUPPORT
    // these pins are defined in the SD library if building with SD support
    #define SCK_PIN          52
    #define MISO_PIN         50
    #define MOSI_PIN         51
  #endif
  
  #define BEEPER 37

  #define BTN_EN1 31
  #define BTN_EN2 33
  #define BTN_ENC 35

  #define SDCARDDETECT 49
  
  #define LCD_PINS_RS 16
  #define LCD_PINS_ENABLE 17
  #define LCD_PINS_D4 23
  #define LCD_PINS_D5 25
  #define LCD_PINS_D6 27
  #define LCD_PINS_D7 29
  
  #define E0_STEP_PIN         26
  #define E0_DIR_PIN          28
  #define E0_ENABLE_PIN       24

  #define LED_PIN            -1 // TODO what is this for?
  #define KILL_PIN           41 //80 with Smart Controller LCD
  #define SUICIDE_PIN        -1  //PIN that has to be turned on right after start, to keep power flowing.
  #define SDPOWER            -1


  #define HEATER_0_PIN 10
  #define HEATER_1_PIN -1 // was 7
  #define HEATER_2_PIN -1
  #define HEATER_BED_PIN 8

  // temperature pins
  #define TEMP_BED_PIN 14
  #define TEMP_0_PIN 13
  #define TEMP_1_PIN 15
  #define TEMP_2_PIN -1


  // TODO figure out fans
  #define FAN_PIN 9
  #define FAN_1_PIN 7
  #define PS_ON_PIN 71

// The Z2 axis, if any, should be the next open extruder port
#ifdef Z_DUAL_STEPPER_DRIVERS

    #define Z2_STEP_PIN   36
    #define Z2_DIR_PIN    34
    #define Z2_ENABLE_PIN 30
 
#endif
  // looks like digitpot stuff all hangs off #ifdef MOTOR_CURRENT_PWM_XY_PIN
  //#define MOTOR_CURRENT_PWM_XY_PIN 46
  //#define MOTOR_CURRENT_PWM_Z_PIN 45
  //#define MOTOR_CURRENT_PWM_E_PIN 44
  
#endif




#ifndef KNOWN_BOARD
#error Unknown MOTHERBOARD value in configuration.h
#endif

//List of pins which to ignore when asked to change by gcode, 0 and 1 are RX and TX, do not mess with those!
#define _E0_PINS E0_STEP_PIN, E0_DIR_PIN, E0_ENABLE_PIN, HEATER_0_PIN,
#if EXTRUDERS > 1
  #define _E1_PINS E1_STEP_PIN, E1_DIR_PIN, E1_ENABLE_PIN, HEATER_1_PIN,
#else
  #define _E1_PINS
#endif
#if EXTRUDERS > 2
  #define _E2_PINS E2_STEP_PIN, E2_DIR_PIN, E2_ENABLE_PIN, HEATER_2_PIN,
#else
  #define _E2_PINS
#endif

#ifdef X_STOP_PIN
  #if X_HOME_DIR < 0
    #define X_MIN_PIN X_STOP_PIN
    #define X_MAX_PIN -1
  #else
    #define X_MIN_PIN -1
    #define X_MAX_PIN X_STOP_PIN
  #endif
#endif

#ifdef Y_STOP_PIN
  #if Y_HOME_DIR < 0
    #define Y_MIN_PIN Y_STOP_PIN
    #define Y_MAX_PIN -1
  #else
    #define Y_MIN_PIN -1
    #define Y_MAX_PIN Y_STOP_PIN
  #endif
#endif

#ifdef Z_STOP_PIN
  #if Z_HOME_DIR < 0
    #define Z_MIN_PIN Z_STOP_PIN
    #define Z_MAX_PIN -1
  #else
    #define Z_MIN_PIN -1
    #define Z_MAX_PIN Z_STOP_PIN
  #endif
#endif


#define SENSITIVE_PINS {0, 1, X_STEP_PIN, X_DIR_PIN, X_ENABLE_PIN, X_MIN_PIN, X_MAX_PIN, Y_STEP_PIN, Y_DIR_PIN, Y_ENABLE_PIN, Y_MIN_PIN, Y_MAX_PIN, Z_STEP_PIN, Z_DIR_PIN, Z_ENABLE_PIN, Z_MIN_PIN, Z_MAX_PIN, PS_ON_PIN, \
                        HEATER_BED_PIN, FAN_PIN,                  \
                        _E0_PINS _E1_PINS _E2_PINS             \
                        analogInputToDigitalPin(TEMP_0_PIN), analogInputToDigitalPin(TEMP_1_PIN), analogInputToDigitalPin(TEMP_2_PIN), analogInputToDigitalPin(TEMP_BED_PIN) }

#endif //__PINS_H
