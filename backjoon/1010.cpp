#include <iostream>
#include <vector>

using namespace std;
int main(void) {
	int T;
	vector<long long> answer;
	cin >> T;
	for (int i = 0; i < T; i++) {
		int N, M;
		cin >> N >> M;
		if (N == M) {
			answer.push_back(1);
			continue;
		}

		long long result = 1;
		long long result2 = 1;
		for (int j = 0; j < min(N, M - N); j++) {
			result *= (long long)M - j;
			result2 *= (long long)j + 1;
		}
		answer.push_back(result / result2);
	}
	for (int i = 0; i < T; i++) {
		cout << answer[i] << endl;
	}
	return 0;
}