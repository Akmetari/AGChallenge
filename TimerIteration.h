#pragma once
#include "Timer.h"
#include "Config.h"


class TimerIteration: public Timer
{
private:
	int iterationNumber;

public:
	TimerIteration() :Timer() {
		iterationNumber = 0;
	};

	~TimerIteration(){};

	virtual void  setStart() { started = true; };

	virtual void passTime() { iterationNumber++; };
	
	virtual bool  getTimePassed() {return iterationNumber>0; };//if returned value is false it means the timer was not set on start
	
	virtual bool  setFinish(double  dTimeToFinishSec);
	virtual bool  isFinished();

};

