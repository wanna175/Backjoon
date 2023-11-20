#include <iostream>
#include <vector>
#define pii pair<int,int>
using namespace std;
int N, M,cnt=0;
int board[102][102] = { 0 };
bool cheeze(pii pos) {
	int y = pos.first;
	int x = pos.second;
	int ret = 0;
	ret = abs(board[y + 1][x]) + abs(board[y - 1][x]) + abs(board[y][x + 1]) + abs(board[y][x - 1]);
	if (ret < 3)
		return true;
	return false;
}
void in_cheeze(pii pos) {
	int y = pos.first;
	int x = pos.second;
	if (y<1 || x<1 || x>M || y>N)
		return;
	board[y][x] = 0;
	if (board[y + 1][x] == -1)
		in_cheeze({ y + 1,x });
	if (board[y - 1][x] == -1)
		in_cheeze({ y - 1,x });
	if (board[y][x+1] == -1)
		in_cheeze({ y,x+1 });
	if (board[y][x-1] == -1)
		in_cheeze({ y,x-1 });
}
int solve(int t) {
	if (cnt == 0)
		return t;
	int ret;
	vector<pii> v;
	board[1][1] = 0;
	for (int i = 1; i <= N; ++i)
		for (int j = 1; j <= M; ++j)
			if (board[i][j] == 0)
				in_cheeze({i,j});
	for (int i = 2; i < N; ++i)
		for (int j = 2; j < M; ++j)
			if (board[i][j] == 1 && cheeze({ i,j }))
				v.push_back({ i,j });
	for (int i = 0; i < v.size(); ++i)
		board[v[i].first][v[i].second] = 0;
	cnt -= v.size();
	v.clear();
	ret = solve(t + 1);
	return ret;
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M;
	for(int i=1;i<=N;++i)
		for (int j = 1; j <= M; ++j) {
			cin >> board[i][j];
			if (board[i][j] == 1)
				cnt++;
			else
				board[i][j] = -1;
		}
	cout << solve(0);
	return 0;
}