//
// Created by deafmist on 10.12.2020.
//

#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

vector<vector<double>> transpose(vector<vector<double>> x) {
    vector<vector<double>> y = {{0, 0, 0},
                                {0, 0, 0},
                                {0, 0, 0}};

    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            y[j][i] = x[i][j];

    return y;
}

vector<vector<double>> multiplication(vector<vector<double>> x, vector<vector<double>> y) {
    vector<vector<double>> z = {{0, 0, 0},
                                {0, 0, 0},
                                {0, 0, 0}};

    for (int i = 0; i < 3; ++i) {
        for (int k = 0; k < 3; ++k) {
            double sum = 0;
            for (int j = 0; j < 3; ++j)
                sum += x[i][j] * y[j][k];
            z[i][k] = sum;
        }
    }

    return z;
}

vector<int> maximum(vector<vector<double>> a) {
    vector<int> index = {0, 1};
    double max = abs(a[0][1]);

    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            if (abs(a[i][j]) > max and i != j) {
                max = abs(a[i][j]);
                index[0] = i;
                index[1] = j;
            }

    return index;
}

int jacobi() {
    vector<vector<double>> a = {{4, 2, 1},
                                {2, 5, 3},
                                {1, 3, 6}};
    double epsi = 1e-6, phi;

    while (sqrt(pow(a[0][1], 2) + pow(a[0][2], 2) + pow(a[1][2], 2)) > epsi) {
        vector<int> index = maximum(a);

        if (a[index[0]][index[0]] != a[index[1]][index[1]])
            phi = atan((2 * a[index[0]][index[1]]) / (a[index[0]][index[0]] - a[index[1]][index[1]])) / 2;
        else
            phi = M_PI / 4;

        vector<vector<double>> u = {{1, 0, 0},
                                    {0, 1, 0},
                                    {0, 0, 1}};
        u[index[0]][index[1]] = -sin(phi);
        u[index[1]][index[0]] = sin(phi);
        u[index[0]][index[0]] = cos(phi);
        u[index[1]][index[1]] = cos(phi);

        a = multiplication(transpose(u), a);
        a = multiplication(a, u);
    }

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cout << a[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}