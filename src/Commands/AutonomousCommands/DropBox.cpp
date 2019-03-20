#include "DropBox.h"
#include <Robot.h>

DropBox::DropBox() {
	Requires(&Robot::joint_motor);
	Requires(&Robot::claw_solenoid);
}

// Called just before this Command runs the first time
void DropBox::Initialize() {
	//if detect the color is not our team
	//don't drop
}

// Called repeatedly when this Command is scheduled to run
void DropBox::Execute() {

}

// Make this return true when this Command no longer needs to run execute()
bool DropBox::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void DropBox::End() {
	Robot::isdroped = true;
}
