#pragma once
#include  "atlstr.h"  //CString
#include  <math.h>
#include  <time.h>
#include  "Timer.h"

#include <windows.h>


	class  TimeCounter: public Timer
	{
	public:

		TimeCounter();
		~TimeCounter();

		void  setStart();
		bool  getTimePassed(double  *pdTimePassedSec);//if returned value is false it means the timer was not set on start
		bool  setFinish(double  dTimeToFinishSec);
		bool  isFinished();
		void passTime() {};

	};