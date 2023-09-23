#include <iostream>

using namespace std;
int IsPairing(int N,int num1,int num2,int round) {
	if ((N == 2)|| (num1 + 1 == num2 && num1 % 2 == 1))
		return round;
	int ret = 0;
	N = (N + 1) / 2;
	num1 = (num1 + 1) / 2;
	num2 = (num2 + 1) / 2;
	ret = IsPairing(N, num1, num2, round + 1);
	return ret;
}

int main(void) {
	int N, kim, lim;
	int answer = -1;
	cin >> N >> kim >> lim;
	cout<<IsPairing(N, min(kim, lim), max(kim, lim), 1);
	return 0;
}