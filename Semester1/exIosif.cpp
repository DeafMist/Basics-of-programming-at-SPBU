#include <iostream> 
#include <cmath>
#include <vector>
using namespace std;

void example2() {
	int n, m;
	cin >> n >> m;
	vector<int> humans(n, 1);
	int last_kill;
	int next_kill = -1;
	int count = 0;
	for (int i = 1; i < n; i++) {
		count = 0;
		while (count < m)  // search for next target
		{
			next_kill = (next_kill + 1) % n;
			if (humans[next_kill] == 1) {
				count++;
			}
		}
		humans[next_kill] = 0;
		last_kill = next_kill;
	}
	for (int i = 0; i < n; i++)
		if (humans[i] == 1) 
			cout << i + 1;
}