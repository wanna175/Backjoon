#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	int N;
	cin >> N;
	vector<int> A, B;
	int answer = 0;
	for (int i = 0; i < N; i++) {
		int temp;
		cin >> temp;
		A.push_back(temp);
		sort(A.begin(), A.end());
	}
	for (int i = 0; i < N; i++) {
		int temp;
		cin >> temp;
		B.push_back(temp);
		sort(B.rbegin(), B.rend());
	}
	for (int i = 0; i < N; i++) {
		answer += A[i] * B[i];
	}
	cout << answer;
	return 0;
}