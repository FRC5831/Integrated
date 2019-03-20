#ifndef Collision_H
#define Collision_H

#include <Commands/Command.h>
#include"AHRS.h"
#include"WPILib.h"

class Collision : public Command {
public:
	Collision();
	void Initialize();
	void Execute();
	bool IsFinished();
private:
	AHRS *ahrs;

	float accelx = 0;
	float lastaccel = 0;
	float growaccel = 0;
	float lastgrow = 0;
	float rate = 0;
	const float hz = 0.1;//if hz become bigger, then the noise will become bigger;

	float hitforce = 85;

	float velocityx = 0;
	float lastvelo = 0;
	bool isMoving = false;

	bool delay = false;
	Timer delaytimer;
	const float delaytime = 0.1;
};

#endif  // Collision_H
