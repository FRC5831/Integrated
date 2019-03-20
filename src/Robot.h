/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once


#include"WPILib.h"
#include"OI.h"

#include"Subsystems/DriveTrain.h"
#include"Subsystems/Elevator.h"
#include"Subsystems/Climb.h"

#include <Commands/AutonomousCommands/Autonomous.h>
#include <Commands/BackGroundCommands/BackGroundCommandGroup.h>
#include <Subsystems/Claw_Solenoid.h>
#include <Subsystems/Joint_Motor.h>

class Robot : public frc::IterativeRobot {
public:
	//Input Value
	static DriverStation& ds;
	static OI oi;

	//Subsystem
	static Joint_Motor joint_motor;
	static Claw_Solenoid claw_solenoid;
	static DriveTrain dt;
    static Elevator elevator;
    static Climb climb;

    //state of some action
    //auto
    static bool ishitting;//for collision
    static bool isdetecting;//for camera and vision detect start
    static bool isourteam;//for color detect
    static bool ischanged;
    static bool isdroped;

    //teleop
    static bool isclimbing;//for switchclimb and tankdrive
    static bool iscontinued;
    static int elevator_position;
    static int elevator_growposition;

	//Command Group
	Autonomous autonomous;
	BackGroundCommandGroup background;

private:
	void RobotInit()override;
	void AutonomousInit() override;
	void AutonomousPeriodic() override;
	void TeleopInit() override;
	void TeleopPeriodic() override;
	void DisabledInit() override;
	void TestPeriodic() override;
};
