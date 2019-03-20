#ifndef ClawInOut_H
#define ClawInOut_H

#include<Commands/Command.h>

class SetJointAngle : public Command {
public:
	SetJointAngle();
	void Execute();
	bool IsFinished();
};

#endif  // ClawInOut_H
