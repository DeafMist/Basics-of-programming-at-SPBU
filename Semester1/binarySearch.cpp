#include <iostream>
#include <cmath>
#include <vector>
#include <fstream>
using namespace std;

int binarySearch() {
	int n = 20;
	int user_number, index = -1;
	vector<int> numbers(n);
	
	ifstream fin;
	fin.open("C:\\Users\\romap\\CLionProjects\\Moiseev\\input\\binarySearch.txt");
	for (int i = 0; i < n; i++)
		fin >> numbers[i];
	//vector<int> numbers = { 0, 58, -26, -35, 10, 74, 66, 5, -8, -115 };
	//int n = numbers.size();

	int change;
	for (int i = 0; i < n - 1; i++)
		for (int j = n - 2; j >= i; j--)
			if (numbers[j] > numbers[j + 1]) {
				change = numbers[j];
				numbers[j] = numbers[j + 1];
				numbers[j + 1] = change;
			}

	cout << "Our array: ";
	for (int i = 0; i < n; i++)
		cout << numbers[i] << " ";
	cout << '\n';

	cin >> user_number;
	int left = 0, right = n - 1, count = 0;
	while (left <= right) {
		count += 1;
		if (numbers[(right + left) / 2] > user_number)
			right = (right + left) / 2 - 1;
		else if (numbers[(right + left) / 2] < user_number)
			left = (right + left) / 2 + 1;
		else {
			index = (right + left) / 2;
			break;
		}
	}

	if (index != -1) {
		cout << "Your number has index = " << index << '\n';
		cout << "Count of operations = " << count << '\n';
	}
	else
		cout << "Not found" << '\n';
	fin.close();

	return 0;
}