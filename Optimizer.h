#pragma once
#include "Selector.h"
#include "Timer.h"
#include "Individual.h"
#include "Evaluator.h"

#include <random>
#include <vector>

using namespace std;

class Optimizer
{
	friend class Selector;
protected:

	CLFLnetEvaluator &evaluator; //problem
	vector<Individual*>* population;
	Selector* selector;
	double crossPropability;
	double mutationPropability;

	int growthSize; // wielkość nowego miotu osobników
	int popSize;
	

public:

	Optimizer(CLFLnetEvaluator &eval) :evaluator(eval){  // konstruktor
		population = new vector<Individual*>;
		popSize = DEFAULT_POPULATION_SIZE;
		growthSize= (int)GROWTH_SIZE_PERCENT / PERCENT_BASE; 
		generateRandomPopulation();
	};// co robi ta linijka? zastępuje przypisanie wartości do ewaluatora, ale tak dokładniej?

	~Optimizer() {};

	virtual void initialize() ; // konfiguraca ustawień początkowych w tym tworzenie populacji!!
	virtual void runIteration() {}; // podstawowa iteracja
	virtual void cross() {}; //krzyżowanie
	virtual void mutate() {}; //mutacja
	virtual void punish() {}; // kara za przekroczenie warunków
	virtual void adaptParams() {}; // zmiana parametrów (np szanse na mutację), potencjalnie nawet selektora
	
	int getPopulationSize() { return popSize; };
	int getGrowthSize() { return growthSize; }
	vector<Individual*>* getPopulation() { return population; }


	//the best of iteration
	Individual* getCurrentBest() { return selector->getCurrentBest(); } //geter
	double getCurrentBestFitness() { return selector->getCurrentBestFitness(); } //geter


	//population management
	void generateRandomPopulation();
	void setPopulationSize(int val) {
		popSize = val;
		population->resize(popSize);
	};
	void killByIndexes(vector<int>* individualIndexes);
	void addIndividual(Individual* individual);
	Individual* getIndividualByIndex(int index) {
		if (index < population->size()) return population->at(index);
		else return 0;
	}
};