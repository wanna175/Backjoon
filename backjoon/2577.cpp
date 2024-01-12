#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int A, B, C, result;
	int num[10];
	fill(num, num + 10, 0);
	cin >> A >> B >> C;
	result = A * B * C;
	while (result!=0) {
		num[result % 10]++;
		result /= 10;
	}
	for (int r : num)
		cout << r<<'\n';
	return 0;
}