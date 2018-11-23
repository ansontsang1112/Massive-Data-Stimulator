#include "pch.h"
#include "calculation.h"
#include <math.h>
#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;

int calculation::getSum(int num[], int size) {
	int sum = 0;
	for (int i = 0; i < size; i++) {
		sum += num[i];
	}
	return sum;
};

double calculation::getMean(int num[], int size, int rtime) {
	double sum = 0;
	for (int i = 0; i < rtime * size; i++) {
		sum += num[i];
	}
	return (sum / (size * rtime));
};

double calculation::getSD(int num[], double mean, int size, int rtime) {
	double sum2 = 0;
	for (int i = 0; i < size * rtime; i++) {
		sum2 += pow((num[i] - mean), 2);
	}
	return (sqrt(sum2 / (size * rtime)));
};