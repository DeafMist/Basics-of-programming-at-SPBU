//
// Created by deafmist on 02.12.2020.
//

#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

void printArray(double a[4][5]) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 5; j++) {
            printf("%5.2f  ", a[i][j]);
        }
        cout << '\n';
    }
    cout << '\n';
}

void read_from_file(double a[4][5]) {
    ifstream fin("C:\\Users\\romap\\CLionProjects\\Moiseev\\input\\methodGaussa.txt");
    if (!fin.is_open())
        cout << "Parse error! File is not open!" << "\n";
    else {
        string line, word;
        for (size_t cur_line = 0; getline(fin, line); cur_line++) {
            stringstream ss(line);
            int cur_elem = 0;
            while (getline(ss, word, ' '))
                a[cur_line][cur_elem++] = stod(word);
        }
    }
    fin.close();
}

int methodGaussa(){
    double a[4][5];

    read_from_file(a);

    printArray(a);

    for (int i = 0; i < 4; i++) { // current line
        for (int j = 4; j >= 0; j--) // normalization
            a[i][j] /= a[i][i];
        for (int j = i+1; j < 4; j++) // next lines
            for (int k = 4; k >= i; k--) // elems
                a[j][k] -= a[i][k] * a[j][i];
    }

    //printArray(a);

    for (int i = 3; i > 0; i--)  // current line
        for (int j = i - 1; j >= 0; j--)  // upper
            for (int k = 4; k >= i; k--)
                a[j][k] -= a[i][k] * a[j][i];

    //printArray(a);

    for (int i = 0; i < 4; i++) {
        printf("x%d = %5.2f\n", i + 1, a[i][4]);
    }

    return 0;
}