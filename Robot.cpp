/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include <iostream>
#include <string>


#include <Drive/DifferentialDrive.h>
#include <Joystick.h>
#include <SampleRobot.h>
#include <SmartDashboard/SendableChooser.h>
#include <SmartDashboard/SmartDashboard.h>
#include <Spark.h>
#include <Timer.h>
#include "WPILib.h"
#include "Joystick.h"
//#include "LiveWindow.h"
#include "ctre/Phoenix.h"
//#include "const.h"
#include "ADXRS450_Gyro.h"

/**
 * This is a demo program showing the use of the DifferentialDrive class.
 * The SampleRobot class is the base of a robot application that will
 * automatically call your Autonomous and OperatorControl methods at the right
 * time as controlled by the switches on the driver station or the field
 * controls.
 *
 * WARNING: While it may look like a good choice to use for your code if you're
 * inexperienced, don't. Unless you know what you are doing, complex code will
 * be much more difficult under this system. Use IterativeRobot or Command-Based
 * instead if you're new.
 */
class Robot : public frc::SampleRobot {
public:
//    float CheckDirectionChange(float);
//    int GetPosition();

//    Robot::Robot() : mAnalogTrigger(0)
//    {
//      mAnalogTrigger.SetLimitsVoltage(3.5, 3.8); // values higher than the highest minimum (pulse floor), lower than the lowest maximum (pulse ceiling)
//      mCounter = new Counter(&mAnalogTrigger);
//      mSpeedPrevious = 0.;
//      mPosition = 0;
//    }

	Robot() : mAnalogTrigger(0)
  {
		// Note SmartDashboard is not initialized here, wait until
		// RobotInit to make SmartDashboard calls
//		m_robotDrive.SetExpiration(0.1);
	//mAnalogTrigger = new AnalogTrigger(0);
	}

	void RobotInit() {
		m_chooser.AddDefault(kAutoNameDefault, kAutoNameDefault);
		m_chooser.AddObject(kAutoNameCustom, kAutoNameCustom);
		frc::SmartDashboard::PutData("Auto Modes", &m_chooser);
    Prefs = Preferences::GetInstance();
//    ultra = new Ultrasonic(9, 8); // assigns ultra to be an ultrasonic sensor which uses DigitalOutput 1 for the echo pulse and DigitalInput 1 for the trigger pulse
//    ultra->SetAutomaticMode(true); // turns on automatic mode

//    Gyro.Calibrate();
//    _talon0->ConfigSelectedFeedbackSensor(FeedbackDevice::CTRE_MagEncoder_Relative, 0, 10);
//    _talon0->SetSensorPhase(true);
//    _talon0->ConfigNominalOutputForward(0, kTimeoutMs);
//    _talon0->ConfigNominalOutputReverse(0, kTimeoutMs);
//    _talon0->ConfigPeakOutputForward(1, kTimeoutMs);
//    _talon0->ConfigPeakOutputReverse(-1, kTimeoutMs);
    mAnalogTrigger.SetLimitsVoltage(3.5, 3.8); // values higher than the highest minimum (pulse floor), lower than the lowest maximum (pulse ceiling)
    mCounter = new Counter(0);
    mSpeedPrevious = 0.;
    mPosition = 0;
    _talon0->ConfigSelectedFeedbackSensor(
        FeedbackDevice::CTRE_MagEncoder_Relative, 0, 10);
    _talon1->ConfigSelectedFeedbackSensor(
        FeedbackDevice::CTRE_MagEncoder_Relative, 0, 10);
    _talon2->ConfigSelectedFeedbackSensor(
        FeedbackDevice::CTRE_MagEncoder_Relative, 0, 10);
    _talon3->ConfigSelectedFeedbackSensor(
        FeedbackDevice::CTRE_MagEncoder_Relative, 0, 10);

    _talon0->SetSensorPhase(true);
    _talon1->SetSensorPhase(true);
    _talon2->SetSensorPhase(true);
    _talon3->SetSensorPhase(true);

	}

	/*
	 * This autonomous (along with the chooser code above) shows how to
	 * select between different autonomous modes using the dashboard. The
	 * sendable chooser code works with the Java SmartDashboard. If you
	 * prefer the LabVIEW Dashboard, remove all of the chooser code and
	 * uncomment the GetString line to get the auto name from the text box
	 * below the Gyro.
	 *
	 * You can add additional auto modes by adding additional comparisons to
	 * the if-else structure below with additional strings. If using the
	 * SendableChooser make sure to add them to the chooser code above as
	 * well.
	 */
	void Autonomous() {
		std::string autoSelected = m_chooser.GetSelected();

		// std::string autoSelected = frc::SmartDashboard::GetString(
		// "Auto Selector", kAutoNameDefault);
//		std::cout << "Auto selected: " << autoSelected << std::endl;
//
//		// MotorSafety improves safety when motors are updated in loops
//		// but is disabled here because motor updates are not looped in
//		// this autonomous mode.
//		m_robotDrive.SetSafetyEnabled(false);
//
//		if (autoSelected == kAutoNameCustom) {
//			// Custom Auto goes here
//			std::cout << "Running custom Autonomous" << std::endl;
//
//			// Spin at half speed for two seconds
//			m_robotDrive.ArcadeDrive(0.0, 0.5);
//			frc::Wait(2.0);
//
//			// Stop robot
//			m_robotDrive.ArcadeDrive(0.0, 0.0);
//		} else {
//			// Default Auto goes here
//			std::cout << "Running default Autonomous" << std::endl;
//
//			// Drive forwards at half speed for two seconds
//			m_robotDrive.ArcadeDrive(-0.5, 0.0);
//			frc::Wait(2.0);
//
//			// Stop robot
//			m_robotDrive.ArcadeDrive(0.0, 0.0);
//		}
	}

	/*
	 * Runs the motors with arcade steering.
	 */
	void OperatorControl() override {
	  int liftAng = 0.0;
    M1 = Prefs->GetDouble("M1", 0.0);
    M2 = Prefs->GetDouble("M2", 0.0);
    M3 = Prefs->GetDouble("M3", 0.0);
    M4 = Prefs->GetDouble("M4", 0.0);
    M5 = Prefs->GetDouble("M5", 0.0);
    M6 = Prefs->GetDouble("M6", 0.0);

    S1 = Prefs->GetDouble("S1", 0.0);
    S2 = Prefs->GetDouble("S2", 0.0);
    TS1 = Prefs->GetDouble("TS1", 0.0);
    TS2 = Prefs->GetDouble("TS2", 0.0);
    TS3 = Prefs->GetDouble("TS3", 0.0);

    _talon0->SetSelectedSensorPosition(0, 0, 10);
    _talon1->SetSelectedSensorPosition(0, 0, 10);
    _talon2->SetSelectedSensorPosition(0, 0, 10);
    _talon3->SetSelectedSensorPosition(0, 0, 10);
    _talon5->SetSelectedSensorPosition(0, 0, 10);
    bool blockForward, blockReverse; // soft limit switches for this example
    int mPos=0;
    float speed = 1.0; // initial speed for this example
    mCounter->Reset();
//		m_robotDrive.SetSafetyEnabled(true);
		while (IsOperatorControl() && IsEnabled()) {
//	    _talon0->SetSelectedSensorPosition(0,kSlotIdx,kTimeoutMs);
	    LY_Axis = _joy->GetRawAxis(1);
	    RX_Axis = _joy->GetRawAxis(5);

      if ((LY_Axis > -0.1) && (LY_Axis < 0.1))
        {
        LY_Axis = 0.0;
        }

      if ((RX_Axis > -0.1) && (RX_Axis < 0.1))
        {
        RX_Axis = 0.0;
        }



	    liftAng = mCounter->Get();

        SmartDashboard::PutNumber("Count", (double)liftAng);

//      double range = ultra->GetRangeInches(); // reads the range on the ultrasonic sensor
//      double rangeScaled = 0.0;
//
//      if (range > 10)
//        {
//        range = 10.0;
//        rangeScaled = 1.0;
//        }
//      else
//        {
//        rangeScaled = range*0.1;
//        }

//	    _talon0->Set(ControlMode::PercentOutput, LY_Axis);

        SmartDashboard::PutNumber("Velocity 0",
            _talon0->GetSelectedSensorVelocity(0) / 12.75);
        SmartDashboard::PutNumber("Velocity 1",
            _talon1->GetSelectedSensorVelocity(0) / 12.75);
        SmartDashboard::PutNumber("Velocity 2",
            _talon2->GetSelectedSensorVelocity(0) / 12.75);
        SmartDashboard::PutNumber("Velocity 3",
            _talon3->GetSelectedSensorVelocity(0) / 12.75);
        SmartDashboard::PutNumber("Velocity 5",
            _talon5->GetSelectedSensorVelocity(0) / 12.75);
//	    Spark1.Set(-RX_Axis);
//	    Spark2.Set(LY_Axis);
//
//	    Talon_PWM0->Set(RX_Axis);
//	    Talon_PWM1->Set(LY_Axis);
        Spark1.Set(LY_Axis);
        Spark2.Set(LY_Axis);

      Talon_PWM0->Set(RX_Axis);
      Talon_PWM1->Set(-RX_Axis);
      double Lift = 0.0;

      if (_joy->GetRawAxis(3) > 0.1)
        {
        Lift = _joy->GetRawAxis(3);
        }
      else if (_joy->GetRawAxis(2) > 0.1)
        {
        Lift = -_joy->GetRawAxis(2);
        }

      double winch = 0.0;
      if (_joy->GetRawButton(1) == true)
        {
        winch = 0.5; // climb direction
        }
      else if (_joy->GetRawButton(2) == true)
        {
        winch = -0.5;
        }

      double hook = 0.0;
      if (_joy->GetRawButton(3) == true)
        {
        hook = 0.3; // climb direction
        }
      else if (_joy->GetRawButton(4) == true)
        {
        hook = -0.3;
        }

	    Talon_PWM2->Set(winch);

      _talon0->Set(ControlMode::PercentOutput, (M1));
      _talon1->Set(ControlMode::PercentOutput, (M2));
      _talon2->Set(ControlMode::PercentOutput, (M3));
      _talon3->Set(ControlMode::PercentOutput, (M4));
      _talon4->Set(ControlMode::PercentOutput, (Lift));
      _talon5->Set(ControlMode::PercentOutput, (M6));


//	    _talon0->Set(ControlMode::PercentOutput, LY_Axis);
//			// Drive with arcade style (use right stick)
//			m_robotDrive.ArcadeDrive(
//					-m_stick.GetY(), m_stick.GetX());
//	    SmartDashboard::PutNumber("LY_Axis", LY_Axis);
//	    SmartDashboard::PutNumber("UltraRange", range);
			// The motors will be updated every 5ms
			frc::Wait(0.005);
		}
	}

	/*
	 * Runs during test mode
	 */
	void Test() override {}

private:
	// Robot drive system
	TalonSRX *_talon0 = new TalonSRX(1);
	TalonSRX *_talon1 = new TalonSRX(2);
	TalonSRX *_talon2 = new TalonSRX(3);
	TalonSRX *_talon3 = new TalonSRX(4);
	TalonSRX *_talon4 = new TalonSRX(5);
	TalonSRX *_talon5 = new TalonSRX(6);

  // Left articulation
  frc::Spark Spark1{0};
  // Left intake
  frc::Spark Spark2{1};
  //Right intake
  Talon *Talon_PWM0 = new Talon(2);
  //Right articulation
  Talon *Talon_PWM1 = new Talon(3);
  //Winch
  Talon *Talon_PWM2 = new Talon(4);

  AnalogTrigger mAnalogTrigger; // create an encoder pulse trigger
    Counter* mCounter; // count the encoder pulse triggers in current direction
    float mSpeedPrevious; // to remember previous direction
    int mPosition; // position accumulator to remember previous position before last direction change

//	frc::Spark m_leftMotor{0};
//  ADXRS450_Gyro Gyro;
  Preferences *Prefs;
  Joystick *_joy = new Joystick(0);
//  DigitalOutput DO_8;
//  DigitalInput DO_9;
//  Ultrasonic *ultra; // creates the ultra object



  float CheckDirectionChange(float NewSpeed)
  {
    // update position accumulator if changing direction
    // encoder doesn't know the direction so we have to remember the direction for it
    if ((mSpeedPrevious < 0 && NewSpeed >= 0) || (mSpeedPrevious >= 0 && NewSpeed < 0))
    {
      mPosition = GetPosition(); // changing directions so save what we have
      mCounter->Reset(); // and start counting in the new direction
      mSpeedPrevious = NewSpeed; // return input speed for ease of use (may include it in the Set() argument => Set(CheckDirectionChange(speed)))
    }
      return NewSpeed;
  }

  int GetPosition(void)
  {
    // position from previous direction change plus what's been accumulated so far in this direction
    if (mSpeedPrevious >= 0)
      return mPosition + mCounter->Get(); // been going forward so add counter

    return mPosition - mCounter->Get(); // been going backward so subtract counter
  }

  int kSlotIdx = 0;
  int kPIDLoopIdx = 0;
  int kTimeoutMs = 10;
  double TargetSpeed = 0;
  double LY_Axis;
  double RX_Axis;
  double GyroAngle;

  double Rt;
  double Lt;

  double IntergalL = 0;
  double IntergalR = 0;
  double input1 = 0;
  double M1, M2, M3, M4, M5, M6, S1, S2, TS1, TS2, TS3;

  double DesiredSpeedPrev = 0;

  double SpeedRaw[2], SpeedFilt[2], SpeedFiltPrev[2], desiredSpeed[2],
      output[2];
//	frc::Spark m_rightMotor{1};
//	frc::DifferentialDrive m_robotDrive{m_leftMotor, m_rightMotor};
//
//	frc::Joystick m_stick{0};

	frc::SendableChooser<std::string> m_chooser;
	const std::string kAutoNameDefault = "Default";
	const std::string kAutoNameCustom = "My Auto";
};

START_ROBOT_CLASS(Robot)


//// Position of BOSCH AHC-2 12V  6004.RA3.194-06 174.9:1 gear w/ encoder 1 tick per motor revolution on roboRIO analog 5 volt bus
//// FRC Team 4237 Lakeshore High School
//// Sample program merely rotates 1 revolution then reverses for 1 revolution and does so forever.
//
//#include "WPILib.h"
//
//class Robot: public SampleRobot
//{
//public:
//  Robot();
//  void OperatorControl();
////  float CheckDirectionChange(float);
//  int GetPosition();
//private:
////  CANTalon* mCANTalon; // motor
//  AnalogTrigger mAnalogTrigger; // create an encoder pulse trigger
//  Counter* mCounter; // count the encoder pulse triggers in current direction
//  float mSpeedPrevious; // to remember previous direction
//  int mPosition; // position accumulator to remember previous position before last direction change
//};
//
//Robot::Robot() : mAnalogTrigger(0)
//{
////  mCANTalon = new CANTalon(0);
//  mAnalogTrigger.SetLimitsVoltage(3.5, 3.8); // values higher than the highest minimum (pulse floor), lower than the lowest maximum (pulse ceiling)
//  mCounter = new Counter(0);
//  mSpeedPrevious = 0.;
//  mPosition = 0;
//}
//
//int Robot::GetPosition()
//{
//  // position from previous direction change plus what's been accumulated so far in this direction
//  if (mSpeedPrevious >= 0)
//    return mPosition + mCounter->Get(); // been going forward so add counter
//
//  return mPosition - mCounter->Get(); // been going backward so subtract counter
//}
//
//void Robot::OperatorControl()
//{
//  bool blockForward, blockReverse; // soft limit switches for this example
//  int mPos=0;
//  float speed = 1.0; // initial speed for this example
//  mCounter->Reset();
//
//// example back and forth nearly 1 revolution (174.9)
//
//  while(IsEnabled() && IsOperatorControl())
//  {
//    mPos = GetPosition();
//    printf("Position %d, Speed %f\n", mPos, speed);
//
//    if (mPos >= 175) blockForward = true; // example check for at limit switch
//    else blockForward = false;
//
//    if (mPos <= 0) blockReverse = true; // example check for at limit switch
//    else blockReverse = false;
//
//    if (blockForward) speed = -1.; // example if at a limit switch go back the other way
//    if (blockReverse) speed = +1.;
//
//            SmartDashboard::PutNumber("Pos", mPos);
//            SmartDashboard::PutNumber("Speed", speed);
//            SmartDashboard::PutNumber("Count", mCounter->Get());
//
//
//
//    // call CheckDirectionChange with same speed as Set() with (or before or after) every motor Set() to update position if reversing direction
////    mCANTalon->Set(CheckDirectionChange(speed)); // refresh or change speed, update position if changing direction
//
//    Wait(0.01); // ticks won't be lost but wait less to see them all here and respond faster
//  }
//}
//
//START_ROBOT_CLASS(Robot)
