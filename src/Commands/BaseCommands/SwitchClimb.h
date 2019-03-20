#ifndef SwitchClimb_H
#define SwitchClimb_H

#include<Commands/Command.h>

class SwitchClimb : public Command {
public:
	SwitchClimb();
	void Execute();
	bool IsFinished();
};

#endif  // SwitchClimb_H
