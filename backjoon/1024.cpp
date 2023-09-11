#include <iostream>
#include <cmath>

using namespace std;

int main(void) {
	int N, L;
	int cnt, answerL;
	cnt = answerL = -1;
	cin >> N >> L;
	int idx = min(100, N + 1);
	for (int i = L; i <= idx; i++) {
		if ((N - i * (i - 1) / 2) % i == 0) {
			cnt = (N - i * (i - 1) / 2) / i;
			if (cnt < 0)
				break;
			answerL = i;
			break;
		}
	}
	if (answerL == -1) {
		cout << -1;
	}
	else {
		for (int i = 0; i < answerL; i++) {
			cout << i + cnt << ' ';
		}
	}
	return 0;
}