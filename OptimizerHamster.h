#pragma once
#include "Optimizer.h"
//optimize that in an iteration changes only the weakest part of population and leaves the best
//touching it only when the best isnt best anymore or increase in previous set wasnt big enough
class OpimizerHamster: public Optimizer
{
};

