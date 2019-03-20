#ifndef TankDrive_H
#define TankDrive_H

#include <Commands/Command.h>

class TankDrive : public Command {
public:
	TankDrive();
	void Execute();
	bool IsFinished();
};

#endif  // TankDrive_H
