#include "SwitchClimb.h"
#include <Robot.h>
#include <config.h>

SwitchClimb::SwitchClimb() {
	Requires(&Robot::climb);
}

void SwitchClimb::Execute() {
	Robot::isclimbing = Robot::oi.GetLeftJoystick().GetRawButton(SWITCHCLIMBMODE);
	Robot::climb.Switch(Robot::isclimbing);
}

bool SwitchClimb::IsFinished() {
	return false;
}
