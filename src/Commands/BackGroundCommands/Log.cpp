#include "Log.h"

Log::Log() {

}

// Called once when the command executes
void Log::Initialize() {

}

void Log::Execute(){
	SmartDashboard::PutNumber("Location",Robot::ds.GetLocation());
	SmartDashboard::PutNumber("Alliance",Robot::ds.GetAlliance());
	SmartDashboard::PutNumber("BatteryVoltage",Robot::ds.GetBatteryVoltage());
	SmartDashboard::PutNumber("isclimbing",Robot::isclimbing);
	SmartDashboard::PutNumber("position",Robot::elevator.GetPosition());
	SmartDashboard::PutNumber("isdetecting",Robot::isdetecting);
	SmartDashboard::PutNumber("isoutteam",Robot::isourteam);
	SmartDashboard::PutNumber("ischanged",Robot::ischanged);
	SmartDashboard::PutNumber("iscontinue",Robot::iscontinued);
	SmartDashboard::PutNumber("growposition",Robot::elevator_growposition);
	SmartDashboard::PutNumber("position",Robot::elevator_position);
	SmartDashboard::PutNumber("joystick speed",abs(Robot::oi.GetControlJoystick().GetRawAxis(DOWNAXIS)));
}

bool Log::IsFinished(){
	return false;
}
