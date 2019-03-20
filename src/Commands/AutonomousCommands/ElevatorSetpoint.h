#ifndef ElevatorSetpoint_H
#define ElevatorSetpoint_H

#include<Commands/Command.h>

class ElevatorSetpoint : public Command {
public:
	ElevatorSetpoint(int point);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // ElevatorSetpoint_H
