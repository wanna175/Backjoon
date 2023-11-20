#include <iostream>
#include <vector>
#define pii pair<int,int>
using namespace std;
int N;
int board[15][15] = { 0 };
void cover(pii V,int value) {
	int cnt = 1;
	for (int i = V.first+1; i <= N; ++i) {
		board[i][V.second] += value;
		if(V.second+cnt<=N)
			board[i][V.second + cnt] += value;
		if(V.second-cnt>0)
			board[i][V.second - cnt] += value;
		++cnt;
	}
}
int solve(int row,int cnt) {
	if (cnt == N)
		return 1;
	int ret = 0;
	bool flag = false;
	for (int i = 1; i <= N; ++i) {
		if (board[row][i] == 0) {
			cover({ row,i }, 1);
			ret+=solve(row + 1,cnt+1);
			cover({ row,i }, -1);
			flag = true;
		}
	}
	if (!flag)
		return 0;
	return ret;
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	cout<<solve(1, 0);
	return 0;
}