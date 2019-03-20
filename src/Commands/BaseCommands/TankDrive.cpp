#include <Commands/BaseCommands/TankDrive.h>
#include <Robot.h>
#include <iostream>
#include <config.h>

TankDrive::TankDrive() {
	Requires(&Robot::dt);
}

// Called repeatedly when this Command is scheduled to run
void TankDrive::Execute() {
	double ratio = 1;//abs(1-(UPPER_MAXPOSITION/Robot::elevator_position));
	if(!Robot::isclimbing)Robot::dt.Drive(Robot::oi.GetLeftJoystick().GetRawAxis(1)*ratio,Robot::oi.GetRightJoystick().GetRawAxis(1)*ratio);
	else Robot::dt.Drive(-std::abs(Robot::oi.GetRightJoystick().GetRawAxis(1)),-std::abs(Robot::oi.GetRightJoystick().GetRawAxis(1)));
}

// Make this return true when this Command no longer needs to run execute()
bool TankDrive::IsFinished() {
	return false;
}
