#include "TimerIteration.h"

 bool  TimerIteration::isFinished() { 
	 return iterationNumber>= MAX_ITERATION_NUMBER; 
 };

 bool  TimerIteration::setFinish(double  dTimeToFinishSec) {
	 if (!started) return false;
	 finished = true;
	 return true;
 };
