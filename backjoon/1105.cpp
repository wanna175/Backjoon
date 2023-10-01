#include <iostream>
#include <cmath>
using namespace std;
int PrintEight(int num, int cnt) {
	int cmp = pow(10, cnt);
	num /= cmp;
	int ret = 0;
	while (num >0) {
		if (num % 10 == 8)
			ret++;
		num /= 10;
	}
	return ret;
}
int main(void) {
	int L, R;
	cin >> L >> R;
	int range = R - L;
	int cnt = 0;

	while (range>0) {
		cnt++;
		range /= 10;
	}

	cout << min(PrintEight(L,cnt),PrintEight(R,cnt));
	return 0;
}