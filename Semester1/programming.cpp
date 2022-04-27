#include <iostream>
#include <math.h>
using namespace std;

float sqr_quation() 
{
	float a, b, c, x1, x2, d;
	cout << "Enter the coefficients: " << endl;
	cin >> a >> b >> c;

	if (a == 0)
	{
		x1 = -c / b;
		cout << "Base of equation: " << x1 << endl;
	}
	else
	{
		d = b * b - 4 * a * c;
		if (d < 0)
			cout << "D < 0." << endl;
		else if (d == 0)
		{
			x1 = -b / (2 * a);
			cout << "Base of equation: " << x1 << endl;
		}
		else
		{
			x1 = (-b - sqrt(d)) / (2 * a);
			x2 = (-b + sqrt(d)) / (2 * a);
			cout << "Base of equation: " << x1 << "and " << x2 << endl;
		}
	}

	return 0;
}

float factorial(int n)
{
	float s = 1;
	for (int i = 2; i <= n; i++)
		s *= i;
	
	return s;
}

float sumFactorial()
{
	float s = 1;
	for (int i = 1; i <= 1e+12; i++)
	{
		float f = 1 / factorial(i);
		if (f < 1e-12)
			break;
		s = s + f;
	}
	cout << s << endl;

	return 0;
}

int bb()
{
	sumFactorial();

	return 0;
}