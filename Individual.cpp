#include "Individual.h"

void Individual::fillRandom(CLFLnetEvaluator* eval) {
	genotype->clear();
	for (int i = 0; i < eval->iGetNumberOfBits(); i++) {
		srand(time(NULL));
		genotype->push_back((int)rand()* eval->iGetNumberOfValues(i) /RAND_MAX);
	}
}


Individual::Individual(CLFLnetEvaluator* eval) {
	fitness = 0;
	genotype = new vector<int>;
	fillRandom(eval);
	changed = true;
}

Individual::Individual(vector<int>* genotypeParam) {
	fitness = 0;
	genotype = genotypeParam;
	changed = true;
}



vector<Individual*>* Individual::cross(Individual* partner) {
	vector<int>* crossPoints= pickNCrossPoints(CROSS_POINTS_NUMBER);
	vector<Individual*>* children=new vector<Individual*>;

	vector<int>* child1 = new vector<int>;
	vector<int>* child2 = new vector<int>;

	vector<int>* parent1Genotype = this->genotype;
	vector<int>* parent2Genotype = partner->genotype;

	vector<int>* child1Source=parent1Genotype;
	vector<int>* child2Source=parent2Genotype;
	vector<int>* tmp;


	for (int i = genotype->size()-1; i>0 ; i--) {
		if (i== crossPoints->at(crossPoints->back())) {
			tmp = child1Source;
			child1Source = child2Source;
			child2Source = tmp;
			crossPoints->pop_back();
		}
		child2->push_back(child1Source->at(i)); 
		child1->push_back(child2Source->at(i));
	}
	
	children->push_back(new Individual(child1));
	children->push_back(new Individual(child2));
	delete crossPoints;
	return children;
}


void Individual::mutate(CLFLnetEvaluator* eval) {
	int position;
	for (int i = 0; i < MUTATION_SIZE*genotype->size()/ PERCENT_BASE; i++) {
		srand(time(NULL));
		position = (int)(rand()* genotype->size() / RAND_MAX);
		setGenome((int)rand()* eval->iGetNumberOfValues(position) / RAND_MAX, position);
	}
	changed = true;
}

vector<int>*  Individual::pickNCrossPoints(int n) {
	vector<int>* crossPoints = new vector<int>;
	srand(time(NULL));
	int genSize = genotype->size();
	int* chosenPoints = new int[genSize];
	int possiblePoint = 0;

	for (int i = 0; i < genSize; i++) { chosenPoints[i] = 0; }

	for (int i = 0; i < n; i++) {
		do {
			possiblePoint = (int)(rand() *genSize / RAND_MAX);
		} while (chosenPoints[possiblePoint] != 0);
		crossPoints->push_back(possiblePoint);
		chosenPoints[possiblePoint = 1];
	}

	delete chosenPoints;

	sort(crossPoints->begin(), crossPoints->end(), [](int rep1, int rep2) { // rep= representation od individual by index and fitness
		if (rep1 >= rep2) return false;
		if (rep1 < rep2) return true;
	});
	return crossPoints;
}