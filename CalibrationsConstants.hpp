/*
  CalibrationsConstants.hpp

   Created on: Feb 7, 2018
       Author: biggs

       The intent of this file is to hold all of the "calibrations" (constants expected to be fine tuned) and actual
       constants (which should not change).
 */
#ifndef TESTBOARD_CALIBRATIONSCONSTANTS_HPP_
#define TESTBOARD_CALIBRATIONSCONSTANTS_HPP_

/* Enum definitions: */
 typedef enum
 {
   E_AutonPositionLeft,
   E_AutonPositionMiddle,
   E_AutonPositionRight,
   E_AutonPositionDefault,
   E_AutonPositionSz
 } T_AutonPosition;


 typedef enum
 {
   E_LED_Color_Red,
   E_LED_Color_Blue,
   E_LED_Color_Green,
   E_LED_Color_White,
   E_LED_Color_Purple,
   E_LED_Color_Yellow,
   E_LED_Color_Pink,
   E_LED_Color_Orange,
   E_LED_Color_Rainbow, // This is meant to indicate when a random mixture of colors are desired
   E_LED_Color_Multi,   // This is meant to indicate when it is desired to have the colors cycle through all of the avaiable colors above rainbow
   E_LED_Color_Black    // This is more of an "off mode", must remain at end of enum
 } T_LED_Color;

 typedef enum
 {
   E_LED_Mode0,
   E_LED_Mode1,
   E_LED_Mode2,
   E_LED_Mode3,
   E_LED_Mode4,
   E_LED_Mode5,
   E_LED_Mode6,
   E_LED_Mode7,
   E_LED_ModeSz
 } T_LED_Mode;

 typedef enum
 {
   E_RobotSideLeft,
   E_RobotSideRight,
   E_RobotSideSz
 } T_RobotSide;

 typedef enum
 {
   E_RobotDirectionForward,
   E_RobotDirectionReverse,
   E_RobotDirectionSz
 } T_RobotDirection;

 typedef enum
 {
   E_PID_Proportional,
   E_PID_Integral,
   E_PID_Derivative,
   E_PID_Sz
 } T_PID;

 const double K_WheelSpeedLagFilterGain[E_RobotSideSz] =
     {
       0.3, /* E_RobotDriveLeft    */
       0.3 /* E_RobotDriveRight  */
     };

 const double K_WheelSpeedPID_Gain[E_RobotSideSz][E_PID_Sz] =
     {
       { /* E_RobotDriveLeft */
        0.3, /* E_PID_Proportional */
        0.3, /* E_PID_Integral */
        0.3  /* E_PID_Derivative */
       },
       { /* E_RobotDriveRight  */
        0.3, /* E_PID_Proportional */
        0.3, /* E_PID_Integral */
        0.3  /* E_PID_Derivative */
       }
     };

 const double K_WheelSpeedPID_Gain[E_RobotSideSz][E_PID_Sz] =
     {
       { /* E_RobotDriveLeft */
        0.3, /* E_PID_Proportional */
        0.3, /* E_PID_Integral */
        0.3  /* E_PID_Derivative */
       },
       { /* E_RobotDriveRight  */
        0.3, /* E_PID_Proportional */
        0.3, /* E_PID_Integral */
        0.3  /* E_PID_Derivative */
       }
     };

 const double K_WheelSpeedIntegralLimit[E_RobotSideSz][E_PID_Sz] =
     {
       { /* E_RobotDriveLeft */
        0.3, /* E_PID_Proportional */
        0.3, /* E_PID_Integral */
        0.3  /* E_PID_Derivative */
       },
       { /* E_RobotDriveRight  */
        0.3, /* E_PID_Proportional */
        0.3, /* E_PID_Integral */
        0.3  /* E_PID_Derivative */
       }
     };

const double C_speedGain = 10;
const double C_SpeedFilterGain = 0.01;

const double C_ErrorP_L = 0.06;
const double C_ErrorI_L = 0.01;
const double C_ErrorD_L = 0.01;
const double C_IntergalUpperLimit_L = 0.1;
const double C_IntergalLowerLimit_L = -0.1;
const double C_FiltGain_L = 0.01;

const double C_ErrorP_R = 0.06;
const double C_ErrorI_R = 0.01;
const double C_ErrorD_R = 0.01;
const double C_IntergalUpperLimit_R = 0.1;
const double C_IntergalLowerLimit_R = -0.1;
const double C_FiltGain_R = 0.01;

const double C_ExeTime = 0.01;



#endif /* TESTBOARD_CALIBRATIONSCONSTANTS_HPP_ */
