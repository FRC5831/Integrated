#include <Commands/AutonomousCommands/DriveUntil.h>
#include "Autonomous.h"
#include "TurnWithPID.h"
#include "DropBox.h"
#include "Delay.h"
#include <Robot.h>

Autonomous::Autonomous() {
//	AddSequential(new DriveUntil(&Robot::ischanged));
//	AddSequential(new Delay(1));
//	AddSequential(new TurnWithPID(90));//detect
	AddSequential(new DriveUntil(&Robot::ishitting));//or ultrasonic use ||
//	AddSequential(new Delay(0.1));
//	AddSequential(new DropBox());//motor and Solenoid
//	AddParallel(new DriveUntil(&Robot::isdroped));
}
