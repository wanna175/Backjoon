#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main(void) {
	int T;
	cin >> T;
	vector<int> answer(T,0);
	for (int i = 0; i < T; ++i) {
		int x, y, range;
		cin >> x >> y;
		range = y - x;
		x = sqrt(range);
		y = pow(x,2);
		answer[i] = 2 * x - 1;
		if (y + x < range)
			answer[i] += 2;
		else if (y + x >= range && range > y)
			answer[i] += 1;
	}
	for (int i = 0; i < T; ++i)
		cout << answer[i] << endl;
	return 0;
}
