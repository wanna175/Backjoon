#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int cache[25][25] = { 0 };
void solve(vector<string>& board,int y,int x,int mark,int N) {
	if (y<0 || x<0 || x>N - 1 || y>N - 1
		||cache[y][x]!=0||board[y][x]=='0')
		return;
	cache[y][x] = mark;
	solve(board, y+1, x, mark, N);
	solve(board, y-1, x, mark, N);
	solve(board, y, x+1, mark, N);
	solve(board, y, x-1, mark, N);
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N,mark=0;
	cin >> N;
	vector<string> board(N, "");
	for (int i = 0; i < N; ++i)
		cin >> board[i];
	
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j)
			if (cache[i][j] == 0 && board[i][j] == '1')
				solve(board, i, j, ++mark, N);
	cout << mark<<'\n';
	vector<int> answer(mark, 0);
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j)
			if (cache[i][j] != 0)
				answer[cache[i][j] - 1]++;
	sort(answer.begin(), answer.end());
	for (int i = 0; i < mark; ++i)
		cout << answer[i] << '\n';
	return 0;
}