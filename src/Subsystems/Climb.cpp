#include "Climb.h"
#include <Commands/BaseCommands/SwitchClimb.h>

Climb::Climb() : Subsystem("Example") {

}

void Climb::InitDefaultCommand(){
	SetDefaultCommand(new SwitchClimb());
}

void Climb::Switch(bool on){
	climb_solenoid.Set(on);
}
