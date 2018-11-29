#include "pch.h"
#include "calculation.h"
#include <Windows.h>
#include <iostream>
#include <stdio.h>
#include <exception>
#include <stdlib.h>
#include <math.h>
#include <string>
#include <fstream>

using namespace std;

calculation calc;

#define max 100000000
#define min 1

/*"Count / Set can not define as 0, Initial & Terminal No. cannot smaller than 1 or bigger than 1 x 10^8 !!"*/

/*Globle Var*/
int set = 0, counter = 0, r_i, r_t, discriminant = 0, dfq = 0;
float mean, sd, z, ss = 0;
int rep[max], tmp[max], sto[max];
string errmsg;

struct NumException : public exception
{
	const char * what() const throw()
	{
		return "隨機數數目 / 反覆次數 不能被定義為 0, 初始化及終結數值不能少於 1 或大於 1 x 10^8 !!";
	}
};

void define() {
	system("CLS");
	try {
		cout << "\n\t請注意: 隨機數數目 / 反覆次數不能大於 " << max << " . 否則, 本程式將無法正常運作或導致程式出錯\n" << endl;
		cout << "請輸入隨機數數目的迴圈次數 [SET] ( Max. value = " << max << " ) : ";
		cin >> set;
		if (set <= 0 || set > max) {
			errmsg = "錯誤 <Set> 已被偵測. 0x0001";
		}
		cout << "\n請輸入重複計算次數 [RP. Time] ( Max. value = " << max << " ) : ";
		cin >> counter;
		if (counter <= 0 || counter > max) {
			errmsg = "錯誤 <Count> 已被偵測. 0x0002";
		}
		cout << "\n請輸入初始化數值 : ";
		cin >> r_i;
		if (r_i < 1) {
			errmsg = "錯誤 <r_i> 已被偵測. 0x0003";
		}
		cout << "\n請輸入隨機數最大值 : ";
		cin >> r_t;
		if (r_t < 1) {
			errmsg = "錯誤 <r_t> 已被偵測. 0x0004";
		}
		if (counter <= 0 || counter > max || set > max || set <= 0 || r_i < 1 || r_t < 1) {
			throw NumException();
		}
		system("cls");
		cout << "\n請確認以下數據: \n";
		cout << "每一次迴圈的大小 [SET SIZE] = " << set << "\n" << endl;
		cout << "迴圈次數 = " << counter << "\n" << endl;
		cout << "初始化數值 [I-VALUE] = " << r_i << "\n" << endl;
		cout << "終結數值 [T-VALUE] = " << r_t << "\n" << endl;
		cout << "隨機數總數 [T-SUM] = " << set * counter << "\n" << endl;
		cout << "" << endl;
		cout << "請按 '任意鍵' 若果上述資料確實無誤, 否則請按右上角的 [X]" << endl;
		system("pause");
	}
	catch (NumException& e) {
		system("cls");
		cout << "\n\t ***** 錯誤已被偵測 *****\n";
		cout << "錯誤類型 : 數據輸入錯誤\n" << endl;
		cout << "錯誤訊息: " << errmsg << "\n" << endl;
		cout << e.what() << endl;
		cout << "\n本程式將會把你重新導向到輸入數值部分，請細心等候。" << endl;
		Sleep(5000);
		return define();
	}
	catch (std::exception& e) {
		system("CLS");
		cout << "\n\t ***** 錯誤已被偵測 *****\n";
		cout << "錯誤類型 : 未知錯誤\n" << endl;
		cout << "\n為免造成數值錯誤，程式將會自動離開，請細心等候。" << endl;
		Sleep(5000);
		exit(0);
	}
}

void rgen() {
	for (int i = 0; i < set; i++) {
		tmp[i] = (r_i != 1) ? (rand() % (r_t - r_i + 1) + r_i) : (rand() % r_t + 1);
	}
	discriminant += 1;
	sto[discriminant - 1] = calc.getSum(tmp, set);
	if (discriminant < counter) {
		return rgen();
	}
}

void result() {
	mean = calc.getMean(sto, set, counter);
	sd = calc.getSD(sto, mean, set, counter);
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
	switch (goku) {
	case 0:
		result << "\nInputted Data ||" << endl;
		result << "Set (DBS) Initiated sizes : " << set << endl;
		result << "Count (RPT) Initiated times : " << counter << endl;
		result << "Total Items (TOI) : " << counter * set << endl;
		result << "Initial (First Ratio) Random Number : " << r_i << endl;
		result << "Terminated (Last Ratio) Random Number : " << r_t << endl;
		result << "\nCalcation Results ||" << endl;
		result << "Mean of " << counter * set << "'s' result = " << mean << endl;
		result << "S.D. of " << counter * set << "'s result = " << sd << endl;
		result << "Var. of " << counter * set << "'s result = " << pow(sd, 2) << endl;
		result.close();
		break;
	case 1:
		result << "\nCommon Result ||" << endl;
		result << "Mean of " << counter * set << "'s' result = " << mean << endl;
		result << "S.D. of " << counter * set << "'s result = " << sd << endl;
		result << "Var. of " << counter * set << "'s result = " << pow(sd, 2) << endl;
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
	cout << "The Mean of " << set * counter << " ramdom combination between " << r_i << " to " << r_t << " is = " << mean << endl;
	cout << "The SD of " << set * counter << " ramdom combination between " << r_i << " to " << r_t << " is = " << sd << endl;
	cout << "" << endl;
	cout << "******* Slection Menu *******\n" << endl;
	cout << choice_A << endl;
	cout << choice_B << endl;
	cout << choice_C << "\n" << endl;
	cout << "Please insert your selection (A/B/C) : ";
	cin >> ch1;
	switch (ch1) {
	case 'A':
	case 'a':
		sao();
		break;
	case 'B':
	case 'b':
		cout << "You have selected the option B, Find Standard Score." << endl;
		cout << "Please insert a valid number from 0 - " << max << " : " << endl;
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
		if (ch2 == 'Y' || ch2 == 'y') {
			cout << "You are now exit without saving, thank you for using STCR.\n" << endl;
			system("pause");
			exit(0);
		}
		else if (ch2 == 'N' || ch2 == 'n') {
			cout << "You will not return back to Selection Menu, please wait for 5 seconds." << endl;
			system("timeout 5");
			system("cls");
			return present();
		}
	default:
		cout << "You have insert the illegel input < " << (ill = (ch2 == 0) ? ch1 : ch2) << " > , failure to operate. Return menu in 10 secords" << endl;
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
