//
// Created by deafmist on 11.03.2021.
//

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

void to866() {
    ifstream fin("C:\\Users\\romap\\CLionProjects\\Moiseev\\input\\beforeEncode1251-866.txt");
    ofstream fout("C:\\Users\\romap\\CLionProjects\\Moiseev\\output\\afterEncode1251-866.txt");
    string s;

    if ((!fin.is_open()) and (!fout.is_open())) {
        cout << "File is not open!\n";
    }
    else {
        while (!fin.eof()) {
            getline(fin, s);
            for (unsigned char i : s) {
                if ((int(i) >= 192) and (int(i) <= 239)) {
                    i = char(int(i) - 64);
                }
                else if ((int(i) >= 240) and (int(i) <= 255)) {
                    i = char(int(i) - 16);
                }
                else if (int(i) == 168) {
                    i = char(240);
                }
                else if (int(i) == 184) {
                    i = char(241);
                }
                fout << i;
            }
            fout << "\n";
        }
        fin.close();
        fout.close();
    }
}

void to1251() {
    ifstream fin("C:\\Users\\romap\\CLionProjects\\Moiseev\\input\\beforeEncode866-1251.txt");
    ofstream fout("C:\\Users\\romap\\CLionProjects\\Moiseev\\output\\afterEncode866-1251.txt");
    string s;

    if ((!fin.is_open()) and (!fout.is_open())) {
        cout << "File is not open!\n";
    }
    else {
        while (!fin.eof()) {
            getline(fin, s);
            for (unsigned char i : s) {
                if ((int(i) >= 128) and (int(i) <= 175)) {
                    i = char(int(i) + 64);
                }
                else if ((int(i) >= 224) and (int(i) <= 239)) {
                    i = char(int(i) + 16);
                }
                else if (int(i) == 240) {
                    i = char(168);
                }
                else if (int(i) == 241) {
                    i = char(184);
                }
                fout << i;
            }
            fout << "\n";
        }
        fin.close();
        fout.close();
    }
}

int main() {
    to1251();
    to866();

    return 0;
}