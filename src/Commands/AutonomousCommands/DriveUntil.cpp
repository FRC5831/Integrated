#include <Commands/AutonomousCommands/DriveUntil.h>
#include <Robot.h>
#include <config.h>

DriveUntil::DriveUntil(bool *sensor_state) {
	Requires(&Robot::dt);
	state = sensor_state;
	SetTimeout(2.2);
}

void DriveUntil::Initialize() {
//	Robot::isdetecting = true;
}

void DriveUntil::Execute() {
//	if(Robot::ds.GetAlliance())
	Robot::dt.Drive(-DRIVE_SPEED_AUTO,-DRIVE_SPEED_AUTO);
}

// Make this return true when this Command no longer needs to run execute()
bool DriveUntil::IsFinished() {
	return IsTimedOut();
//	return *statew;
}

// Called once after isFinished returns true
void DriveUntil::End() {
	Robot::dt.Drive(0,0);
	Robot::claw_solenoid.Switch(false);
}
