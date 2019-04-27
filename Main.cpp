#include <vector>
#include <iostream>
#include <math.h>
#include <string>
#include <Windows.h>
#include <stdio.h>
#include <exception>

#include "Calculation.h"
#include "renGen.h"

using namespace std;

vector<int>simData;

void stimlation(long, int, int, int);

int main(void) {
	vector <int> simContainer;
	long size;
	int ini, tem, sxi;
	char ch1;

	cout << "Please insert the Number of Data need to stimulate: ";
	cin >> size;
	
	cout << "\nDo you need to start the stimlation from 0 ? (y/n): ";
	cin >> ch1;
	switch (ch1) {
	case 'Y':
	case 'y':
		ini = 0;
		cout << "\nStimlation will be start at 0 ..." << endl;
		Sleep(2000);
		cout << "\nPlease insert the termination value: ";
		cin >> tem;
		sxi = 0;
		break;
	case 'N':
	case 'n':
		cout << "\nPlease insert the initial value: ";
		cin >> ini;
		cout << "\nPlease insert the termination value: ";
		cin >> tem;
		sxi = 1;
		break;
	}
	
	system("cls");

	cout << "Please Check the Value below:\n" << endl;
	cout << "The Initialized value = " << ini << endl;
	cout << "The Terminated value = " << tem << endl;
	cout << "The Maximun Size of stimlation = " << size << endl;
	
	cout << "\nIf the data above is fine, press any key to contiune the stimlation." << endl;
	system("pause");
	system("cls");

	stimlation(size, ini, tem, sxi);
}

void stimlation(long size, int ini, int tem, int sxi) {
	cout << "Stimlation Initializing ... " << endl;
	Sleep(1000);
	cout << "Constructing Var ..." << endl;
	Sleep(1000);
	cout << "Constructing Stimlation Data ..." << endl;
	simData = getNum(size, sxi, ini, tem);
	Sleep(1000);

	/*for (auto i : simData) {
		cout << "Data : " << i << endl;
	}*/

	Calc calc;
	Data data;

	cout << "Getting the Sum of Data ..." << endl;
	data.sum = calc.getSum(simData);
	Sleep(2000);
	cout << "Getting the Mean of Data ..." << endl;
	data.mean = calc.getMean(simData, size);
	Sleep(2000);
	cout << "Getting the Standard Deviation of Data ..." << endl;
	data.sd = calc.getSD(simData, data.mean);
	Sleep(2000);
	cout << "Getting the Variance of Data ..." << endl;
	data.var = pow(data.sd, 2);
	Sleep(2000);
	cout << "Generating the Report ..." << endl;
	cout << "Sum = " << data.sum << " Mean = " << data.mean << " SD = " << data.sd << " VAR = " << data.var << endl;
}