#include<iostream>

using namespace std;

int main(void) {
	long long X, Y,Z;
	cin >> X >> Y;
	Z = Y*100 / X;
	long double answer = -1;
	if (Z==100||Z==99) {
		cout << -1;
		return 0;
	}
	answer = (long double)(X * (Z + 1) - 100 * Y) / (99 - Z);
	if ((int)answer != answer)
		answer++;
	cout << (int)answer;
	return 0;
}