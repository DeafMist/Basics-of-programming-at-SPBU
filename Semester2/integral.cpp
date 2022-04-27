#include "iostream"
#include "string"
#include "vector"
#include "cmath"
using namespace std;

const int n = 3;

void showVector(vector<double> vec) {
    for (double i : vec) {
        cout << i << " ";
    }
    cout << '\n';
}

vector<double> multiplyMV(vector<vector<double>> matrix, vector<double> vec) {
    vector<double> result(n);
    for (int i = 0; i < n; ++i) {
        double sum = 0;
        for (int j = 0; j < n; ++j) {
            sum += vec[j] * -matrix[i][j];
        }
        result[i] = sum;
    }

    return result;
}

vector<double> multiplyVS(vector<double> vec, double scalar) {
    vector<double> result(vec.size());
    for (int i = 0; i < vec.size(); ++i) {
        result[i] = scalar * vec[i];
    }

    return result;
}

vector<double> summation(vector<double> vector1, vector<double> vector2) {
    vector<double> result(vector1.size());
    for (int i = 0; i < vector1.size(); ++i) {
        result[i] = vector1[i] + vector2[i];
    }

    return result;
}

double lenDif(vector<double> x, vector<double> xH) {
    vector<double> minus = summation(x, multiplyVS(xH, -1));
    double result = 0;
    for (auto i: minus) {
        result += i*i;
    }

    return sqrt(result);
}



int main () {
    vector<vector<double>> matrix = {{1, 1, 3},
                                     {4, 1, 6},
                                     {7, 8, 9}};
    vector<double> x = {1, 1, 1};
    vector<double> xH = {1, 1, 1};

    double h = 0.1;
    double t = 0;

    do {
        xH = {1, 1, 1};
        while(abs(1-t) > h/2) {
            vector<double> k1 = multiplyVS(multiplyMV(matrix, xH), h);
            vector<double> k2 = multiplyVS(
                    multiplyMV(matrix, summation(xH, multiplyVS(k1, 0.5))), h);
            vector<double> k3 = multiplyVS(
                    multiplyMV(matrix, summation(xH, multiplyVS(k2, 0.5))), h);
            vector<double> k4 = multiplyVS(multiplyMV(matrix, summation(xH, k3)), h);

            xH = summation(xH, multiplyVS(summation(k1, summation(multiplyVS(k2, 2),
                                                                  summation(
                                                                                multiplyVS(
                                                                                        k3, 2),
                                                                                k4))), 1.0 / 6.0));
            t += h;

        }
        x = xH;
        h /= 2;
        t = 0;

    } while(lenDif(x, xH) > 10e-6);

    showVector(xH);


    return 0;
}