//
// Created by deafmist on 05.12.2020.
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<string> toBinary(int a) {
    int b = a / 10, c = a % 10;
    string l, m;
    
    for (int i = 0; i < 4; i++) {
        l = to_string(b % 2) + l;
        m = to_string(c % 2) + m;
        b /= 2;
        c /= 2;
    }

    return vector<string>{l, m};
}

vector<string> summation(string s1, string s2) {
    string prev, cur, s3 = "0000";
    prev = '0';
    
    for (int i = 3; i >= 0; i--) {
        prev = cur;
        cur = '0';
        
        if (s1[i] == '0') {
            if (s2[i] == '0')
                s3[i] = '0';
            else {
                s3[i] = '1';
                cur = '0';
            }
        }
        else {
            if (s2[i] == '0') {
                s3[i] = '1';
                cur = '0';
            }
            else {
                s3[i] = '0';
                cur = '1';
            }
        }
        
        if (prev == "1") {
            if (s3[i] == '0')
                s3[i] = '1';
            else {
                s3[i] = '0';
                cur = '1';
            }
        }
    }
    
    return vector<string>{s3, cur};
}

int binary_arithmetic() {
    int a, b;
    cin >> a;
    cin >> b;

    string s1, s2, s3, s4, cur1, cur2, c6 = "0110", c10 = "1010", c1 = "0001";
    vector<string> vec1, vec2, vec3, vec4;

    vec1 = toBinary(a);
    s1 = vec1[0];
    s2 = vec1[1];

    if (b > 0) {
        vec2 = toBinary(b);
        s3 = vec2[0];
        s4 = vec2[1];
    }
    else {
        b += 100;
        vec2 = toBinary(b);
        s3 = vec2[0];
        s4 = vec2[1];
    }

    vec1 = summation(s1, c6);
    s1 = vec1[0];
    vec2 = summation(s2, c6);
    s2 = vec2[0];
    vec4 = summation(s2, s4);
    s2 = vec4[0];
    cur2 = vec4[1];

    if (cur2 == "0") {
        vec4 = summation(s2, c10);
        s2 = vec4[0];
    }
    if (cur2 == "1") {
        vec3 = summation(s1, c1);
        s1 = vec3[0];
    }

    vec3 = summation(s1, s3);
    s1 = vec3[0];
    cur1 = vec3[1];

    if (cur1 == "0") {
        vec3 = summation(s1, c10);
        s1 = vec3[0];
    }

    cout << s1 << ' ' << s2 << '\n';

    return 0;
}

