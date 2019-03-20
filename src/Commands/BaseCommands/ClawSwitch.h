#ifndef ClawSwitch_H
#define ClawSwitch_H

#include <Commands/Command.h>

class ClawSwitch : public Command {
public:
	ClawSwitch();
	void Execute();
	bool IsFinished();
};

#endif  // ClawSwitch_H
