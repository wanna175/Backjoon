#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;
int L, R, C;
int z, y, x;
char board[30][30][30];
int isvisited[30][30][30];
int dz[6] = { 0,0,0,0,-1,1 };
int dy[6] = { 1,0,-1,0,0,0 };
int dx[6] = { 0,1,0,-1,0,0 };
struct pos {
	int z;
	int y;
	int x;
};
int BFS() {
	fill_n(&isvisited[0][0][0], 30 * 30 * 30, -1);
	queue<pos> Q;
	Q.push({ z,y,x });
	isvisited[z][y][x] = 0;
	while (!Q.empty()) {
		int cz = Q.front().z;
		int cy = Q.front().y;
		int cx = Q.front().x;
		Q.pop();
		for (int i = 0; i < 6; ++i) {
			int nz = cz + dz[i];
			int ny = cy + dy[i];
			int nx = cx + dx[i];
			if (nz < 0 || ny < 0 || nx < 0 || nz >= L || ny >= R || nx >= C) continue;
			if (isvisited[nz][ny][nx]!=-1 || board[nz][ny][nx] == '#')continue;
			isvisited[nz][ny][nx] = isvisited[cz][cy][cx] + 1;
			Q.push({ nz,ny,nx });
			if (board[nz][ny][nx] == 'E')
				return isvisited[nz][ny][nx];
		}
	}
	return -1;
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	while (true) {
		cin >> L >> R >> C;
		if (L == 0 && R == 0 && C == 0)
			break;
		for(int r=0;r<L;++r)
			for(int i=0;i<R;++i)
				for (int j = 0; j < C; ++j) {
					cin >> board[r][i][j];
					if (board[r][i][j] == 'S') {
						z = r; y = i; x = j;
					}
				}
		int answer = BFS();
		if (answer == -1) cout << "Trapped!\n";
		else cout << "Escaped in " << answer << " minute(s).\n";
	}
	
	return 0;
}