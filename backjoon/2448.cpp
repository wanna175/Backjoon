#include <iostream>
#include <vector>
#include <map>
using namespace std;
int N;
vector<vector<char>> board;
map<int, int> m;
void Draw(int n,int y,int x) {
	if (n == 3) {
		board[y - 2][x - 2] = '*';
		board[y - 1][x - 1] = '*';
		board[y - 1][x - 3] = '*';
		for(int i=x;i>x-5;--i)
			board[y][i] = '*';
		return;
	}
	Draw(n / 2,y-n/2,x-m[n/2]+m[n/2]/2);//À­»ï°¢Çü
	Draw(n / 2, y, x);//¿À¸¥ÂÊ¾Æ·¡ »ï°¢Çü
	Draw(n / 2, y, x-m[n/2]-1);//¿ÞÂÊ¾Æ·¡ »ï°¢Çü

}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	int n = N/3;
	int tmp = 1;
	m[3] = 5;
	while (n!=tmp) {
		
		int t = m[tmp * 3] - 5 * tmp;
		tmp *= 2;
		m[tmp * 3] = 5 * tmp + t*2+1;
	}
	board.resize(N, vector<char>(m[N], ' '));
	Draw(N, N-1, m[N]-1);
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < board[0].size(); ++j)
			cout << board[i][j];
		cout << '\n';
	}
		
	return 0;
}