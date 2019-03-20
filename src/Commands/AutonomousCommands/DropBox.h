#ifndef DropBox_H
#define DropBox_H

#include<Commands/Command.h>

class DropBox : public Command {
public:
	DropBox();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
};

#endif  // DropBox_H
