#ifndef Log_H
#define Log_H

#include "Commands/Command.h"
#include <Robot.h>

class Log : public Command {
public:
	Log();
	void Initialize();
	void Execute();
	bool IsFinished();
private:

};

#endif  // Log_H
