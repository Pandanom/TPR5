// TPR5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

double tp, fp, fn, tn, l12, l21;

int main()
{
	cout << "Enter Tp: ";
	cin >> tp;
	cout << "Enter Fp: ";
	cin >> fp;
	cout << "Enter Fn: ";
	cin >> fn;
	cout << "Enter Tn: ";
	cin >> tn;
	cout << "Enter L12: ";
	cin >> l12;
	cout << "Enter L21: ";
	cin >> l21;
	auto Se = tp / (tp + fn);
	cout << "Se = " << Se << endl;
	auto Sp = tn / (tn + fp);
	cout << "Sp = " << Sp << endl;
	auto w = l12 / l21;
	cout << "w = " << w << endl;
	auto p = (tp + fn) / (tp + fn + fp + tn);
	cout << "p = " << p << endl;
	if (p*(w + 1) < 1)
	{
		cout << "Diagnostical test: " <<(((1 - p)*(1 - Sp) < w*p*Se) ? "true" : "false" )<< endl;
	}
	else if (p*(w + 1) > 1)
	{
		cout << ("Diagnostical test: " + ((1 - p)* Sp > w*p*(1-Se)) ? "true" : "false" )<< endl;
	}
	else
	{
		cout << "Diagnostical test undefined" << endl;
	}
	auto min = ((1 - p) / p)*((1 - Sp) / Se);
	auto max = ((1 - p) / p)*(Sp/(1 - Se));
	cout << "Bounds: ["<<min <<", "<< max <<"]" << endl;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
