#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
bool cmp(pair<int, int> a, pair<int, int> b) {
	if (a.first == b.first) {
		return a.second < b.second;
	}
	return a.first < b.first;
}
int main(void) {
	int N;
	vector<pair<int, int>> answer;
	int* P;
	cin >> N;
	P = new int[N] {0};
	for (int i = 0; i < N; i++) {
		int n;
		cin >> n;
		answer.push_back(make_pair(n, i));
		sort(answer.begin(), answer.end(), cmp);
	}
	for (int i = 0; i < N; i++) {
		P[answer[i].second] = i;
	}
	for (int i = 0; i < N; i++) {
		cout << P[i] << ' ';
	}
	delete[] P;
	return 0;
}