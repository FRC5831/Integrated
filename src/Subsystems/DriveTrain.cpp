#include "DriveTrain.h"
#include "../Commands/BaseCommands/TankDrive.h"

DriveTrain::DriveTrain() : Subsystem("ExampleSubsystem") {

}

void DriveTrain::InitDefaultCommand(){
	SetDefaultCommand(new TankDrive());
}

void DriveTrain::SetSafetyEnabled(bool state){
	m_Robot.SetSafetyEnabled(state);
}

void DriveTrain::Drive(double leftspeed,double rightspeed){
	m_Robot.TankDrive(leftspeed*0.8,rightspeed*0.8);//rightspeed*0.3);
}

AHRS *DriveTrain::Getahrs(){
	return ahrs;
}
