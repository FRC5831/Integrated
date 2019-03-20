#include "Delay.h"

Delay::Delay(double delay_time) {
	SetTimeout(delay_time);
}

void Delay::Execute() {

}

bool Delay::IsFinished() {
	return IsTimedOut();
}
