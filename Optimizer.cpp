#include "Optimizer.h"

void Optimizer:: generateRandomPopulation() {
	for (int i = 0; i < population->size(); i++) delete population->at(i);
	population->clear();
	Individual* ind;
	for (int i = 0; i < popSize; i++) {
		ind = new Individual(&evaluator);
		population->push_back(ind);
	}

}

void Optimizer::killByIndexes(vector<int>* individualIndexes) {
	sort(individualIndexes->begin(), individualIndexes->end());

	for (int i = individualIndexes->size()-1; i >= 0; i--) {
		delete *(population->begin() + (*individualIndexes)[i]);
		population->erase(population->begin() + (*individualIndexes)[i]);
	}
	popSize = popSize - individualIndexes->size();
	delete individualIndexes;
}

void Optimizer::addIndividual(Individual* individual) {
	population->push_back(individual);
}

void Optimizer::initialize() {
	popSize = DEFAULT_POPULATION_SIZE;
	generateRandomPopulation();
}
