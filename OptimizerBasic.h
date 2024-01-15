#pragma once
#include "Optimizer.h"
#include "SelectorRanking.h"
#include "Config.h";
// most basic methods of optimalization

class OptimizerBasic: public Optimizer
{
public:
	OptimizerBasic(CLFLnetEvaluator& eval) //konstruktor
		: Optimizer(eval) {
	};

	~OptimizerBasic() {};

	virtual void initialize(); // konfiguraca ustawień początkowych w tym tworzenie populacji!!
	virtual void runIteration(); // podstawowa iteracja
	virtual void cross(); //krzyżowanie
	virtual void mutate(); //mutacja
	virtual void punish(); //mutacja
	virtual void adaptParams(); // zmiana parametrów (np szanse na mutację), potencjalnie nawet selektora

	void crossRandom();

	void crossBestWorst();

	void crossTournament();

	

};

