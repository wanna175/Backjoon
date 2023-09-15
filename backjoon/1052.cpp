#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main(void) {
	int N, K;
	int answer = 0;
	int total_cnt = 1;
	vector<bool> binary_N;
	cin >> N >> K;
	//N을 이진수로 바꿔야 한다.
	while (N != 1) {
		if (N % 2 == 1)
			total_cnt++;
		binary_N.push_back(N % 2);
		N = N / 2;
	}
	binary_N.push_back(1);

	if (K >= total_cnt) {
		answer = 0;
	}
	else {
		int cnt = 0;
		int idx = -1;
		for (int i = binary_N.size() - 1; i > 0; i--) {
			if (binary_N[i])
				cnt++;
			if (cnt == K) {
				idx = i - 1;
				break;
			}
		}
		for (int i = 0; i <= idx; i++) {
			if (!binary_N[i])
				answer += (int)pow(2, i);
		}
		answer++;
	}
	cout << answer;
	return 0;
}