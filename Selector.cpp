#include "Selector.h"


using namespace std;

void Selector::sortPopulation(vector<Individual*>* pop, CLFLnetEvaluator &eval) {
	if (isPopulation) {
		for (int i = 0; i < sortedPopulation->size(); i++) delete sortedPopulation->at(i);
		delete sortedPopulation;
	}
	isPopulation = true;
	sortedPopulation = createPopRepresentation(pop,eval);
	sort(sortedPopulation->begin(), sortedPopulation->end(), [](const void* rep1, const void* rep2) { // rep= representation od individual by index and fitness
		double* ptr1 = (double*)rep1;
		double* ptr2 = (double*)rep2;

		if (ptr1[1] >= ptr2[1]) return false;
		if (ptr1[1] < ptr2[1]) return true;
		
	
	}); 

	currentBest=pop->at(sortedPopulation->at(sortedPopulation->size() - 1)[0]);
	currentBestFitness= sortedPopulation->at(sortedPopulation->size() - 1)[1];
}

vector<double*>* Selector::createPopRepresentation(vector<Individual*>* pop, CLFLnetEvaluator &eval) {
	vector<double*>* representation=new vector<double*>;
	double* rep;
	
	for (int i = 0; i < pop->size(); i++) {
		rep = new double[2];
		rep[0] = i;
		rep[1] = eval.dEvaluate(pop->at(i)->getGenotype());
		representation->push_back(rep);
	}

	return representation;
}

vector<int>* Selector::getSortedIndexes(vector<Individual*>* pop, CLFLnetEvaluator &eval) {
	vector<int>* sortedIndexes = new vector<int>;
	sortPopulation(pop,eval);
	for (int i = 0; i < sortedPopulation->size(); i++) {
		sortedIndexes->push_back((int)(sortedPopulation->at(i)[0]));
	}

	return sortedIndexes;
}