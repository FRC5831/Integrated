#include <Commands/BaseCommands/Upper.h>
#include <Robot.h>
#include <config.h>

Upper::Upper() {
	Requires(&Robot::elevator);
}

void Upper::Execute() {
#ifdef DEBUG
	if(Robot::oi.GetLeftJoystick().GetRawButton(1))Robot::claw_solenoid.Release(true);
	else Robot::claw_solenoid.Release(false);
#endif
double sign = 0;
double elevator_speed = 0;
int position = Robot::elevator.GetPosition();
if(!Robot::elevator.GetButton()){
	Robot::elevator.Reset();
	Robot::iscontinued = true;
}
Robot::elevator_growposition = abs(position-lastposition);
//	isbraking = Robot::elevator_growposition>UPPER_MAXGROW_POSITION;
SmartDashboard::PutBoolean("isbraking",isbraking);

#ifdef ONEDRIVER
	if(Robot::oi.GetLeftJoystick().GetRawButton(UPBUTTON)){
#endif
#ifdef TWODRIVER
	if(Robot::oi.GetControlJoystick().GetRawButton(UPBUTTON)){
#endif
		sign = -1;
		Robot::iscontinued = false;
	}
	else if(Robot::iscontinued)sign = UPPER_CONTINUE_SPEED;
#ifdef ONEDRIVER
	else if(Robot::oi.GetLeftJoystick().GetRawButton(DOWNBUTTON))sign = UPPER_UPMAXSPEED;
#endif
#ifdef TWODRIVER
	else if(double(abs(Robot::oi.GetControlJoystick().GetRawAxis(DOWNAXIS)))>=0.01)sign = UPPER_UPMAXSPEED;
#endif
	else sign = UPPER_HOLD_SPEED;
	elevator_speed = UPPER_MAXSPEED*sign;
	Robot::elevator.Move(elevator_speed);
	Robot::elevator_position = position;
	lastposition = position;
}

bool Upper::IsFinished() {
	return false;
}
