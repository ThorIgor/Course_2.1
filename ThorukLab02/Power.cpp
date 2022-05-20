#include<iostream>

using namespace std;

double power(double num, unsigned int pow) {
	if (pow <= 0)
		return 1;
	double result = num;
	int count = 0;
	for (int i = 1; i < pow; i++) {
		result *= num;
		count++;
	}
	cout << "Count: " << count << endl;
	return result;
}

double quickPower(double num, unsigned int pow) {
	if (pow <= 0)
		return 1;
	double result = num;
	int i = 1, count = 0;
	while (i < pow-1)
	{
		if (i * 2 < pow)
			result *= result;
		else
			result *= num;
		i++;
		count++;

	}
	cout << "Count: " << count << endl;
	return result;
}

double recPower(double num, unsigned int pow) {
	if (pow <= 0)
		return 1;
	if (pow == 1)
		return num;
	return recPower(num, --pow) * num;
}
double recQuickPower(double num, unsigned int pow) {
	if (pow <= 0)
		return 1;
	if (pow == 1)
		return num;
	if (pow % 2 == 1)
		return recQuickPower(num, pow-1) * num;
	else
		return recQuickPower(num * num, pow / 2);
}