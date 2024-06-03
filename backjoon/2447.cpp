#include<iostream>
using namespace std;
int N;
char board[6561][6561];
void fillNone(int n,int y,int x) {
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			board[y + i][x + j] = ' ';
}
void print(int n,int y,int x) {
	if (n == 3) {
		for(int i=0;i<3;++i)
			for(int j=0;j<3;++j)
				board[y+i][x+j] = '*';
		board[y + 1][x + 1] = ' ';
		return;
	}
	n /= 3;
	for (int i = 0; i < 3; ++i)
		for (int j = 0; j < 3; ++j) {
			if (i == 1 && j == 1)
				fillNone(n, y + n * i, x + n * j);
			else
				print(n, y + n * i, x + n * j);
		}
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	print(N, 0, 0);
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j)
			cout << board[i][j];
		cout << '\n';
	}
	return 0;
}