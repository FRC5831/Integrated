#ifndef Delay_H
#define Delay_H

#include <Commands/Command.h>

class Delay : public Command {
public:
	Delay(double delay_time);
	void Execute();
	bool IsFinished();
};

#endif  // Delay_H
