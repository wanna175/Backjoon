#include<iostream>
#include<vector>
#define pii pair<int,int>
using namespace std;
int N, M;
int board[51][51] = { 0 };
vector<pii> chicken;
vector<pii> house;
int get_chicken(){
	int ret=0;
	for (int i = 0; i < house.size(); ++i) {
		int tmp = 5000;
		for (int j = 0; j < chicken.size(); ++j) {
			int cy = chicken[j].first;
			int cx = chicken[j].second;
			if (board[cy][cx] == 0) continue;
			int y = house[i].first;
			int x = house[i].second;
			tmp = min(tmp, abs(y - cy) + abs(x - cx));
		}
		ret += tmp;
	}
	return ret;
}
int solve(int toPick,int idx) {
	if (toPick == 0)
		return get_chicken();
	int ret = 5000;
	for (int i = idx; i < chicken.size(); ++i) {
		int y = chicken[i].first;
		int x = chicken[i].second;
		board[y][x] = 0;
		ret = min(ret,solve(toPick - 1, i + 1));
		board[y][x] = 2;
	}
	return ret;
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M;
	for(int i=1;i<=N;++i)
		for (int j = 1; j <= N; ++j) {
			cin >> board[i][j];
			if (board[i][j] == 2)
				chicken.push_back({ i,j });
			else if (board[i][j] == 1)
				house.push_back({ i,j });
		}
	int n = chicken.size() - M;
	cout << solve(n, 0);
	return 0;
}