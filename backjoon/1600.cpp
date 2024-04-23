#include<iostream>
#include<queue>

using namespace std;
struct pos {
	int y;
	int x;
	int cnt;
};
int K, W, H;
int board[200][200];
int isvisited[31][200][200];
int dy[12] = { 1,0,-1,0,1,1,2,2,-1,-1,-2,-2 };
int dx[12] = { 0,-1,0,1,2,-2,1,-1,2,-2,1,-1 };
int BFS() {
	queue<pos> Q;
	Q.push({ 0,0,0 });
	for(int i=0;i<31;++i)
		isvisited[i][0][0] = 1;
	while (!Q.empty()) {
		int cy = Q.front().y;
		int cx = Q.front().x;
		int cc = Q.front().cnt;
		Q.pop();
		for (int i = 0; i < 12; ++i) {
			int ny = cy + dy[i];
			int nx = cx + dx[i];
			int nc = cc;
			if (i >= 4)	nc++;
			if (nc > K) continue;
			if (ny < 0 || nx < 0 || ny >= H || nx >= W) continue;
			if (board[ny][nx] == 1 || isvisited[nc][ny][nx] > 0) continue;
			isvisited[nc][ny][nx] = isvisited[cc][cy][cx] + 1;
			if (ny == H - 1 && nx == W - 1)
				return isvisited[cc][cy][cx];
			Q.push({ ny,nx,nc });
		}
	}
	return -1;
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> K >> W >> H;
	for (int i = 0; i < H; ++i) {
		for (int j = 0; j < W; ++j) {
			cin >> board[i][j];
		}
	}
	if (W == 1 && H == 1)
		cout << 0;
	else
		cout << BFS();
	return 0;
}