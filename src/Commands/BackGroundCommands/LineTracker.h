#ifndef LineTracker_H
#define LineTracker_H

using namespace std;

#include<Commands/Command.h>
#include<vector>
#include"WPILib.h"
#include<algorithm>

class LineTracker : public Command {
public:
	LineTracker();
	void Execute();
	void Initialize();
	bool IsFinished();
private:
	frc::AnalogInput linetracker{0};
	vector<int> linevalue;
	int color = 0;
	int lastcolor = 0;
	double growcolor = 0;
	const float hz = 0.1;
	const int range = 500;

	bool delay = false;
	Timer delaytimer;
	const double delaytime = 0.1;

};

#endif  // LineTracker_H
