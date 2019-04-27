#include <vector>
#include <iostream>
#include <math.h>

#include "Calculation.h"

using namespace std;

long Calc::getSum(vector<int>num) {
	long result = 0;
	for (int i = 0; i < num.size(); i++) {
		result += num.at(i);
	}
	return result;
}

double Calc::getMean(vector<int>num, int sum) {
	return (sum / num.size());
}

double Calc::getSD(vector<int>num, double mean) {
	double sqrSum = 0;
	for (int i = 0; i < num.size(); i++) {
		sqrSum += sqrt(pow((num.at(i) - mean),2));
	}
	return sqrSum / num.size();
}