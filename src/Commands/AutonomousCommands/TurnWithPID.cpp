#include "TurnWithPID.h"
#include <Robot.h>
#include <config.h>

TurnWithPID::TurnWithPID(double turn_angle) {
	Requires(&Robot::dt);
	turnController = new PIDController(kP, kI, kD, kF, Robot::dt.Getahrs(), this);
	turnController->SetInputRange(-180.0f,  180.0f);
	turnController->SetOutputRange(-0.5, 0.5);
	turnController->SetAbsoluteTolerance(2.0f);
	turnController->SetContinuous(true);
	angle = turn_angle;
}

void TurnWithPID::Initialize() {
	turnController->Enable();
}

void TurnWithPID::Execute() {
	 turnController->SetSetpoint(angle);
	 Robot::dt.Drive(-rotateSpeed,rotateSpeed);
}

bool TurnWithPID::IsFinished() {
	return turnController->OnTarget();
}

void TurnWithPID::End() {
	turnController->Disable();
	Robot::dt.Drive(0,0);

}

void TurnWithPID::PIDWrite(double output){
	rotateSpeed = output;
}

