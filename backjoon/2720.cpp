#include <iostream>
#include <cmath>
#include <vector>

using namespace std;
int main(void) {
	int T;
	vector<int> _change;

	cin >> T;
	for (int i = 0; i < T; i++) {
		int temp;
		cin >> temp;
		_change.push_back(temp);
	}

	for (int i = 0; i < T; i++) {
		cout << _change[i] / 25<<" ";
		_change[i] %= 25;
		cout << _change[i] / 10 << " ";
		_change[i] %= 10;
		cout << _change[i] / 5 << " ";
		_change[i] %= 5;
		cout << _change[i] << endl;
	}

	return 0;
}