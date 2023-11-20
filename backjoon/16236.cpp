#include <iostream>
#include <vector>
#include <queue>
#define pii pair<int,int>
using namespace std;
int N;
int board[20][20] = { 0 };
class Shark {
public:
	pii pos;
	int size=2;
	int exp=0;
	int time = 0;
	vector<pii> vec;
	void eat(int y,int x) {
		++exp;
		if (size <= exp) {
			exp = 0;
			++size;
		}
		pos.first = y;
		pos.second = x;
	}
	pii pick(int v) {
		pii ret=vec[0];
		for (int i = 1; i < vec.size(); ++i) {
			if (ret.first > vec[i].first)
				ret = vec[i];
			else if (ret.first == vec[i].first) {
				if (ret.second > vec[i].second)
					ret = vec[i];
			}
		}
		eat(ret.first, ret.second);
		time += v;
		vec.clear();
		return pos;
	}
};
Shark shark = Shark();
int bfs_push(int y,int x,int py,int px,queue<pii>& q,int (*visited)[20],int& v) {
	if (y < 0 || x < 0 || y >= N || x >= N || visited[y][x]!=0||board[y][x]>shark.size)
		return 0;
	visited[y][x] = visited[py][px]+1;
	if (v < visited[y][x])
		return -1;
	q.push({ y,x });
	if (board[y][x]!=0&&board[y][x] < shark.size) {
		v = visited[y][x];
		shark.vec.push_back({ y,x });
	}
	return visited[y][x];
}
bool BFS() {
	int v = 401;
	queue<pii> q;
	int visited[20][20] = { 0 };
	q.push(shark.pos);
	visited[shark.pos.first][shark.pos.second] = true;
	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		if (bfs_push(y - 1, x, y, x, q, visited, v)==-1)break;
		if (bfs_push(y, x - 1,y,x, q, visited,v)==-1) break;
		if (bfs_push(y, x + 1,y,x, q, visited,v)==-1) break;
		if (bfs_push(y + 1, x,y,x, q, visited,v)==-1) break;
	}
	if (v == 401) {
		return false;
	}
	pii p = shark.pick(v-1);
	board[p.first][p.second] = 0;
	return true;
}
int solve() {
	while (true) {
		bool flag = false;
		for(int i=0;i<N;++i)
			for (int j = 0; j < N; ++j)
				if (board[i][j]!=0&&shark.size > board[i][j])
					flag = true;
		if (!flag) break;
		if (!BFS())break;
	}
	return shark.time;
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j) {
			cin >> board[i][j];
			if (board[i][j] == 9) {
				shark.pos = { i,j };
				board[i][j] = 0;
			}
		}
	cout<<solve();
	return 0;
}