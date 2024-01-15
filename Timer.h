#pragma once
#include  "atlstr.h"  //CString
#include  <math.h>
#include  <time.h>

#include <windows.h>

class Timer
{

protected:
	bool  started;
	LARGE_INTEGER  start_position;
	LARGE_INTEGER  frequency;

	bool  finished;
	LARGE_INTEGER  finish_position;

public:

	Timer() {
		started = false;
		finished = false;
	};

	~Timer() {};

	virtual void  setStart() {};
	virtual void passTime() {};
	virtual bool  getTimePassed(double  *pdTimePassedSec) { return false; };//if returned value is false it means the timer was not set on start
	virtual bool  setFinish(double  dTimeToFinishSec) { return false; };
	virtual bool  isFinished() { return finished; };


};

