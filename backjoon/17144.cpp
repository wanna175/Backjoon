#include <iostream>

using namespace std;
int R, C, T,total=0,clean_rust=0;
int up = 0, down = 0;
int board[2][51][51] = { 0 };
void Clean_board() {
	for (int i = up - 1; i >= 1; --i)
		board[0][i + 1][1] = board[0][i][1];
	clean_rust += board[0][up][1];
	board[0][up][1] = -1;
	for (int i = down + 1; i <= R; ++i)
		board[0][i - 1][1] = board[0][i][1];
	clean_rust += board[0][down][1];
	board[0][down][1] = -1;
	for (int i = 2; i <= C; ++i) {
		board[0][1][i - 1] = board[0][1][i];
		board[0][R][i - 1] = board[0][R][i];
	}
	for (int i = 2; i <= up; ++i)
		board[0][i - 1][C] = board[0][i][C];
	for (int i = R-1; i >= down; --i)
		board[0][i +1][C] = board[0][i][C];
	for (int i = C - 1; i >= 2; --i) {
		board[0][up][i + 1] = board[0][up][i];
		board[0][down][i + 1] = board[0][down][i];
	}
	board[0][up][2] = 0;
	board[0][down][2] = 0;
}
int Calculation_diffusion(int y, int x,int value) {
	if (y<1 || x<1 || y>R || x>C || board[0][y][x] == -1)
		return 0;
	board[1][y][x] += value;
	return value;
}
void diffusion() {
	for(int i=1;i<=R;++i)
		for (int j = 1; j <= C; ++j) {
			if (board[0][i][j] <= 0) continue;
			int value = board[0][i][j]/5;
			board[1][i][j] -= Calculation_diffusion(i+1, j, value);
			board[1][i][j] -= Calculation_diffusion(i - 1, j, value);
			board[1][i][j] -= Calculation_diffusion(i, j+1, value);
			board[1][i][j] -= Calculation_diffusion(i, j-1, value);
		}
	for (int i = 1; i <= R; ++i)
		for (int j = 1; j <= C; ++j) {
			board[0][i][j] += board[1][i][j];
			board[1][i][j] = 0;
		}
	
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> R >> C >> T;
	for(int i=1;i<=R;++i)
		for (int j = 1; j <= C; ++j) {
			cin >> board[0][i][j];

			if (board[0][i][j] == -1) {
				if (up == 0)
					up = i;
				else
					down = i;
			}
			else {
				total += board[0][i][j];
			}
		}
	for (int i = 1; i <= T; ++i) {
		diffusion();
		Clean_board();
	}
	cout << total - clean_rust;
	return 0;
}