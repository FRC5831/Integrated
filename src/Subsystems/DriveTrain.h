#ifndef DriveTrain_H
#define DriveTrain_H

#include <Commands/Subsystem.h>
#include <WPILib.h>
#include "AHRS.h"
#include <Port.h>

class DriveTrain : public Subsystem {
public:
	DriveTrain();
	void Drive(double left,double right);
	void SetSafetyEnabled(bool state);
	void InitDefaultCommand();
	AHRS *Getahrs();

private:
	Spark leftforward_motor{DRIVETRAIN_LEFTFORWARD_MOTOR};
	Spark leftmiddle_motor{DRIVETRAIN_LEFTMIDDLE_MOTOR};
	Spark leftbackward_motor{DRIVETRAIN_LEFTBACKWARD_MOTOR};
	SpeedControllerGroup left{leftforward_motor,leftmiddle_motor,leftbackward_motor};

	Spark rightforward_motor{DRIVETRAIN_RIGHTFORWARD_MOTOR};
	Spark rightmiddle_motor{DRIVETRAIN_RIGHTMIDDLE_MOTOR};
	Spark rightbackward_motor{DRIVETRAIN_RIGHTBACKWARD_MOTOR};
	SpeedControllerGroup right{rightforward_motor,rightmiddle_motor,rightbackward_motor};

	//if you found the car cannot have a good mode, plz change the value beside this line
	DifferentialDrive m_Robot{right,left};
	AHRS *ahrs = new AHRS(SerialPort::kMXP);
};

#endif  // DriveTrain_H
