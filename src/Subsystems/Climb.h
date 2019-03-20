#ifndef Climb_H
#define Climb_H

#include <Commands/Subsystem.h>
#include <WPILIB.h>
#include <Port.h>

class Climb : public Subsystem {
private:
	Solenoid climb_solenoid{CLIMB_SOLENOID};

public:
	Climb();
	void Switch(bool on);
	void InitDefaultCommand();
};

#endif  // Climb_H
