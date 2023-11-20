#include <iostream>
#include <queue>
#include <vector>

using namespace std;
int N;
int board[17][17] = { 0 };
queue<vector<int>> q;
void bfs_push(int y,int x,int mode,int prev_mode) {
	if(mode==0){
		if (x + 1 > N || board[y][x + 1] != 0 || prev_mode == 2)
			return;
		q.push({ y,x + 1,mode });
	}
	else if(mode==1){
		if (x +1 > N ||y+1>N|| board[y+1][x + 1] != 0 
			||board[y][x + 1] != 0 || board[y + 1][x] != 0)
			return;
		q.push({ y + 1,x + 1,mode });
	}
	else{
		if (y + 1 > N || board[y+1][x] != 0 || prev_mode == 0)
			return;
		q.push({ y + 1,x,mode });
	}
}
int BFS() {
	int answer = 0;
	while (!q.empty()) {
		int y = q.front()[0];
		int x = q.front()[1];
		int mode = q.front()[2];
		q.pop();
		if (y == N && x == N) {
			++answer;
			continue;
		}
		bfs_push(y, x, 0,mode);
		bfs_push(y, x, 1,mode);
		bfs_push(y, x, 2,mode);
	}
	return answer;
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	for (int i = 1; i <= N; ++i)
		for (int j = 1; j <= N; ++j)
			cin >> board[i][j];
	q.push({ 1,2,0 });
	cout << BFS();
	return 0;
}