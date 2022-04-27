#include <iostream>
#include <cmath>
using namespace std;

struct complex {
    double re;
    double im;
};

complex summation(complex complex1, complex complex2) { 
    return complex {complex1.re + complex2.re, 
                        complex1.im + complex2.im};
}

complex multiplication(complex complex1, complex complex2) { 
    return complex {complex1.re * complex2.re - complex1.im * complex2.im,
                        complex1.re * complex2.im + complex1.im * complex2.re};
}

complex division(complex complex1, complex complex2) { 
    complex2.im = -complex2.im;
    complex complex3 = multiplication(complex1, complex2);
    return complex {complex3.re / (pow(complex2.re, 2) + pow(complex2.im,2)),
                        complex3.im / (pow(complex2.re, 2) + pow(complex2.im,2))};
}

complex sinComplex(complex z) {
    double epsi = 1e-8;
    complex sum = z;
    complex element = z;
    int factorial = 1;
    int n = 1;
    complex zkv = multiplication(z, z);

    while (sqrt(pow(element.re, 2) + pow(element.im, 2)) > epsi) {
        n += 2;
        factorial *= -(n - 1) * n;
        element = multiplication(element, zkv);
        element.re /= factorial;
        element.im /= factorial;
        sum = summation(sum, element);
    }
    return sum;
}

int struct_complex() {
    complex z = {1, 1};
    complex res = sinComplex(z);
    cout << res.re << ' ' << res.im;
    return 0;
}