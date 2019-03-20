#include <Commands/BackGroundCommands/ColorDetect.h>
#include <Robot.h>

ColorDetect::ColorDetect() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
}

// Called just before this Command runs the first time
void ColorDetect::Initialize() {
	cs::UsbCamera camera = CameraServer::GetInstance()->StartAutomaticCapture(0);
	camera.SetResolution(640, 480);
	camera.SetBrightness(20);
	camera.SetExposureManual(20);
}

// Called repeatedly when this Command is scheduled to run
void ColorDetect::Execute() {
	if(CameraServer::GetInstance()->GetVideo().GrabFrame(img)!= 0 && Robot::isdetecting)Detect();
}

// Make this return true when this Command no longer needs to run execute()
bool ColorDetect::IsFinished() {
	return false;
}

Mat Crop(Mat mat,int x,int y){
	Rect roi;
	roi.x = x;
	roi.y = y;
	roi.width = mat.size().width;
	roi.height = mat.size().height/2;
	return mat(roi);
}

Mat distance(Mat img,Scalar color){
	Mat matcolor(img.rows,img.cols,img.type(),color);
	Mat temp = matcolor-img;
	pow(temp,2,temp);
	return temp;
}

int comparecolor(Mat img){
	Mat bluedistance = distance(img,Scalar(255, 0, 0));
	Mat reddistance = distance(img,Scalar(0, 0, 255));
	Mat temp1,temp2;
	compare(reddistance,bluedistance,temp1,cv::CMP_GT);
	compare(bluedistance,reddistance,temp2,cv::CMP_GT);
	cvtColor(temp1,temp1, CV_BGR2GRAY);
	cvtColor(temp2,temp2, CV_BGR2GRAY);
	int red = countNonZero(temp1);
	int blue = countNonZero(temp2);
	if(blue>red)return 0;
	else if(red>blue)return 1;
	else return 2;
}

void ColorDetect::Detect(){
	Mat topcrop = Crop(img,0,0);
	Mat downcrop = Crop(img,0,img.size().height/2);
	//cout << comparecolor(topcrop) << endl;
	cout << comparecolor(downcrop) << endl;
	Robot::isourteam = comparecolor(downcrop)==Robot::ds.GetAlliance();
}
