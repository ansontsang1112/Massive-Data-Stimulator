#pragma once
#include <vector>
#include <iostream>
#include <math.h>

class Data {
public:
	long sum;
	double mean, sd, var;
};

class Calc {
public:
	long getSum(std::vector<int>);
	double getMean(std::vector<int>, int);
	double getSD(std::vector<int>, double);
};
