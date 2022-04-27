//
// Created by deafmist on 10.03.2021.
//

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

string pathInput = "C:\\Users\\romap\\CLionProjects\\Moiseev\\input\\text.txt";
string pathOutput = "C:\\Users\\romap\\CLionProjects\\Moiseev\\output\\txet.txt";

struct list{
    char symb;
    struct list *next;
};

list *create(char data) {
    list *tmp = new list;
    tmp->symb = data;
    tmp->next = NULL;
    return tmp;
}

list *addElem(char data, list *head) {
    list *tmp = create(data);
    tmp->next = head;
    return tmp;
}

list *spisok;

int main(){
    ifstream fin(pathInput);
    ofstream fout(pathOutput);

    string s;

    if (!fin.is_open()) {
        cout << "Input file is not open!\n";
    }
    else {
        while (!fin.eof()) {
            getline(fin, s);
            for (auto i : s) {
                if (spisok == NULL) {
                    spisok = create(i);
                }
                else {
                    spisok = addElem(i, spisok);
                }
            }
            spisok = addElem('\n', spisok);
        }
        spisok = spisok->next;
        fin.close();
    }

    if (!fout.is_open()) {
        cout << "Output file is not open!\n";
    }
    else {
        while (spisok != NULL) {
            fout << spisok->symb;
            spisok = spisok->next;
        }
        fout.close();
    }

    return 0;
}