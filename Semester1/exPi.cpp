#include <iostream>
#include <cmath>
using namespace std;

double searchPi() {
	int step = 8;
	double pi_old = 0, pi_new = 3, b = sqrt(2) / 2;
	while (abs(pi_old - pi_new) > 1e-8) {
		b = sqrt(b * b + pow(1 - sqrt(1 - b * b), 2)) / 2;
		pi_old = pi_new;
		pi_new = step * b;
		step *= 2;
	}
	return pi_new;
}

int exPi() {
	cout << "My pi = " << searchPi() << '\n';
	return 0;
}