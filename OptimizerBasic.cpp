#include "OptimizerBasic.h"

void OptimizerBasic :: initialize() { // konfiguraca ustawień początkowych w tym tworzenie populacji
	generateRandomPopulation();
	selector = new SelectorRanking();  
	crossPropability = DEFAULT_CROSS_PROP;
	mutationPropability = DEFAULT_MUTATION_PROP;
}; 


void OptimizerBasic::runIteration() {// podstawowa iteracja
	mutate();
	cross();
	//punish();
	killByIndexes(selector->select(growthSize,population,evaluator));
}; 


void OptimizerBasic::cross() {
	crossBestWorst();

}; 

void OptimizerBasic::crossRandom() {
	int size = population->size();
	int childrenNumber = 0;
	int individualIndex = 0;
	int partnerIndex = 0;
	vector<Individual*>* children = new vector<Individual*>;
	vector<Individual*>* individualsChildren = new vector<Individual*>;
	Individual* indTmp;

	srand(time(NULL));

	while (childrenNumber < size) {
		srand(time(NULL));
		individualIndex = (int)(size*rand() / RAND_MAX);

		if (PERCENT_BASE * rand() / RAND_MAX < crossPropability) {
			indTmp = getIndividualByIndex(individualIndex);

			do {
				partnerIndex = (int)(popSize*rand() / RAND_MAX);

			} while (partnerIndex == individualIndex);

			individualsChildren = indTmp->cross(getIndividualByIndex(partnerIndex));
			for (int i = 0; i < individualsChildren->size(); i++) children->push_back(individualsChildren->at(i));
			childrenNumber += individualsChildren->size();
			delete individualsChildren;
		}
	}

	population->insert(population->end(), children->begin(), children->end());
	setPopulationSize(size + children->size());
	delete children;
}


void OptimizerBasic::crossBestWorst() {
	int childrenNumber = 0;
	int individualIndex = 0;
	int partnerIndex = 0;
	int crossCount=0;
	int size = population->size();
	vector<int>* populationSortedIndexes = selector->getSortedIndexes(population,evaluator);
	vector<Individual*>* children = new vector<Individual*>;
	vector<Individual*>* individualsChildren = new vector<Individual*>;
	Individual* indTmp;

	srand(time(NULL));

	while (childrenNumber < growthSize) {
	
		if (crossCount > size - 1) crossCount = 0;
		individualIndex = populationSortedIndexes->at(size-1-crossCount);
		partnerIndex = populationSortedIndexes->at(crossCount);
		crossCount++;

		indTmp = getIndividualByIndex(individualIndex);

		if (PERCENT_BASE* rand() / RAND_MAX < crossPropability) {

			individualsChildren = indTmp->cross(getIndividualByIndex(partnerIndex));
			for (int i = 0; i < individualsChildren->size(); i++) children->push_back(individualsChildren->at(i));
			childrenNumber += individualsChildren->size();
			delete individualsChildren;
		}
	}

	population->insert(population->end(), children->begin(), children->end());
	setPopulationSize(size + children->size());
	delete children;
}

void OptimizerBasic::crossTournament() {

}


void OptimizerBasic::mutate() {//mutacja
	double tmp;
	srand(time(NULL));
	for (int i = 0; i < population->size(); i++) {
		
		tmp = PERCENT_BASE *rand() / (RAND_MAX);
		if (getCurrentBest() != (getIndividualByIndex(i)) && tmp< mutationPropability) {
			getIndividualByIndex(i)->mutate(&evaluator);
		}
	}
}; 

void OptimizerBasic::punish() {
	int individualLen = evaluator.iGetNumberOfBits();
	int maxIntOnPosition;
	Individual* indPtr;

	for (int i = 0; i < population->size(); i++) {
		indPtr = getIndividualByIndex(i);
		if (indPtr->getSize() > individualLen) indPtr->setFitness(-200);
		else {
			for (int j = 0; j < indPtr->getSize(); j++) 
				if (indPtr->getGenome(j) > evaluator.iGetNumberOfBits()) indPtr->setFitness(-100);
		}
	}
}


void OptimizerBasic::adaptParams() {// zmiana parametrów (np szanse na mutację), potencjalnie nawet selektora}; // zmiana parametrów (np szanse na mutację), potencjalnie nawet selektora

};

