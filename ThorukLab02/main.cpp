#include<iostream>

#include"Power.h"

using namespace std;

void main()
{
	double n;
	unsigned int p;
	while (true) {
		/**/
		cout << "Power: n^p, n is Q, p is N" << endl;
		cout << "n: ";
		cin >> n;
		cout << "p: ";
		cin >> p;
		cout << n << "^" << p << "=" << power(n, p) << endl;
		
		/**/
		cout << "Quick power: n^p, n is Q, p is N" << endl;
		cout << "n: ";
		cin >> n;
		cout << "p: ";
		cin >> p;
		cout << n << "^" << p << "=" << quickPower(n, p) << endl;
		
		/**/
		cout << "Rec. power: n^p, n is Q, p is N" << endl;
		cout << "n: ";
		cin >> n;
		cout << "p: ";
		cin >> p;
		cout << n << "^" << p << "=" << recPower(n, p) << endl;
		

		cout << "Rec. quick power: n^p, n is Q, p is N" << endl;
		cout << "n: ";
		cin >> n;
		cout << "p: ";
		cin >> p;
		cout << n << "^" << p << "=" << recQuickPower(n, p) << endl;
	}
}