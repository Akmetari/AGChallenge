#include "Evaluator.h"
#include "OptimizerBasic.h"
#include "OptimizerHotCold.h"
#include "OptimizerHamster.h"
#include "TimeCounter.h"
#include "TimerIteration.h"

#include <exception>
#include <iostream>
#include <random>

using namespace std;

#define dMAX_TIME 20 * 60


void vRunExperiment(CLFLnetEvaluator &cConfiguredEvaluator)
{
	try
	{
		int i = 0;
		double d_time_passed;

		Timer* time_counter= new TimerIteration(); //tu zmieniamy sposób liczenia czasu i warunek stopu

		Optimizer* optimizer= new OptimizerBasic(cConfiguredEvaluator); // tu zmieniamy typ optymalizatora

		time_counter->setStart();

		optimizer->initialize();

		time_counter->getTimePassed(&d_time_passed);

		while (!time_counter->isFinished())
		{
			i++;
			optimizer->runIteration();
			cout<<i<<":  "<<optimizer->getCurrentBestFitness()<<"\n";

			time_counter->passTime();
			time_counter->getTimePassed(&d_time_passed);
		}
	}
	catch (exception &c_exception)
	{
		cout << c_exception.what() << endl;
	}
}



void  vRunLFLExperiment(CString  sNetName)
{
	CLFLnetEvaluator c_lfl_eval;
	c_lfl_eval.bConfigure(sNetName);
	vRunExperiment(c_lfl_eval);
	
}



void main(int iArgCount, char **ppcArgValues)
{
	random_device c_mask_seed_generator;
	int i_mask_seed = (int)c_mask_seed_generator();


	CString  s_test;
	vRunLFLExperiment("104b09");

}