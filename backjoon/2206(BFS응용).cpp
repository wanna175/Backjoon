#include <iostream>
#include <queue>
#include <string>
#define pii pair<int,int>
using namespace std;
int N, M;
int board[1001][1001] = { 0 };
int cache[1001][1001][2] = {0};
queue<vector<int>> q;
int Push(pii pos, pii prev, int wall) {
	if (pos.first<1 || pos.second<1 || pos.first>N || pos.second>M)
		return 0;
	int pre = cache[prev.first][prev.second][wall];
	if (board[pos.first][pos.second] != 0) {
		if (wall == 0)
			wall = 1;
		else
			return 0;
	}

	if (cache[pos.first][pos.second][wall] != 0)
		return 0;
	q.push({pos.first, pos.second, wall});
	cache[pos.first][pos.second][wall] = pre + 1;
	if (pos.first == N && pos.second == M)
		return cache[pos.first][pos.second][wall]+1;
	return 0;
}
int BFS() {
	q.push({ 1,1,0 });
	cache[1][1][0] = 1;
	int ret = -1;
	if (N == 1 && M == 1)
		return 1;
	while (!q.empty()&&ret==-1) {
		int y = q.front()[0];
		int x = q.front()[1];
		int wall = q.front()[2];
		ret+=Push({ y + 1,x }, { y,x }, wall);
		ret+=Push({ y - 1,x }, { y,x }, wall);
		ret+=Push({ y,x + 1 }, { y,x }, wall);
		ret+=Push({ y,x - 1 }, { y,x }, wall);
		q.pop();
	}
	return ret;
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M;
	vector<pii> wall;
	string tmp;
	for (int i = 1; i <= N; ++i) {
		cin >> tmp;
		for (int j = 1; j <= M; ++j) {
			if (tmp[j - 1] == '1')
				wall.push_back({ i,j });
			board[i][j] = tmp[j - 1] - '0';
		}
	}
	int distance = BFS();
	cout << distance;
	return 0;
}