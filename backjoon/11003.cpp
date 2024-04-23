#include<iostream>
#include<vector>
#include<deque>
using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int N, L;
	cin >> N >> L;
	deque<int> D,arr;
	vector<int> answer;
	for (int i = 1; i <= N; ++i) {
		int A;
		cin >> A;
		if (i > L) {
			if (D.front() == arr.front())
				D.pop_front();
			arr.pop_front();
		}
		while (!D.empty() && D.back() > A) D.pop_back();
		D.push_back(A);
		arr.push_back(A);
		answer.push_back(D.front());
	}
	for (int v : answer) cout << v << ' ';
	return 0;
}