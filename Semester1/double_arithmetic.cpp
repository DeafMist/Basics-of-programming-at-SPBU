//
// Created by deafmist on 03.12.2020.
//

#include <iostream>
#include <string>
using namespace std;

string toBinary(double x) {
    string s = "00.";

    for (int i = 0; i < 9; i++) {
        x *= 2.0;
        if (x >= 1) {
            s += "1";
            x -= 1;
        }
        else
            s += "0";
    }

    return s;
}

string summation(string s1, string s2) {
    char prev, cur;
    string s3 = "00.00000000";
    prev = '0';

    for (int i = 10; i >= 0; i--) {
        if (i == 2)
            continue;

        if (s1[i] == '0') {
            if (s2[i] == '0')
                s3[i] = '0';
            else 
                s3[i] = '1';
        }
        else {
            if (s2[i] == '0') 
                s3[i] = '1';
            else {
                s3[i] = '0';
                cur = '1';
            }
        }

        if (prev == '1') {
            if (s3[i] == '0')
                s3[i] = '1';
            else {
                s3[i] = '0';
                cur = '1';
            }
        }

        prev = cur;
        cur = '0';
    }

    return s3;
}

string reverse(string s1) {
    string reverse_string = "00.00000000";

    for (int i = 0; i < 11; i++) {
        if (i == 2)
            continue;
        if (s1[i] == '0')
            reverse_string[i] = '1';
        else
            reverse_string[i] = '0';
    }

    return reverse_string;
}

int double_arithmetic() {
    double a, b;
    string s1, s2, s3, s4 = "00.00000001";
    cin >> a;
    cin >> b;

    double tmp;
    if (a < 0) {
        tmp = a;
        a = b;
        b = tmp;
    }

    s1 = toBinary(a);
    if (b > 0)
        s2 = toBinary(b);
    else {
        b = -b;
        s2 = toBinary(b);
        s2 = reverse(s2);
        s2 = summation(s2, s4);
    }

    s3 = summation(s1,s2);
    cout << s3 << '\n';

    return 0;
}