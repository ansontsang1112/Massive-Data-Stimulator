#include <vector>
#include <iostream>
#include <math.h>
#include "renGen.h"
#include "Calculation.h"

using namespace std;

int Calc::getSum(vector<int>num) {
	int result;
	for (int i = 0; i < num.size(); i++) {
		result += num.at(i);
	}
	return result;
}

double Calc::getMean(vector<int>num, int sum) {
	return (sum / num.size());
}

double Calc::getSD(vector<int>num, int sum) {
	double sqrSum;
	for (int i = 0; i < num.size(); i++) {
		sqrSum += sqrt(pow((num.at(i) - getMean(num, getSum(num))),2));
	}
	return sqrSum / num.size();
}