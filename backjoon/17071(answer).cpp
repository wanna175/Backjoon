#include<iostream>
#include<queue>
#define MAX 500001
using namespace std;
bool board[2][MAX];//Â¦¼öÃÊ È¦¼öÃÊ ±â·Ï
int N, K;
int dx[3] = { 1,-1,0 };
int BFS() {
	int bt = 0;
	queue<pair<int,int>> Q;
	Q.push({N,0});
	board[0][N] = true;
	while (!Q.empty()) {
		int cur = Q.front().first;
		int nt = Q.front().second+1;
		if (bt != nt) {
			bt = nt;
			K += bt;
			if (K >= MAX) break;
		}
		Q.pop();
		for (int i = 0; i < 3; ++i) {
			int next = cur + dx[i];
			if (i == 2) next *= 2;
			if (next < 0 || next >= MAX || board[nt % 2][next]) continue;
			board[nt % 2][next] = true;
			if (board[bt % 2][K]) return bt;
			Q.push({ next,nt });
		}
	}
	return -1;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> K;
	if (N == K) {
		cout << 0;
		return 0;
	}
	cout << BFS();
	return 0;
}