#pragma once





//propabilities
const double DEFAULT_MUTATION_PROP = 0.1;
const double DEFAULT_CROSS_PROP = 50;

//population
const int GROWTH_SIZE_PERCENT = 50;
const int DEFAULT_POPULATION_SIZE = 200;

//timers settings
const int	MAX_ITERATION_NUMBER = 10000;

//operation changes
const int MUTATION_SIZE = 5; // liczba miejscw których przeprowadzamy mutację;
const int CROSS_POINTS_NUMBER = 10;

//fitness changes
const int VALUE_PUNISH = -200;
const int LENGTH_PUNISH = -100;
const int AFTER_CHANGE_FITNESS = -100;

//math consts
const int PERCENT_BASE = 100;