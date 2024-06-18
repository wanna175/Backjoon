#include<iostream>
using namespace std;
int N, answer = 0;
int S[8], W[8];
void checkEgg() {
	int ret = 0;
	for (int i = 0; i < N; ++i)
		ret += S[i] <= 0 ? 1 : 0;
	if (answer < ret) answer = ret;
}
void breakEgg(int seq, int eggIdx) {
	bool flag = false;
	if (seq == eggIdx) return;
	if (S[eggIdx] <= 0 || S[seq] <= 0) flag = true;
	if (!flag) {
		S[eggIdx] -= W[seq];
		S[seq] -= W[eggIdx];
	}
	if (seq + 1 == N) checkEgg();
	else {
		for (int i = 0; i < N; ++i)
			breakEgg(seq + 1, i);
	}
	if (!flag) {
		S[eggIdx] += W[seq];
		S[seq] += W[eggIdx];
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; ++i)
		cin >> S[i] >> W[i];
	for (int i = 0; i < N; ++i) breakEgg(0, i);
	cout << answer;

	return 0;
}