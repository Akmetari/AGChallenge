#pragma once
#include  "TimeCounter.h"

TimeCounter::TimeCounter()
{
	started  =  false;
	finished  =  false;
}

TimeCounter:: ~TimeCounter() {};



void TimeCounter::setStart()
{
	started  =  true;
	QueryPerformanceFrequency(&frequency);
	QueryPerformanceCounter(&start_position);
}


//if returned value is false it means the timer was not set on start
bool  TimeCounter::getTimePassed(double  *pdTimePassedSec)
{
	if  (started  ==  false)  return(false);

	LARGE_INTEGER  li_now;
	QueryPerformanceCounter(&li_now);

	double  d_result;

	d_result  =  (li_now.QuadPart  -  start_position.QuadPart);
	d_result  =  d_result  /  frequency.QuadPart;
	
	*pdTimePassedSec  =  d_result;

	return(true);
}//bool  CTimeCounter::bGetTimePassed(double  *pdTimePassedMs)


bool  TimeCounter::setFinish(double  dTimeToFinishSec)
{
	if  ( (started  ==  false)||(dTimeToFinishSec <= 0) )  return(false);

	finished  =  true;

	finish_position.QuadPart  =  start_position.QuadPart  +  frequency.QuadPart * dTimeToFinishSec;

	return(true);
}//bool  CTimeCounter::bSetFinishOn(double  dTimeToFinishMs)


bool  TimeCounter::isFinished()
{
	if  ( (started  !=  true)||(finished  !=  true) )
		return(true);

	LARGE_INTEGER  li_now;
	QueryPerformanceCounter(&li_now);
	if  (li_now.QuadPart  >  finish_position.QuadPart)
		return(true);
	else
		return(false);
};//bool  CTimeCounter::bIsFinished()






