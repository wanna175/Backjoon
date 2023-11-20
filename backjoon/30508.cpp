#include <iostream>
#include <vector>
#include <queue>
#define pii pair<int,int>
using namespace std;
int N, M,K,h,w;
int arr[1001][1001] = { 0 };
int board[1001][1001] = { 0 };
queue<pii> q;
void bfs_push(int y,int x,int cur_h) {
	if (y<1 || x<1 || y>N || x>M || cur_h > arr[y][x]
		||board[y][x]==1)
		return;
	q.push({ y,x });
	board[y][x] = 1;
}
void BFS() {
	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		bfs_push(y + 1, x, arr[y][x]);
		bfs_push(y - 1, x, arr[y][x]);
		bfs_push(y, x+1, arr[y][x]);
		bfs_push(y, x-1, arr[y][x]);
	}

}
int solve() {
	int ret = 0;
	for(int i=1;i<=N;++i)
		for (int j = 1; j <= M; ++j)
			board[i][j] += board[i][j - 1] + board[i - 1][j] - board[i - 1][j - 1];
	
	for (int i = h; i <= N; ++i)
		for (int j = w; j <= M; ++j)
			if (board[i][j] - board[i - h][j] - board[i][j - w] + board[i - h][j - w] == h * w)
				++ret;
	return ret;
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M >> h >> w;
	for (int i = 1; i <= N; ++i)
		for (int j = 1; j <= M; ++j)
			cin >> arr[i][j];
	cin >> K;
	for (int i = 0; i < K; ++i) {
		int r, c;
		cin >> r >> c;
		q.push({ r,c });
		board[r][c] = 1;
	}
	BFS();
	cout << solve();
	return 0;
}