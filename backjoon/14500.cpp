#include <iostream>
#include <vector>
using namespace std;
int N, M;
int board[502][502] = { 0 };
int path[502][502] = { 0 };
int solve(int y,int x,int toPick,int cur) {
	if (y<1 || x<1 || y>N || x>M||path[y][x]!=0)
		return -1;
	cur += board[y][x];
	if (toPick == 1)
		return cur;
	
	path[y][x] = 1;
	int ret = solve(y + 1, x, toPick - 1, cur);
	ret = max(ret, solve(y - 1, x, toPick - 1, cur));
	ret = max(ret, solve(y, x+1, toPick - 1, cur));
	ret = max(ret, solve(y, x-1, toPick - 1, cur));
	path[y][x] = 0;
	return ret;
}
int solve2(int y, int x) {
	int ret = board[y + 1][x] + board[y - 1][x] + board[y][x + 1];
	ret =max(ret, board[y + 1][x] + board[y - 1][x] + board[y][x - 1]);
	ret = max(ret, board[y + 1][x] + board[y][x + 1] + board[y][x - 1]);
	ret = max(ret, board[y - 1][x] + board[y][x + 1] + board[y][x - 1]);
	
	return ret + board[y][x];
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	for (int i = 1; i <= N; ++i)
		for (int j = 1; j <= M; ++j)
			cin >> board[i][j];
	int answer = -1;
	for (int i = 1; i <= N; ++i)
		for (int j = 1; j <= M; ++j) {
			answer = max(answer,max(solve(i, j, 4, 0), solve2(i, j)));
		}
	cout << answer;
	return 0;
}