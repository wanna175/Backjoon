#include <iostream>
#include <vector>
using namespace std;
int blue = 0, white = 0;
bool CompareColor(const vector<vector<int>>& arr, int y, int x, int size) {
	int cmd = arr[y][x];
	for (int i = y; i < y + size; ++i)
		for (int j = x; j < x + size; ++j)
			if (arr[i][j] != cmd)
				return false;
	return true;
}
void solve(const vector<vector<int>>& board,int size,int y,int x){
	if (size == 1 || CompareColor(board, y, x, size)) {
		(board[y][x] == 1) ? ++blue : ++white;
		return;
	}
	solve(board, size / 2, y, x);
	solve(board, size / 2, y + size / 2, x + size / 2);
	solve(board, size / 2, y + size / 2, x);
	solve(board, size / 2, y, x + size / 2);
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int N;
	cin >> N;
	vector<vector<int>> board(N + 1, vector<int>(N + 1, 0));
	for (int i = 1; i <= N; ++i)
		for (int j = 1; j <= N; ++j)
			cin >> board[i][j];
	solve(board, N, 1, 1);
	cout << white << '\n';
	cout << blue;
	return 0;
}