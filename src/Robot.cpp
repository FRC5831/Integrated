/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Robot.h"

#include <iostream>

DriverStation& Robot::ds = DriverStation::GetInstance();
Elevator Robot::elevator;
DriveTrain Robot::dt;
Claw_Solenoid Robot::claw_solenoid;
Joint_Motor Robot::joint_motor;
OI Robot::oi;
Climb Robot::climb;
//Initialize the globle value
bool Robot::isclimbing = false;
bool Robot::ishitting = false;
bool Robot::isdetecting = false;
bool Robot::isourteam = false;
bool Robot::ischanged = false;
bool Robot::isdroped = false;
bool Robot::iscontinued = false;
int Robot::elevator_position = 0;
int Robot::elevator_growposition = 0;

void Robot::RobotInit() {
	background.Start();
	dt.SetSafetyEnabled(false);
	Robot::claw_solenoid.SetCloseLoop(true);
	cs::UsbCamera camera1 = CameraServer::GetInstance()->StartAutomaticCapture(0);
	camera1.SetResolution(1280, 960);
	cs::UsbCamera camera2 = CameraServer::GetInstance()->StartAutomaticCapture(1);
	camera2.SetResolution(1280, 960);}

void Robot::AutonomousInit() {
	autonomous.Start();
}

void Robot::AutonomousPeriodic() {
	frc::Scheduler::GetInstance()->Run();
}

void Robot::TeleopInit() {
	autonomous.Cancel();
	Robot::iscontinued = false;
}

void Robot::TeleopPeriodic() {
	frc::Scheduler::GetInstance()->Run();
}

void Robot::DisabledInit(){

}

void Robot::TestPeriodic() {

}

START_ROBOT_CLASS(Robot)
