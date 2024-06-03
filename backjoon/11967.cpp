#include<iostream>
#include<queue>

using namespace std;

int N,M;
bool board[102][102];
bool isvisitd[102][102];
int dy[4] = { 1,0,-1,0 };
int dx[4] = { 0,1,0,-1 };
queue<pair<int, int>> sw[101][101];
void BFS() {
	queue<pair<int, int>> Q;
	Q.push({ 1,1 });
	isvisitd[1][1] = true;
	board[1][1] = true;
	while (!Q.empty()) {
		int cy = Q.front().first;
		int cx = Q.front().second;
		Q.pop();
		while (!sw[cy][cx].empty()) {//ºÒÄÑ±â
			int y = sw[cy][cx].front().first;
			int x = sw[cy][cx].front().second;
			board[y][x] = true;
			sw[cy][cx].pop();
			for (int i = 0; i < 4; ++i) {
				if (isvisitd[y + dy[i]][x + dx[i]]) {
					Q.push({ y,x });
					isvisitd[y][x] = true;
					continue;
				}
			}
		}
		for (int i = 0; i < 4; ++i) {
			int ny = cy + dy[i];
			int nx = cx + dx[i];
			if (ny<1 || nx<1 || ny>N || nx>N)continue;
			if (board[ny][nx] && !isvisitd[ny][nx]) {
				Q.push({ ny,nx });
				isvisitd[ny][nx] = true;
			}
		}
	}

}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M;
	for (int i = 0; i < M; ++i) {
		int x, y, a, b;
		cin >> x >> y >> a >> b;
		sw[y][x].push({ b,a });
	}
	BFS();
	int answer = 0;
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j) {
			if (board[i][j]) answer++;
		}
	}
	cout << answer;
	return 0;
}