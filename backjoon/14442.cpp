#include<iostream>
#include<queue>
#include<string>
using namespace std;
struct pos {
	int y;
	int x;
	int k;
};
int N, M, K;
int dy[4] = { 0,1,0,-1 };
int dx[4] = { 1,0,-1,0 };
int board[1000][1000];
int isvisited[11][1000][1000];
int BFS() {
	if (N == 1 && M == 1)
		return 1;
	queue<pos> Q;
	Q.push({ 0,0,0 });
	for (int i = 0; i < 11; ++i) {
		isvisited[i][0][0] = 1;
	}
	while (!Q.empty()) {
		int cy = Q.front().y;
		int cx = Q.front().x;
		int ck = Q.front().k;
		Q.pop();
		for (int i = 0; i < 4; ++i) {
			int ny = cy + dy[i];
			int nx = cx + dx[i];
			int nk = ck;
			if (ny < 0 || nx < 0 || ny >= N || nx >= M) continue;
			if (board[ny][nx] == 1) {
				if (nk >= K)
					continue;
				else
					nk++;
			}
			if (isvisited[nk][ny][nx] > 0) continue;
			isvisited[nk][ny][nx] = isvisited[ck][cy][cx] + 1;
			if (ny == N - 1 && nx == M - 1)
				return isvisited[nk][ny][nx];
			Q.push({ ny,nx,nk });
		}
	}
	return -1;
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M >> K;
	for (int i = 0; i < N; ++i) {
		string s;
		cin >> s;
		for (int j = 0; j < M; ++j) {
			board[i][j] = s[j] - '0';
		}
	}
	int answer = BFS();
	cout << answer;
	return 0;
}