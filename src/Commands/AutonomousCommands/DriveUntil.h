#ifndef DriveUntil_H
#define DriveUntil_H

#include<Commands/Command.h>

class DriveUntil : public Command {
public:
	DriveUntil(bool *sensor_state);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
private:
	bool *state;
};

#endif  // DriveUntil_H
