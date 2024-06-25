#include<iostream>
#include<list>
#include<algorithm>
#define it list<pair<int,int>>::iterator
using namespace std;

int N, M, G, R;
int board[50][50];
bool bfs_board[50][50][2];
bool isvisit[50][50];
int dy[4] = { 1,0,-1,0 };
int dx[4] = { 0,1,0,-1 };
list<pair<int, int>> cult;//배양액 자리
list<pair<int, int>> c;//배양액 뿌린 자리
int answer = 0;
void BFS() {
	int ans = 0;
	fill_n(&isvisit[0][0], 2500, false);
	fill_n(&bfs_board[0][0][0], 5000, false);
	list<pair<int, int>> _list;
	list<pair<int, int>> stack;
	for (auto v : c) {
		_list.push_back({ v.first,v.second });
		bfs_board[v.first][v.second][2 + board[v.first][v.second]] = true;
		isvisit[v.first][v.second] = true;
	}
	while (true) {
		for (it i = _list.begin(); i != _list.end(); ++i) {
			int cy = (*i).first;
			int cx = (*i).second;
			for (int j = 0; j < 4; ++j) {
				int ny = cy + dy[j];
				int nx = cx + dx[j];
				if (ny < 0 || ny >= N || nx < 0 || nx >= M) continue;
				if (board[ny][nx] == 0 || isvisit[ny][nx]) continue;
				stack.push_back({ ny,nx });
				if (bfs_board[cy][cx][0])
					bfs_board[ny][nx][0] = bfs_board[cy][cx][0];
				if (bfs_board[cy][cx][1])
					bfs_board[ny][nx][1] = bfs_board[cy][cx][1];
			}
		}
		_list.clear();
		if (stack.empty()) break;

		while (!stack.empty()) {
			int y = stack.back().first;
			int x = stack.back().second;
			stack.pop_back();
			if (isvisit[y][x]) continue;
			if (bfs_board[y][x][0] && bfs_board[y][x][1]) ans++;
			else _list.push_back({ y,x });
			isvisit[y][x] = true;
		}
	}
	if (ans > answer) answer = ans;
}
void selectCult(it idx, char type, int g, int r) {
	it i = idx;
	++i;//list순환용
	if (type == 'G') {
		if (g <= 0) return;
		g--;
		board[(*idx).first][(*idx).second] = -1;
		c.push_back(*idx);
	}
	else {
		if (r <= 0) return;
		r--;
		board[(*idx).first][(*idx).second] = -2;
		c.push_back(*idx);
	}
	if (g == 0 && r == 0) BFS();
	else {
		for (; i != cult.end(); ++i) {
			selectCult(i, 'G', g, r);
			selectCult(i, 'R', g, r);
		}
	}
	board[(*idx).first][(*idx).second] = 2;
	c.pop_back();
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M >> G >> R;
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < M; ++j) {
			cin >> board[i][j];
			if (board[i][j] == 2)
				cult.push_back({ i,j });
		}
	for (it i = cult.begin(); i != cult.end(); ++i) {
		selectCult(i, 'G', G, R);
		selectCult(i, 'R', G, R);
	}
	cout << answer;
	return 0;
}