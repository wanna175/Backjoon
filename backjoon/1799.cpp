#include <iostream>
#include <vector>
using namespace std;
typedef pair<int, int> pii;

int N;
vector<pii> black;
vector<pii> white;
int board[11][11] = { 0 };
void bishop(int y,int x,int cover) {
	int sy = max(y - 1, N - y);
	int sx = max(x - 1, N - x);
	int s = max(sy, sx);
	for (int i = 1; i <= s; ++i) {
		if (y + i <= N && x + i <= N)
			board[y + i][x + i] += cover;
		if (y + i <= N && x - i > 0)
			board[y + i][x - i] += cover;
		if (y - i > 0 && x + i <= N)
			board[y - i][x + i] += cover;
		if (y - i > 0 && x - i > 0)
			board[y - i][x - i] += cover;

	}
}
int solve(int idx,int cur,vector<pii>& v) {
	if (idx>=v.size())
			return cur;
	int ret = 0;
	pii c = v[idx];
	idx++;
	while (idx<v.size()) {
		if (board[c.first][c.second] != 1) {
			c = v[idx];
			idx++;
		}
		else
			break;
	}
	ret = max(ret,solve(idx,cur,v));//안두는 경우
	if (board[c.first][c.second] == 1) {
		bishop(c.first, c.second, -1);
		ret = max(ret, solve(idx,cur + 1,v));
		bishop(c.first, c.second, 1);
	}
	return ret;
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	for (int i = 1; i <= N; ++i)
		for (int j = 1; j <= N; ++j) {
			cin >> board[i][j];
			if (board[i][j] == 1) {
				if ((i % 2 == 0 && j % 2 != 0) || (i % 2 != 0 && j % 2 == 0))
					white.push_back({ i,j });
				else
					black.push_back({ i,j });
			}
		}
	cout<<solve(0,0,black)+solve(0,0,white);

	return 0;
}