#include "ElevatorSetpoint.h"
#include <Robot.h>

ElevatorSetpoint::ElevatorSetpoint(int point) {
	Requires(&Robot::elevator);
}

// Called just before this Command runs the first time
void ElevatorSetpoint::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void ElevatorSetpoint::Execute() {

}

// Make this return true when this Command no longer needs to run execute()
bool ElevatorSetpoint::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void ElevatorSetpoint::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ElevatorSetpoint::Interrupted() {

}
