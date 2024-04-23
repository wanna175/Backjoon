#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>

using namespace std;
int Y, X, K;
bool board[100][100];
int dy[4] = { 1,0,-1,0 };
int dx[4] = { 0,1,0,-1 };
int BFS(int y, int x) {
	int ret = 0;
	queue<pair<int, int>> Q;
	Q.push({ y,x });
	board[y][x] = true;
	while (!Q.empty()) {
		int cy = Q.front().first;
		int cx = Q.front().second;
		Q.pop();
		ret++;
		for (int i = 0; i < 4; ++i) {
			int ny = cy + dy[i];
			int nx = cx + dx[i];
			if (ny < 0 || ny >= Y || nx < 0 || nx >= X) continue;
			if (board[ny][nx]) continue;
			Q.push({ ny,nx });
			board[ny][nx] = true;
		}
	}
	return ret;
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	vector<int> answer;
	cin >> Y >> X >> K;
	for (int k = 0; k < K; ++k) {
		int y1, y2, x1, x2;
		cin >> x1 >> y1 >> x2 >> y2;
		for (int i = y1; i < y2; ++i)
			for (int j = x1; j < x2; ++j)
				board[i][j] = true;
	}
	for (int i = 0; i < Y; ++i) {
		for (int j = 0; j < X; ++j) {
			if (!board[i][j])
				answer.push_back(BFS(i, j));
		}
	}
	sort(answer.begin(), answer.end());
	cout << answer.size() << '\n';
	for (auto v : answer) cout << v << " ";
	return 0;
}