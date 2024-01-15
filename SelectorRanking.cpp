#include "SelectorRanking.h"

vector<int>* SelectorRanking::select(int growthSize, vector<Individual*>* pop, CLFLnetEvaluator &eval) {
	vector<int>* killList=new vector<int>;
	int killSize = growthSize; 
	sortPopulation(pop,eval);
	for (int i = 0; i < killSize; i++) {
		killList->push_back((int)(sortedPopulation->at(i)[0]));
	}
	
	return killList;
};