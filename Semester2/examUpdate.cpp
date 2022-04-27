//
// Created by deafmist on 11.12.2020.
//

#include <iostream>
#include <cmath>
#include <string>
#include <fstream>
using namespace std;

string path = "C:\\Users\\romap\\CLionProjects\\Moiseev\\input\\list.txt";

struct Human {
    int number;
    string fio;
    int year;
    string phone;
};

typedef struct Node {
    Human value;
    struct Node *next;
    struck Node *prev;
} Spisok;

Spisok *spisok;

Spisok *create(Human data) {
    Spisok *tmp = new Spisok;
    tmp -> value = data;
    tmp -> next = NULL;
    return tmp;
}

Spisok *add_element_start(Human data, Spisok *head) {
    Spisok *tmp = create(data);
    tmp -> next = head;
    return tmp;
}

void add_element_end(Human data, Spisok *head) {
    Spisok *tmp = create(data);
    Spisok *p = head;
    while (p -> next != NULL)
        p = p -> next;
    p -> next = tmp;
}

void print(Spisok *head) {
    while (head != NULL) {
        cout << head -> value.number << ' '
             << head -> value.fio << ' '
             << head -> value.year << ' '
             << head -> value.phone << '\n';
        head = head -> next;
    }
}

Spisok *remove_element(int number, Spisok *head) {
    Spisok *tmp = head, *p = NULL;
    if (head == NULL)
        return NULL;
    while (tmp && tmp -> value.number != number) {
        p = tmp;
        tmp = tmp -> next;
    }
    if (tmp == head) {
        delete head;
        return tmp -> next;
    }
    if (!tmp)
        return head;
    p -> next = tmp -> next;
    delete tmp;
    return head;
}

Spisok *remove_all(Spisok *head)
{
    while (head != NULL) {
        Spisok *p = head;
        head = head -> next;
        delete p;
    }
    return NULL;
}

void menu() {
    cout << "1. Load\n"
         << "2. Save\n"
         << "3. Edit\n"
         << "4. Add\n"
         << "5. Delete\n"
         << "6. Find\n"
         << "7. Exit\n"
         << '\n';
}

ifstream fin(path);

void add() {
    cout << "Enter new person.\n";
    Human human = {};
    cin >> human.number;

    string word, word2;
    cin >> word >> word2;
    word += ' ' + word2;
    human.fio = word;
    cin >> human.year >> human.phone;

    if (spisok == NULL) {
        spisok = create(human);
        return;
    }
    else {
        Spisok *tmp = spisok;
        while (tmp != NULL) {
            if (human.number == tmp->value.number) {
                cout << "This id is already used.\n\n";
                return;
            }
            tmp = tmp->next;
        }
    }

    add_element_end(human, spisok);
}

void load() {
    if (!fin.is_open())
        cout << "Input file is not open!\n";
    else {
        string word, word2;
        Human human = {};

        while (!fin.eof()) {
            fin >> human.number >> word >> word2;
            word += ' ' + word2;
            human.fio = word;
            fin >> human.year >> human.phone;
            if (human.phone == "") {
                cout << "File is empty. Please add a new person.\n";
                return add();
            }
            if (spisok == NULL)
                spisok = create(human);
            else
                add_element_end(human, spisok);
        }

        print(spisok);
        cout << '\n';
    }
}

void save() {
    ofstream fout(path);
    if (!fout.is_open()) {
        cout << "Output file is not open!\n";
    }
    else {
        Spisok *tmp = spisok;
        while (tmp != NULL) {
            if (tmp -> next != NULL) {
                fout << tmp->value.number << ' '
                     << tmp->value.fio << ' '
                     << tmp->value.year << ' '
                     << tmp->value.phone << '\n';
            }
            else {
                fout << tmp->value.number << ' '
                     << tmp->value.fio << ' '
                     << tmp->value.year << ' '
                     << tmp->value.phone;
            }
            tmp = tmp -> next;
        }
    }
    fout.close();
}

void editElem() {
    int id, input_index;
    string word, word2;
    Spisok *tmp = spisok;
    cout << "Enter the id of element which you want to edit.\n";
    cin >> id;

    while (tmp != NULL) {
        if (tmp -> value.number == id) {
            cout << "What do you want to change?\n"
                 << "1. FIO.\n"
                 << "2. Year.\n"
                 << "3. Phone number.\n\n";
            cin >> input_index;
            switch(input_index){
                case 1:
                    cout << "Enter FIO.\n";
                    cin >> word >> word2;
                    word += ' ' + word2;
                    tmp -> value.fio = word;
                    print(spisok);
                    return;
                case 2:
                    cout << "Enter the year.\n";
                    cin >> tmp -> value.year;
                    print(spisok);
                    return;
                case 3:
                    cout << "Enter the phone number.\n";
                    cin >> tmp -> value.phone;
                    print(spisok);
                    return;
            }
        }
        else {
            tmp = tmp -> next;
        }
    }

    if (tmp == NULL)
        cout << "Element is not found.\n";
}

void deleteElem() {
    cout << "Enter the person's id which you want to delete.\n";
    int id;
    cin >> id;
    spisok = remove_element(id, spisok);
}

void findElem() {
    cout << "Enter the first symbol of person's surname which you want to find.\n";
    char a;
    cin >> a;
    a = tolower(a);
    Spisok *tmp = spisok;

    bool is_found = false;
    while (tmp != NULL) {
        if (tolower(tmp -> value.fio[0]) == a) {
            cout << tmp->value.number << ' '
                 << tmp->value.fio << ' '
                 << tmp->value.year << ' '
                 << tmp->value.phone << '\n';
            is_found = true;
        }
        tmp = tmp -> next;
    }
    if (!is_found)
        cout << "Nothing found.";
    cout << '\n';
}

void byebye() {
    spisok = remove_all(spisok);
}

int main() {
    int input_number = 0;

    while (input_number != 7) {
        menu();
        cin >> input_number;
        switch (input_number) {
            case 1:
                load();
                break;
            case 2:
                if (spisok != NULL)
                    save();
                else
                    cout << "Firstly, load the file!\n";
                break;
            case 3:
                if (spisok != NULL)
                    editElem();
                else
                    cout << "Firstly, load the file!\n";
                break;
            case 4:
                if (spisok != NULL)
                    add();
                else
                    cout << "Firstly, load the file!\n";
                break;
            case 5:
                if (spisok != NULL)
                    deleteElem();
                else
                    cout << "Firstly, load the file!\n";
                break;
            case 6:
                if (spisok != NULL)
                    findElem();
                else
                    cout << "Firstly, load the file!\n";
                break;
            case 7:
                byebye();
                break;
        }
    }

    return 0;
}
