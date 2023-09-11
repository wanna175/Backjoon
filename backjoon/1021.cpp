#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main(void) {
	int N, M;
	cin >> N >> M;
	vector<int> Idx;
	int current_idx = 1;
	int current_size = N;

	int answer = 0;

	for (int i = 0; i < M; i++) {
		int tmp;
		cin >> tmp;
		Idx.push_back(tmp);
	}//입력값 다 받음

	for (int i = 0; i < M; i++) {
		int target = Idx[i];
		for (int j = 0; j < i; j++) {
			if (Idx[j] < Idx[i])
				target--;
		}
		int cmp1, cmp2;
		if (current_idx <= target)
			cmp1 = target - current_idx;
		else if (current_idx > target)
			cmp1 = current_idx - target;
		cmp2 = current_size - cmp1;
		answer += min(cmp1, cmp2);

		current_size--;
		current_idx = target;
		if (current_size < target)
			current_idx = 1;
	}
	cout << answer;
	return 0;
}