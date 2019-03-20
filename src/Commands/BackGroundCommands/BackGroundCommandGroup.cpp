#include "BackGroundCommandGroup.h"
#include "ColorDetect.h"
#include "Collision.h"
#include "Log.h"
#include "LineTracker.h"

#include <Port.h>
#include <Robot.h>

BackGroundCommandGroup::BackGroundCommandGroup() {
	//AddParallel(new ColorDetect());
	AddParallel(new Collision());
	AddParallel(new Log());
	AddParallel(new LineTracker());
}
