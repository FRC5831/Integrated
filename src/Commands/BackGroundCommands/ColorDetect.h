#ifndef ColorDetect_H
#define ColorDetect_H

#include <Commands/Command.h>
#include <CameraServer.h>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/core/types.hpp>
#include <iostream>

using namespace cv;
using namespace std;

class ColorDetect : public Command {
public:
	ColorDetect();
	void Initialize();
	void Execute();
	bool IsFinished();
	void Detect();
private:
	Mat img;
};

#endif  // ColorDetect_H
