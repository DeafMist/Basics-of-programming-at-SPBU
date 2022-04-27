//
// Created by deafmist on 10.05.2021.
//

#include <iostream>
#include <string>
using namespace std;

int main() {
    int paths[4][4] = {
            {0, 3, 5, 6},
            {3, 0, 4, 7},
            {5, 4, 0, 7},
            {6, 7, 7, 0},
    };
    int ways[4] = {5, 3, 4, 4};

    int cur = 0;
    int min = 0;
    string curPath = "";
    string minPath = "";
    for (int i = 0; i < 4; ++i) {
        cur += ways[i];
        curPath += to_string(i + 1);
        for (int j = 0; j < 4; ++j) {
            if (j == i)
                continue;

            cur += paths[i][j];
            curPath += to_string(j + 1);
            for (int k = 0; k < 4; ++k) {
                if ((k == i) or (k == j))
                    continue;

                cur += paths[j][k];
                curPath += to_string(k + 1);
                for (int l = 0; l < 4; ++l) {
                    if ((l == i) or (l == j) or (l == k))
                        continue;

                    cur += paths[k][l] + ways[l];
                    curPath += to_string(l + 1);

                    if ((cur < min) or (min == 0)) {
                        min = cur;
                        minPath = curPath;
                    }

                    cur -= paths[k][l] + ways[l];
                    curPath.erase(curPath.size() - 1);
                }

                cur -= paths[j][k];
                curPath.erase(curPath.size() - 1);
            }

            cur -= paths[i][j];
            curPath.erase(curPath.size() - 1);
        }

        cur -= ways[i];
        curPath.erase(curPath.size() - 1);
    }

    minPath = "0" + minPath + "0";
    cout << "Минимальный путь: " + minPath << '\n'
         << "Расстояние: " << min << " км\n\n";

    cout << "Минимальный путь: ";
    for (int i = minPath.size() - 1; i >= 0; --i) {
        cout << minPath[i];
    }
    cout << '\n'
         << "Расстояние: " << min << " км\n";
}