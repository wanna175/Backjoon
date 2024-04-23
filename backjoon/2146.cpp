#include<iostream>
#include<queue>
#include<cmath>
#include<algorithm>
using namespace std;
int N;
int board[100][100];
bool isvisited[100][100];
bool isborder[100][100];
int cnt[100][100];
int dy[4] = { 0,1,0,-1 };
int dx[4] = { 1,0,-1,0 };
void BFS(int y, int x, int num) {
	queue<pair<int, int>> Q;
	Q.push({ y,x });
	board[y][x] = num;
	isvisited[y][x] = true;
	while (!Q.empty()) {
		int cy = Q.front().first;
		int cx = Q.front().second;
		Q.pop();
		for (int i = 0; i < 4; ++i) {
			int ny = cy + dy[i];
			int nx = cx + dx[i];
			if (ny < 0 || nx < 0 || ny >= N || nx >= N || isvisited[ny][nx]) continue;
			if (board[ny][nx] == 0) { 
				isborder[cy][cx] = true;
				continue; 
			}
			Q.push({ ny,nx });
			board[ny][nx] = num;
			isvisited[ny][nx] = true;
		}
	}
}
int borderBFS(int y, int x, int num) {
	fill_n(&cnt[0][0], 100 * 100, 0);
	queue<pair<int, int>> Q;
	Q.push({ y,x });
	while (!Q.empty()) {
		int cy = Q.front().first;
		int cx = Q.front().second;
		Q.pop();
		for (int i = 0; i < 4; ++i) {
			int ny = cy + dy[i];
			int nx = cx + dx[i];
			if (ny < 0 || nx < 0 || ny >= N || nx >= N || board[ny][nx] == num) continue;
			if (cnt[ny][nx] > 0) continue;
			if (isborder[ny][nx]) {
				return cnt[cy][cx];
			}
			Q.push({ ny,nx });
			cnt[ny][nx] = cnt[cy][cx] + 1;
		}
	}
	return -1;
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> board[i][j];
		}
	}//입력
	int num = 1;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			if (board[i][j] > 0 && !isvisited[i][j]) {
				BFS(i, j, num++);
			}
		}
	}//경계선 찾기, num으로 대륙 구분
	int answer = 201;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			if (isborder[i][j]) {
				int tmp = borderBFS(i, j, board[i][j]);
				if(tmp!=-1)
					answer = min(answer, tmp);
			}
		}
	}
	cout << answer;
	return 0;
}