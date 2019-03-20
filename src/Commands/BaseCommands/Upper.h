#ifndef Upper_H
#define Upper_H

#include <Commands/Command.h>

class Upper : public Command {
public:
	Upper();
	void Execute();
	bool IsFinished();
private:
	int lastposition = 0;
	bool isbraking = false;
};

#endif  // Upper_H
