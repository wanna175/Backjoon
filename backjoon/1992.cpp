#include<iostream>
#include<string>
using namespace std;
int N;
char board[64][64];
bool check(int y, int x, int size) {
	char tmp = board[y][x];
	for (int i = y; i < y + size; ++i)
		for (int j = x; j < x + size; ++j)
			if (tmp != board[i][j])
				return false;
	return true;
}
void compress(int y, int x, int size) {
	if (check(y, x, size)) {
		cout << board[y][x];
		return;
	}
	cout << "(";
	size /= 2;
	compress(y, x, size);
	compress(y, x + size, size);
	compress(y + size, x, size);
	compress(y + size, x + size, size);
	cout << ")";
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;

	for (int i = 0; i < N; ++i) {
		string str;
		cin >> str;
		for (int j = 0; j < N; ++j) {
			board[i][j] = str[j];
		}
	}
	compress(0, 0, N);
	return 0;
}