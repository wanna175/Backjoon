#include<iostream>
#include<queue>

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int N, idx = 0;
	cin >> N;
	queue<int> Q;
	for (int i = 0; i < N; ++i) Q.push(i + 1);
	while (Q.size() > 1) {
		if (idx % 2 != 0) {
			int front = Q.front();
			Q.push(front);
		}
		Q.pop();
		idx++;
	}
	cout << Q.front();
	return 0;
}