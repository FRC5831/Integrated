#include <Commands/BaseCommands/ClawInOut.h>
#include <Robot.h>
#include <config.h>

SetJointAngle::SetJointAngle() {
	Requires(&Robot::joint_motor);
}

void SetJointAngle::Execute() {
	double claw_speed = 0;
	#ifdef ONEDRIVER
		double sign = 0;
		if(Robot::oi.GetRightJoystick().GetRawButton(INBUTTON))sign = 1;
		else if(Robot::oi.GetRightJoystick().GetRawButton(OUTBUTTON))sign = -1;
		else sign = CLAW_CONTINUE_SPEED;
		claw_speed = CLAW_SPEED*sign;
	#endif
	#ifdef TWODRIVER
		double outaxis = Robot::oi.GetControlJoystick().GetRawAxis(OUTAXIS);
		if(Robot::oi.GetControlJoystick().GetRawButton(INBUTTON))claw_speed = CLAW_SPEED;
		else if(outaxis>0)claw_speed = -outaxis;
		else claw_speed = CLAW_CONTINUE_SPEED;
	#endif
	Robot::joint_motor.SetAngle(claw_speed);
}

bool SetJointAngle::IsFinished() {
	return false;
}
