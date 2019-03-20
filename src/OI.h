/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#define DEBUG

#include <Buttons/JoystickButton.h>
#include <Joystick.h>

#include <Port.h>

using namespace frc;

class OI {
public:
	OI();
	Joystick& GetLeftJoystick();
	Joystick& GetRightJoystick();
	Joystick& GetControlJoystick();

private:
	Joystick left_joy{LEFTSTICK_PORT};
	Joystick right_joy{RIGHTSTICK_PORT};
	Joystick m_joy{CONTROLSTICK_PORT};

	//JoystickButton setting
#ifdef ONEDRIVER
//	JoystickButton up{&left_joy,UPBUTTON};
//	JoystickButton down{&right_joy,DOWNBUTTON};
//	JoystickButton openclaw{&left_joy,OPENBUTTON};
//	JoystickButton closeclaw{&right_joy,CLOSEBUTTON};
//	JoystickButton inclaw{&right_joy,INBUTTON};
//	JoystickButton outclaw{&right_joy,OUTBUTTON};
#endif
#ifdef TWODRIVER
//	JoystickButton closeclaw{&m_joy,CLOSEBUTTON};
//	JoystickControl openclaw{&m_joy,OPENAXIS};
//	JoystickControl updown{&m_joy,UPDOWNAXIS};
//	JoystickButton inclaw{&m_joy,INBUTTON};
//	JoystickControl outclaw{&m_joy,OUTAXIS};
#endif
};
