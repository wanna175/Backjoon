#include<iostream>
#include<queue>
#include<stack>
#define MAX 100001
using namespace std;
int N, K;
int board[MAX];
int cnt[MAX];
int dx[3] = { -1,1,0 };
int BFS() {
	queue<int> Q;
	board[N] = -1;
	cnt[N] = 1;
	if (N == K)
		return 0;
	Q.push(N);
	while (!Q.empty()) {
		int cur = Q.front();
		Q.pop();
		for (int i = 0; i < 3; ++i) {
			int next = cur + dx[i];
			if (i == 2) next *= 2;
			if (next < 0 || next >= MAX) continue;
			if (cnt[next] != 0) continue;
			board[next] = cur;
			cnt[next] = cnt[cur] + 1;
			if (next == K)
				return cnt[cur];
			Q.push(next);
		}
	}
	return -1;
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> K;
	/*if (K < N) {
		cout << N - K << '\n';
		while (N != K-1) {
			cout << N << " ";
			N--;
		}
		return 0;
	}*/
	int time = BFS();
	int i = K;
	stack<int> S;
	S.push(K);
	while (board[i]!=-1) {
		S.push(board[i]);
		i = board[i];
	}

	cout << time << '\n';
	while (!S.empty()) {
		cout << S.top() << " ";
		S.pop();
	}
	return 0;
}