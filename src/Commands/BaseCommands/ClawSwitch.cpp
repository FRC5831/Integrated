#include <Commands/BaseCommands/ClawSwitch.h>
#include <Robot.h>

ClawSwitch::ClawSwitch() {
	Requires(&Robot::claw_solenoid);
}

void ClawSwitch::Execute() {
#ifdef ONEDRIVER
	Robot::claw_solenoid.Switch(Robot::oi.GetRightJoystick().GetRawButton(OPENBUTTON));
#endif
#ifdef TWODRIVER
	Robot::claw_solenoid.Switch(Robot::oi.GetControlJoystick().GetRawButton(OPENBUTTON));
#endif
}

bool ClawSwitch::IsFinished(){
	return false;
}
