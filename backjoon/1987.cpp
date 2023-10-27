#include <iostream>
#include <string>
#define pii pair<int,int>
using namespace std;
int R, C;
int board[21][21];
bool alpha[27] = { false };
int DFS(pii V,int cur) {
	int y = V.first;
	int x = V.second;
	if (y<1 || x<1 || x>C || y>R || alpha[board[y][x]])
		return cur-1;
	int ret = 0;
	alpha[board[y][x]] = true;
	ret = DFS({ y-1,x }, cur + 1);
	ret = max(ret,DFS({ y+1,x }, cur + 1));
	ret = max(ret, DFS({ y,x+1 }, cur + 1));
	ret = max(ret, DFS({ y,x-1 }, cur + 1));
	alpha[board[y][x]] = false;
	return ret;
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> R >> C;
	for (int i = 1; i <= R; ++i) {
		string str;
		cin >> str;
		for (int j = 1; j <= C; ++j){
			board[i][j] = str[j-1] - 'A';
		}
	}
	cout<<DFS({ 1,1 }, 1);
	return 0;
}