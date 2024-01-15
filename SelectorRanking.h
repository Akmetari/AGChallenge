#pragma once
#include "Selector.h"

class SelectorRanking: public Selector
{
public:
	virtual vector<int>* select(int growthSize, vector<Individual*>* pop, CLFLnetEvaluator &eval);
	SelectorRanking() :Selector() {};
};

