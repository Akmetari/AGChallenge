#pragma once
#include <vector>
#include <cmath>
#include "Config.h"
#include "Evaluator.h"

using namespace std;

class Individual
{
private:
	double fitness;
	vector<int>* genotype;
	bool changed;

public:

	~Individual() {delete genotype;}

	void fillRandom(CLFLnetEvaluator* eval);

	int getSize() { return genotype->size(); }
	int getGenome(int index) {
		if (index < genotype->size()) return genotype->at(index);
		else return genotype->at(0);
	}
	void setGenome(int val, int index) { genotype->at(index) = val; }
	void setChanged(bool b) { changed = b; }

	vector<int>* getGenotype() { return genotype; }

	Individual(CLFLnetEvaluator* eval);
	Individual(vector<int>* genotypeParam);

	void evaluate(CLFLnetEvaluator* evaluator) {
		fitness = evaluator->dEvaluate(genotype);
	}

	double getFitness(CLFLnetEvaluator* evaluator) {
		if (changed) {
			evaluate(evaluator);
			changed = false;
		}
		return fitness;
	}

	void setFitness(double d) { fitness = d; }

	vector<Individual*>* cross(Individual* partner);
	void mutate(CLFLnetEvaluator* eval);
	vector<int>* pickNCrossPoints(int n);
};

