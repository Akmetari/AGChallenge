#pragma once
#include <vector>
#include <algorithm>

#include "Individual.h";
#include "Evaluator.h"

//klasa rodzic na różne możliwe metody selekcji
class Selector
{
protected:
	bool isPopulation = false;
	vector < double* >* sortedPopulation;
	void sortPopulation(vector<Individual*>* pop, CLFLnetEvaluator &eval);
	vector<double*>* createPopRepresentation(vector<Individual*>* pop, CLFLnetEvaluator &eval);
	Individual* currentBest;
	double currentBestFitness;

public:
	virtual vector<int>* select(int growthSize, vector<Individual*>* pop, CLFLnetEvaluator &eval) { return nullptr; };// metoda selekcji

	vector<int>* getSortedIndexes(vector<Individual*>* pop, CLFLnetEvaluator &eval);
	Selector() {};

	Individual* getCurrentBest() { return currentBest; }
	double getCurrentBestFitness(){return currentBestFitness; }

};

