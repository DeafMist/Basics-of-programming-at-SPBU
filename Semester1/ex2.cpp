#include <iostream>
#include <cmath>
using namespace std;

const double phi = (1 + sqrt(5)) / 2;

double myfunc(double x) {
	return cos(x) + log(x);
}

bool sign(double val) {
	return val >= 0;
}

int ex2() {
	double a = 0, b = 1;
	double epsi = 1e-8;
	double x1 = 0, x2 = 0;
	while (abs(b - a) > epsi) {
		x1 = b - (b - a) / phi;
		x2 = a + (b - a) / phi;
		if (sign(myfunc(x1)) == sign(myfunc(a)) && sign(myfunc(x2)) == sign(myfunc(b)))
			a = x1;
		else if (sign(myfunc(x1)) != sign(myfunc(a)) && sign(myfunc(x2)) == sign(myfunc(b)))
			b = x2;
		else
			a = x1;
	}
	double x = (x1 + x2) / 2;
	cout << x << '\n' << myfunc(x);
	return 0;
}