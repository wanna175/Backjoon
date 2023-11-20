#include <iostream>
#include <queue>
#include <vector>
#define pii pair<int,int>
using namespace std;
vector<vector<int>> board(8,vector<int>(8,0));
int N, M;
vector<pii> virus;
int bfs_push(int y,int x,queue<pii>& q, vector<vector<int>>& board) {
	if (y < 0 || x < 0 || y >= N || x >= M || board[y][x] != 0)
		return 0;
	q.push({ y,x });
	board[y][x] = 2;
	return 1;
}
int BFS(vector<vector<int>> board,int cnt) {
	queue<pii> q;
	for (int i = 0; i < virus.size(); ++i)
		q.push(virus[i]);
	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		cnt-=bfs_push(y+1, x, q, board);
		cnt-=bfs_push(y-1, x, q, board);
		cnt-=bfs_push(y, x+1, q, board);
		cnt-=bfs_push(y, x-1, q, board);
	}
	return cnt;
}
int solve(int num,vector<pii>& zero,int cnt,int idx) {
	if (num == 3)
		return BFS(board, cnt);
	int ret=-1;
	for (int i = idx; i < zero.size(); ++i) {
		int y = zero[i].first;
		int x = zero[i].second;
		board[y][x] = 1;
		ret = max(ret, solve(num + 1, zero, cnt - 1,i+1));
		board[y][x] = 0;
	}
	return ret;
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M;
	vector<pii> zero;
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < M; ++j) {
			cin >> board[i][j];
			if (board[i][j] == 2)
				virus.push_back({ i,j });
			else if (board[i][j] == 0) {
				zero.push_back({ i,j });
			}
		}
	cout << solve(0, zero, zero.size(), 0);
	return 0;
}