#ifndef Elevator_H
#define Elevator_H

#include <Commands/Subsystem.h>
#include <WPILib.h>
#include <Port.h>

#include "ctre/Phoenix.h"

class Elevator : public Subsystem {
public:
	Elevator();
	void SetToDistance(double distance);
	void Move(double elevator_speed);
	double GetPosition();
	void InitDefaultCommand();
	bool GetButton();
	void Reset();

private:
	Spark right_motor{ELEVATOR_RIGHT_MOTOR};
	TalonSRX left_motor{ELEVATOR_LEFT_MOTOR};//can change to WPI_TalonSRX
	DigitalInput button{ELEVATOR_BUTTON};
	//SpeedControllerGroup elevator_motor{left_motor,right_motor};
};

#endif  // Elevator_H
