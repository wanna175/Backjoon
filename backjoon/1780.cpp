#include<iostream>
#include<map>
using namespace std;
int N;
int board[2187][2187];
map<int, int> answer;
bool checkPaper(int y,int x,int size) {
	int tmp = board[y][x];
	for (int i = y; i < y+size; ++i)
		for (int j = x; j < x+size; ++j)
			if (tmp != board[i][j])
				return false;
	return true;
}
void cutPaper(int y,int x,int size) {
	if (checkPaper(y, x, size)) {
		answer[board[y][x]]++;
		return;
	}
	size /= 3;
	for (int i = 0; i < 3; ++i)
		for (int j = 0; j < 3; ++j)
			cutPaper(y + i * size, x + j * size, size);
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	answer[-1] = 0;
	answer[0] = 0;
	answer[1] = 0;
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j)
			cin >> board[i][j];
	cutPaper(0, 0, N);
	cout << answer[-1] << '\n';
	cout << answer[0] << '\n';
	cout << answer[1] << '\n';
	return 0;
}