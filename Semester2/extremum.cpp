//
// Created by deafmist on 08.05.2021.
//

#include <iostream>
#include <cmath>
#include <string>
#include <ctime>
#include <Windows.h>
#include <vector>
using namespace std;

const double epsi = 1e-6;

double func(double x) {
    return pow(x, 3) - x + exp(-x);
}

void bisection(double a, double b, string minMax) {
    srand(time(0));
    int step = 0;
    double x;
    if (minMax == "min") {
        double a1 = a;
        double b1 = b;
        while (b1 - a1 > epsi) {
            step++;
            double delta = (b1 - a1) / 10;
            double a0 = (a1 + b1) / 2 - delta;
            double b0 = a0 + 2 * delta;

            if (func(a0) <= func(b0)) {
                b1 = b0;
            }
            else {
                a1 = a0;
            }
        }
        x = (a1 + b1) / 2;
    }
    else {
        double a1 = a;
        double b1 = b;
        while (b1 - a1 > epsi) {
            step++;
            double delta = (b1 - a1) / 10;
            double a0 = (a1 + b1) / 2 - delta;
            double b0 = a0 + 2 * delta;

            if (func(a0) > func(b0)) {
                b1 = b0;
            }
            else {
                a1 = a0;
            }
        }
        x = (a1 + b1) / 2;
    }

    cout << "Промежуток: [" << a << "; " << b << "]\n"
         << "Метод: bisection\n"
         << minMax << " значение функции: y = " << func(x) << '\n'
         << "Точка " << minMax << ": x = " << x << '\n'
         << "Количество шагов: " << step << '\n'
         << "Время работы программы: " << clock() / 1000.0 << '\n';
}

void goldenSection(double a, double b, string minMax) {
    srand(time(0));
    int step = 0;
    double x;
    if (minMax == "min") {
        double a1 = a;
        double b1 = b;
        while (b1 - a1 > epsi) {
            step++;
            double a0 = a1 + 2 * (b1 - a1) / (3 + sqrt(5));
            double b0 = a1 + 2 * (b1 - a1) / (1 + sqrt(5));

            if (func(a0) <= func(b0)) {
                b1 = b0;
            }
            else {
                a1 = a0;
            }
        }
        x = (a1 + b1) / 2;
    }
    else {
        double a1 = a;
        double b1 = b;
        while (b1 - a1 > epsi) {
            step++;
            double a0 = a1 + 2 * (b1 - a1) / (3 + sqrt(5));
            double b0 = a1 + 2 * (b1 - a1) / (1 + sqrt(5));

            if (func(a0) > func(b0)) {
                b1 = b0;
            }
            else {
                a1 = a0;
            }
        }
        x = (a1 + b1) / 2;
    }

    cout << "Промежуток: [" << a << "; " << b << "]\n"
         << "Метод: golden section\n"
         << minMax << " значение функции: y = " << func(x) << '\n'
         << "Точка " << minMax << ": x = " << x << '\n'
         << "Количество шагов: " << step << '\n'
         << "Время работы программы: " << clock() / 1000.0 << '\n';
}

void fibonacci(double a, double b, string minMax) {
    srand(time(0));
    vector<double> fibonaccies = vector<double> {1, 1};
    double a1 = a;
    double b1 = b;
    double x;

    while ((b - a) / fibonaccies[fibonaccies.size() - 1] > epsi) {
        double last = fibonaccies[fibonaccies.size() - 1];
        double lastLast = fibonaccies[fibonaccies.size() - 2];
        fibonaccies.push_back(last + lastLast);
    }

    int size = fibonaccies.size() - 1;
    int k = 1;

    if (minMax == "min") {
        for (int i = 0; i < size; i++) {
            double a0 = a1 + (b1 - a1) * fibonaccies[size - k - 1] / fibonaccies[size - k + 1];
            double b0 = a1 + (b1 - a1) * fibonaccies[size - k] / fibonaccies[size - k + 1];

            if (func(a0) <= func(b0)) {
                b1 = b0;
            }
            else {
                a1 = a0;
            }
            k++;
        }
        x = (a1 + b1) / 2;
    }
    else {
        for (int i = 0; i < size; i++) {
            double a0 = a1 + (b1 - a1) * fibonaccies[size - k - 1] / fibonaccies[size - k + 1];
            double b0 = a1 + (b1 - a1) * fibonaccies[size - k] / fibonaccies[size - k + 1];

            if (func(a0) > func(b0)) {
                b1 = b0;
            }
            else {
                a1 = a0;
            }
            k++;
        }
        x = (a1 + b1) / 2;
    }

    cout << "Промежуток: [" << a << "; " << b << "]\n"
         << "Метод: fibonacci\n"
         << minMax << " значение функции: y = " << func(x) << '\n'
         << "Точка " << minMax << ": x = " << x << '\n'
         << "Количество шагов: " << size << '\n'
         << "Время работы программы: " << clock() / 1000.0 << '\n';
}

void passiveSearch(double a, double b, string minMax) {
    srand(time(0));
    float ex, k;
    int step = 0;

    if (minMax == "min") {
        ex = func(a);

        for (double x = a; x <= b; x = x + epsi) {
            step++;
            if (func(x) < ex) {
                ex = func(x);
                k = x;
            }
        }
    }
    else {
        ex = func(a);

        for (double x = a; x <= b; x = x + epsi) {
            step++;
            if (func(x) > ex) {
                ex = func(x);
                k = x;
            }
        }
    }

    cout << "Промежуток: [" << a << "; " << b << "]\n"
         << "Метод: passive search\n"
         << minMax << " значение функции: y = " << ex << '\n'
         << "Точка " << minMax << ": x = " << k << '\n'
         << "Количество шагов: " << step << '\n'
         << "Время работы программы: " << clock() / 1000.0 << '\n';
}

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    bisection(-5, -3, "min");
    cout << '\n';
    goldenSection(-5, -3, "min");
    cout << '\n';
    fibonacci(-5, -3, "min");
    cout << '\n';
    passiveSearch(-5, -3, "min");
    cout << "\n\n";

    bisection(-3, 0, "max");
    cout << '\n';
    goldenSection(-3, 0, "max");
    cout << '\n';
    fibonacci(-3, 0, "max");
    cout << '\n';
    passiveSearch(-3, 0, "max");
    cout << "\n\n";

    bisection(0, 3, "min");
    cout << '\n';
    goldenSection(0, 3, "min");
    cout << '\n';
    fibonacci(0, 3, "min");
    cout << '\n';
    passiveSearch(0, 3, "min");
}