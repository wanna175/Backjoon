#include<iostream>
#include<queue>
#include<string>
using namespace std;
struct pos {
	int y;
	int x;
	int k;
	bool day;//¹ã³·±â·Ï
	bool stay;
};
int N, M, K;
int dy[5] = { 0,1,0,-1 };
int dx[5] = { 1,0,-1,0 };
int board[1000][1000];
int isvisited[2][11][1000][1000];
int BFS() {
	if (N == 1 && M == 1)
		return 1;
	queue<pos> Q;
	Q.push({ 0,0,0,true,false });
	for (int i = 0; i < 11; ++i) {
		isvisited[0][i][0][0] = 1;
		isvisited[1][i][0][0] = 1;
	}
	while (!Q.empty()) {
		int cy = Q.front().y;
		int cx = Q.front().x;
		int ck = Q.front().k;
		bool day = Q.front().day;
		bool stay = Q.front().stay;
		Q.pop();
		if (!stay) {
			isvisited[1][ck][cy][cx] = isvisited[0][ck][cy][cx]+1;
			Q.push({ cy,cx,ck,!day,true });
		}
		for (int i = 0; i < 4; ++i) {
			int ny = cy + dy[i];
			int nx = cx + dx[i];
			int nk = ck;
			if (ny < 0 || nx < 0 || ny >= N || nx >= M) continue;
			if (board[ny][nx] == 1) {
				if (nk >= K||!day)
					continue;
				else
					nk++;
			}
			if (isvisited[0][nk][ny][nx] > 0) continue;
			isvisited[0][nk][ny][nx] = isvisited[(stay)?1:0][ck][cy][cx] + 1;
			if (ny == N - 1 && nx == M - 1)
				return isvisited[0][nk][ny][nx];
			Q.push({ ny,nx,nk,!day,false });
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