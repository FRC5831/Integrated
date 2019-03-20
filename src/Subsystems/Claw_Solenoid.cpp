#include <Subsystems/Claw_Solenoid.h>
#include <Commands/BaseCommands/ClawSwitch.h>

Claw_Solenoid::Claw_Solenoid() : Subsystem("ExampleSubsystem") {

}

void Claw_Solenoid::Switch(bool on){
	if(on)solenoid.Set(frc::DoubleSolenoid::kReverse);
	else solenoid.Set(frc::DoubleSolenoid::kForward);
}

void Claw_Solenoid::InitDefaultCommand(){
	SetDefaultCommand(new ClawSwitch());
}

void Claw_Solenoid::SetCloseLoop(bool state){
	compressor->SetClosedLoopControl(state);
}

void Claw_Solenoid::Release(bool state){
	if(state)compressor->Stop();
	else compressor->Start();
}

bool Claw_Solenoid::isEnabled(){
	return compressor->Enabled();
}



