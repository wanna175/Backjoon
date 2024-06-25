#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int N, M;
int board[8][8];
vector<pair<int, int>> cctv;
int cctvDir[6] = { 0,4,2,4,4,1 };
int answer = 65;
void setRight(int y, int x, int set) {
	for (int i = x + 1; i < M; ++i) {
		if (board[y][i] == 6) break;
		if (board[y][i]>0) continue;
		board[y][i] += set;
	}
}
void setLeft(int y, int x, int set) {
	for (int i = x - 1; i >= 0; --i) {
		if (board[y][i] == 6) break;
		if (board[y][i]>0) continue;
		board[y][i] += set;
	}
}
void setUp(int y, int x, int set) {
	for (int i = y - 1; i >= 0; --i) {
		if (board[i][x] == 6) break;
		if (board[i][x]>0) continue;
		board[i][x] += set;
	}
}
void setDown(int y, int x, int set) {
	for (int i = y + 1; i < N; ++i) {
		if (board[i][x] == 6) break;
		if (board[i][x]>0) continue;
		board[i][x] += set;
	}
}
void setCCTV(int y, int x, int dir,int set) {
	switch (board[y][x])
	{
	case 1:
		if (dir == 1) {
			setRight(y, x, set);
		}
		else if (dir == 2) {
			setDown(y, x, set);
		}
		else if (dir == 3) {
			setLeft(y, x, set);
		}
		else if (dir == 4) {
			setUp(y, x, set);
		}
		break;
	case 2:
		if (dir == 1) {
			setRight(y, x, set);
			setLeft(y, x, set);
		}
		else if (dir == 2) {
			setDown(y, x, set);
			setUp(y, x, set);
		}
		break;
	case 3:
		if (dir == 1) {
			setRight(y, x, set);
			setUp(y, x, set);
		}
		else if (dir == 2) {
			setDown(y, x, set);
			setRight(y, x, set);
		}
		else if (dir == 3) {
			setLeft(y, x, set);
			setDown(y, x, set);
		}
		else if (dir == 4) {
			setLeft(y, x, set);
			setUp(y, x, set);
		}
		break;
	case 4:
		if (dir == 1) {
			setRight(y, x, set);
			setUp(y, x, set);
			setLeft(y, x, set);
		}
		else if (dir == 2) {
			setDown(y, x, set);
			setRight(y, x, set);
			setUp(y, x, set);
		}
		else if (dir == 3) {
			setLeft(y, x, set);
			setDown(y, x, set);
			setRight(y, x, set);
		}
		else if (dir == 4) {
			setUp(y, x, set);
			setLeft(y, x, set);
			setDown(y, x, set);
		}
		break;
	case 5:
		setUp(y, x, set);
		setLeft(y, x, set);
		setDown(y, x, set);
		setRight(y, x, set);
		break;
	}
}
void calBlindSpot() {
	int ans = 0;
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < M; ++j)
			if (board[i][j] == 0)
				ans++;
	if (answer > ans) answer = ans;
	
}
void backtracking(int dir) {
	int cy = cctv.back().first;
	int cx = cctv.back().second;
	cctv.pop_back();
	setCCTV(cy, cx, dir, -1);
	if (cctv.empty()) calBlindSpot();
	else {
		int ny = cctv.back().first;
		int nx = cctv.back().second;
		int cc = board[ny][nx];
		for (int i = 1; i < cctvDir[cc] + 1; ++i)
			backtracking(i);
	}
	setCCTV(cy, cx, dir, 1);
	cctv.push_back({ cy,cx });
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M;

	for (int i = 0; i < N; ++i)
		for (int j = 0; j < M; ++j) {
			cin >> board[i][j];
			if (board[i][j] > 0 && board[i][j] < 6)
				cctv.push_back({ i,j });
		}
	if (cctv.empty()) {
		calBlindSpot();
		cout << answer;
		return 0;
	}
	int ny = cctv.back().first;
	int nx = cctv.back().second;
	int cc = board[ny][nx];
	for (int i = 1; i < cctvDir[cc]+1; ++i)
		backtracking(i);
	cout << answer;
	return 0;
}