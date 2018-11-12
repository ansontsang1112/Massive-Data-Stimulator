#include <iostream>
#include <stdio.h>
#include <exception>
#include <stdlib.h>
#include <math.h>
#include <string>
#include <fstream>

using namespace std;

double getMean(int []);
double getSD(int []);
double getStd(int []);
int getSum(int []);


#define max 100000000
#define min 1

/*"Count / Set can not define as 0, Initial & Terminal No. cannot smaller than 1 or bigger than 1 x 10^8 !!"*/

/*Globle Var*/
int set = 0, count = 0, r_i, r_t, discriminant = 0, dfq = 0;
float mean, sd, z, ss = 0;
int rep[max], tmp[max], sto[max];
string errmsg;

struct NumException : public exception
{
  const char * what() const throw()
  {
    return "Count / Set can not define as 0, Initial & Terminal No. cannot smaller than 1 or bigger than 1 x 10^8 !!";
  }
};

void define() {
	system("CLS");
	try {
		cout << "\n\tNotice: Set and Count should not larger than " << max << " . Otherwise, the program will error and crush.\n" << endl;
	    cout << "Please insert the size of the set  ( Max. value = " << max << " ) : " ;
	    cin >> set;
	    if(set <= 0 || set > max) {
	    	errmsg = "Exception Number <Set> detected. 0x0001";
		}
	    cout << "\nPlease insert the szie of repeat calc. ( Max. value = " << max << " ) : " ;
	    cin >> count;
	    if (count <= 0 || count > max) {
	    	errmsg = "Exception Number <Count> detected. 0x0002";
		}
	    cout << "\nPlease insert the Starting (Initial) value of r1 : ";
	    cin >> r_i;
	    if (r_i < 1) {
	    	errmsg = "Exception Number <r_i> detected. 0x0003";
		}
	    cout << "\nPlease insert the Ending value of r1 : ";
	    cin >> r_t;
	    if (r_t < 1) {
	    	errmsg = "Exception Number <r_t> detected. 0x0004";
		}
	    if(count <= 0 || count > max || set > max || set <= 0 || r_i < 1 || r_t < 1) {
	    	throw NumException();
		}
		system("cls");
		cout << "\nPlease comfirm the following number:\n";
		cout << "The sizes of 1 set is = " << set << endl;
		cout << "The times of counts is = " << count << endl;
		cout << "The Starting (Initial) Value is = " << r_i << endl;
		cout << "The Ending Value is = " << r_t << endl;
		cout << "The totoal random combination will be = " << set * count << endl;
		cout << "" << endl;
		cout << "Press 'ANY KEY' if you think that is right, type [X] if the input is wrong !!" << endl;
		system("pause");
	} catch (NumException& e) {
		system("cls");
		cout << "\n\t ***** Error Cauget *****\n";
	    cout << "Error Type : Number Exception\n" << endl;
	    cout << "Error Message: " << errmsg << "\n"<< endl;
        cout << e.what() << endl;
		cout << "\nWe will return and reinsert the data again, please wait for 10 second." << endl;
		system("timeout 10");
		return define();
	} catch(std::exception& e) {
		system("CLS");
		cout << "\n\t ***** Error Cauget *****\n";
	    cout << "Error Type : Unknown Exception\n" << endl;
		cout << "\nTo prevent the data corruption, auto exit in 10 second." << endl;
		system("timeout 10");
		exit(0);
	}
}

void rgen() {
	for(int i = 0; i < set; i++) {
		tmp[i] = (r_i != 1) ? (rand() % (r_t - r_i + 1) + r_i) : (rand() % r_t + 1);
	}
	discriminant += 1;
	sto[discriminant - 1] = getSum(tmp);
	if(discriminant < count) {
		return rgen();
	}
}

void result() {
	mean = getMean(sto);
	sd = getSD(sto);
}

/*result.txt opcli*/
void sao() {
	int goku;
	goku = (ss == 0) ? 0 : 1;
	ofstream result;
	result.open("result.txt");
	result << "Calclation result for DCS: \n" << endl;
	result << "Basic infomation ||" << endl;
	result << "Exported Date : " << __DATE__ << endl;
	result << "Exported Time : " << __TIME__ << endl;
	result << "Exported File Name : " << __FILE__ << endl;
	switch(goku) {
		case 0:
			result << "\nInputted Data ||" << endl;
			result << "Set (DBS) Initiated sizes : " << set << endl;
			result << "Count (RPT) Initiated times : " << count << endl;
			result << "Total Items (TOI) : " << count * set << endl;
			result << "Initial (First Ratio) Random Number : " << r_i << endl;
			result << "Terminated (Last Ratio) Random Number : " << r_t << endl;
			result << "\nCalcation Results ||" << endl;	
			result << "Mean of " << count * set << "'s' result = " << mean << endl;
			result << "S.D. of " << count * set << "'s result = " << sd << endl;
			result << "Var. of " << count * set << "'s result = " << pow(sd, 2) << endl;
			result.close();
			break;
		case 1:
			result << "\nCommon Result ||" << endl;
			result << "Mean of " << count * set << "'s' result = " << mean << endl;
			result << "S.D. of " << count * set << "'s result = " << sd << endl;
			result << "Var. of " << count * set << "'s result = " << pow(sd, 2) << endl;
			result << "\nCalcation Results ||" << endl;
			result << "The Score (Zi) : " << z << endl;
			result << "The Standard Score (Zr) : " << ss << endl;
			result.close();
			break;
	}
};


void present() {
	char ch1, ch2 = 0, ill;
	string choice_A, choice_B, choice_C;
	choice_A = "A: Print out the Mean, SD, Total count, Set Value to a 'result.txt' ";
	choice_B = "B: Find the standard score (z) of a spec. value.";
	choice_C = "C: Exit the Program.";
	
	system("cls");
	cout << "\nThe result is : \n";
	cout << "The Mean of " << set * count << " ramdom combination between " << r_i << " to " << r_t << " is = " << mean << endl;
	cout << "The SD of " << set * count << " ramdom combination between " << r_i << " to " << r_t << " is = " << sd << endl;
	cout << "" << endl;
	cout << "******* Slection Menu *******\n" << endl;
	cout << choice_A << endl;
	cout << choice_B << endl;
	cout << choice_C << "\n" << endl;
	cout << "Please insert your selection (A/B/C) : ";
	cin >> ch1;
	switch(ch1) {
		case 'A':
		case 'a':
			sao();
			break;
		case 'B':
		case 'b':
			cout << "You have selected the option B, Find Standard Score." << endl;
			cout << "Please insert a valid number from 0 - " << max << " : "<< endl;
			cin >> z;
			cout << "\n You have inserted " << z << endl;
			system("cls");
			ss = (z - mean) / sd;
			sao();
			break;
		case 'C':
		case 'c':
			cout << "You are now exit the program without saveing, are you sure ? (Y / N) : ";
			cin >> ch2;
			if(ch2 == 'Y' || ch2 == 'y') {
				cout << "You are now exit without saving, thank you for using STCR.\n" << endl;
				system("pause");
				exit(0);	
			} else if(ch2 == 'N' || ch2 == 'n') {
				cout << "You will not return back to Selection Menu, please wait for 5 seconds." << endl;
				system("timeout 5");
				system("cls");
				return present();				
			}
		default:
			cout << "You have insert the illegel input < " << (ill = (ch2 == 0) ? ch1 : ch2)  << " > , failure to operate. Return menu in 10 secords" << endl;
			system("timeout 10");
			system("cls");
			return present();
			break;
	}
}

int main() {
	define();
	rgen();
	result();
	present();
	system("pause");
	return 0;
};

int getSum(int tmp[max]) {
	int sum = 0;
	for(int i = 0; i < set; i++) {
		sum += tmp[i];
	}
	return sum;
};

double getMean(int sto[max]) {
	float sum, mean;
	for(int i = 0; i < count * set; i++) {
		sum += sto[i];
	}
	return (sum/(set * count));
};

double getSD(int sto[max]) {
	float tmp;
	for(int i = 0; i < count * set; i++) {
		tmp += pow((sto[i] - mean), 2); 
	}
	return (sqrt(tmp/(count * set)));
}
