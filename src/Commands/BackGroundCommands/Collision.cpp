#include <Commands/BackGroundCommands/Collision.h>
#include <Robot.h>

Collision::Collision() {
	ahrs = Robot::dt.Getahrs();
}

// Called just before this Command runs the first time
void Collision::Initialize() {
//	ahrs->Reset();
}

// Called repeatedly when this Command is scheduled to run
void Collision::Execute() {
	//Input the Value and Display
	isMoving = ahrs->IsMoving();
	velocityx = ahrs->GetVelocityX();
	SmartDashboard::PutNumber("accelx",accelx);
	SmartDashboard::PutNumber("velocityx",velocityx);
	SmartDashboard::PutBoolean("isMoving",isMoving);
	SmartDashboard::PutNumber("growaccel",growaccel);
	SmartDashboard::PutNumber("grow rate",rate);
	//the delay funtion
	if(delaytimer.Get()>=delaytime){
		delaytimer.Stop();
		delaytimer.Reset();
		delay = false;
	}else if(delay){
		delaytimer.Start();
		SmartDashboard::PutBoolean("ishitting",true);
	}else SmartDashboard::PutBoolean("ishitting",Robot::ishitting);

	//set a hz and use it the find the growing
	if(isMoving){
		accelx = ahrs->GetWorldLinearAccelX();
		growaccel = (lastaccel-accelx)/hz;
		rate = ((lastgrow-growaccel)/hz);//the shock rate
	}
	Robot::ishitting = rate>hitforce;//judgment the hitting movement
	//record the last value
	lastaccel = accelx;
	lastgrow = growaccel;
	lastvelo = velocityx;
}


// Make this return true when this Command no longer needs to run execute()
bool Collision::IsFinished() {
	return false;
}
