/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

//#include <Commands/BaseCommands/ClawInOut.h>
//#include <Commands/BaseCommands/SwitchClimb.h>
#include "OI.h"
#include <SmartDashboard/SmartDashboard.h>

//#include"Commands/BaseCommands/ClawSwitch.h"
//#include"Commands/BaseCommands/Upper.h"
#include "config.h"
using namespace frc;

//change to whenpress
OI::OI() {
//closeclaw.WhenActive(new ClawSwitch(false));
//openclaw.WhenActive(new ClawSwitch(true));
//inclaw.WhenActive(new ClawInOut(CLAW_IN_SPEED));
//#ifdef ONEDRIVER
//up.WhenActive(new Upper(UPPER_MAXSPEED));
//down.WhenActive(new Upper(-UPPER_MAXSPEED));
//down.WhenInactive(new Upper(0));
//outclaw.WhenActive(new ClawInOut(CLAW_OUT_SPEED));
//#endif
//#ifdef TWODRIVER
//updown.WhileActive(new Upper(m_joy.GetRawAxis(UPDOWNAXIS)));
//outclaw.WhileActive(new ClawInOut(m_joy.GetRawAxis(OUTAXIS)));
//outclaw.WhenInactive(new ClawInOut(CLAW_CONTINUE_SPEED));
//#endif
}

Joystick& OI::GetLeftJoystick() {
	return left_joy;
}

Joystick& OI::GetRightJoystick() {
	return right_joy;
}

	Joystick& OI::GetControlJoystick() {
	return m_joy;
}
