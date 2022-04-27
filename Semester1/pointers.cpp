//
// Created by deafmist on 03.12.2020.
//

#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

int pointers() {
    ifstream fin("C:\\Users\\romap\\CLionProjects\\Moiseev\\input\\pointers.txt");
    if (!fin.is_open())
        cout << "File is not open to read!" << "\n";
    else {
        int n = 0;
        string n_str;
        getline(fin, n_str);
        stringstream ss(n_str);
        while (getline(ss, n_str, ' '))
            n++;

        fin.seekg(0);

        double **a;
        a = new double *[n];
        for (int i = 0; i < n; ++i) {
            a[i] = new double[n];
        }

        string line, word;
        for (size_t cur_line = 0; getline(fin, line); cur_line++) {
            stringstream ss(line);
            int cur_elem = 0;
            while (getline(ss, word, ' '))
                a[cur_line][cur_elem++] = stod(word);
        }

        double min = a[0][0], max = a[0][0];
        int i_min = 0, i_max = 0;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                if (a[i][j] < min) {
                    min = a[i][j];
                    i_min = j;
                }
                else if (a[i][j] > max) {
                    max = a[i][j];
                    i_max = i;
                }

        double change;
        int i_cur = 0, j_cur = 0;
        for (int i = 0; i < n - 1; ++i) {
            if (j_cur == i_min)
                j_cur++;
            if (i_cur == i_max)
                i_cur++;
            change = a[i_max][j_cur];
            a[i_max][j_cur] = a[i_cur][i_min];
            a[i_cur][i_min] = change;
            i_cur++;
            j_cur++;
        }

        ofstream fout("C:\\Users\\romap\\CLionProjects\\Moiseev\\output\\pointers.txt");
        if (!fout.is_open())
            cout << "File is not open to write!" << '\n';
        else {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j)
                    fout << a[i][j] << ' ';
                fout << '\n';
            }
        }

        fout.close();

        for (int i = 0; i < n; ++i)
            delete[] a[i];
        delete[] a;
    }

    fin.close();

    return 0;
}