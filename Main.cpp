#include <vector>
#include <iostream>
#include <math.h>
#include <string>
#include <Windows.h>
#include <stdio.h>
#include <exception>

#include "Calculation.h"

using namespace std;

int main(void) {
	vector <int> simContainer;
	int size, ini, tem, sxi;
	char ch1;

	cout << "Please insert the Number of Data need to stimulate: ";
	cin >> size;
	
	cout << "\nDo you need to start the stimlation from 0 ? (y/n): ";
	cin >> ch1;
	switch (ch1) {
	case 'Y':
	case 'y':
		cout << "Stimlation will be start at 0 ..." << endl;
		Sleep(2000);
		cout << "Please insert the termination value: ";
		cin >> tem;
		sxi = 0;
		break;
	case 'N':
	case 'n':
		cout << "Please insert the initial value: ";
		cin >> ini;
		cout << "Please insert the termination value: ";
		cin >> tem;
		sxi = 1;
		break;
	}



}