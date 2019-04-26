#pragma once
#include <iostream>
#include <vector>
#include <math.h>
#include <random>

using namespace std;

std::vector<int>getNum(int size, int gen, int ini, int tem) {
	vector<int>num;
	for (int i = 0; i < size; i++) {
		 num.push_back((gen == 1) ? (rand() % (tem - ini + 1) + ini) : (rand() % tem + 1));
	}

	return num;
}