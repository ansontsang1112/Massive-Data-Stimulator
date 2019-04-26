#pragma once
#include <vector>
#include <iostream>
#include <math.h>

class Calc {
public:
	int getSum(std::vector<int>);
	double getMean(std::vector<int>, int);
	double getSD(std::vector<int>, int);
};
