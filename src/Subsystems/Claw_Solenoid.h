#ifndef Claw_Solenoid_H
#define Claw_Solenoid_H

#include <Commands/Subsystem.h>
#include <WPILib.h>
#include <Port.h>

class Claw_Solenoid : public Subsystem {
public:
	Claw_Solenoid();
	void Switch(bool on);
	void InitDefaultCommand();
	bool GetPressure();
	void SetCloseLoop(bool state);
	void Release(bool state);
	bool isEnabled();

private:
	DoubleSolenoid solenoid{CLAW_LEFT_SOLENOID,CLAW_RIGHT_SOLENOID};
	Compressor *compressor = new Compressor(0);
};

#endif  // Claw_Solenoid_H
