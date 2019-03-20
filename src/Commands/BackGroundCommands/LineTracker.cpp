#include "LineTracker.h"
#include <Robot.h>

LineTracker::LineTracker() {

}

void LineTracker::Initialize(){
}

void LineTracker::Execute() {
//	if(delaytimer.Get()>=delaytime){
//		delaytimer.Stop();
//		delaytimer.Reset();
//		delay = false;
//	}else if(delay){
//		delaytimer.Start();
//		SmartDashboard::PutBoolean("ischanged",true);
//	}
//	if(linevalue.size()>3){
//		sort(linevalue.begin(),linevalue.end());
//		color = linevalue[1];
//		linevalue.clear();
//	}
//	else linevalue.push_back(linetracker.GetValue());
	if(abs(growcolor)>range){
		Robot::ischanged = true;
		delay = true;
	}
	else Robot::ischanged = false;
//	if(!delay)SmartDashboard::PutBoolean("ischanged",Robot::ischanged);
		growcolor = lastcolor-color;
		SmartDashboard::PutNumber("growcolor",growcolor);
		lastcolor = color;
//	}
	SmartDashboard::PutNumber("color",color);
	SmartDashboard::PutNumber("colorsensor",linetracker.GetValue());
}

bool LineTracker::IsFinished() {
	return false;
}
