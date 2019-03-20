#ifndef TurnWithPID_H
#define TurnWithPID_H

#include <Commands/Command.h>
#include <WPILib.h>


class TurnWithPID : public Command,public PIDOutput {
public:
	TurnWithPID(double turn_angle);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void PIDWrite(double output);

private:
	PIDController *turnController;
	double angle;
	double rotateSpeed = 0;
};

#endif  // TurnWithPID_H
