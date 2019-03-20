#include "Elevator.h"
#include <Commands/BaseCommands/Upper.h>

Elevator::Elevator() : Subsystem("ExampleSubsystem") {
	right_motor.SetInverted(true);
}

void Elevator::SetToDistance(double distance){

}

void Elevator::Move(double elevator_speed){
	left_motor.Set(ctre::phoenix::motorcontrol::ControlMode::PercentOutput,elevator_speed);
	right_motor.Set(elevator_speed);
}

void Elevator::InitDefaultCommand(){
	SetDefaultCommand(new Upper());
}

double Elevator::GetPosition(){
	return left_motor.GetSelectedSensorPosition(0);
}

bool Elevator::GetButton(){
	return button.Get();
}

void Elevator::Reset(){
	left_motor.SetSelectedSensorPosition(0,0,10);
}
