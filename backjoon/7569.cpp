#include <iostream>
#include <queue>
#include <vector>

using namespace std;
int M, N, H;//가로 세로 높이
int cache[100][100][100] = { 0 };
queue<vector<int>> q;
int BFSPush(int h,int n,int m,vector<int>& cur) {
	if (h<0 || n < 0 || m < 0 || h > H - 1 || n > N - 1 || m > M - 1
		|| cache[h][n][m] != 0)
		return 0;
	cache[h][n][m] = cache[cur[0]][cur[1]][cur[2]] + 1;
	q.push({h,n,m});
	return 1;
}
int solve(int empty) {
	int ret = q.size();
	int answer=1;
	while (q.size() > 0) {
		int h = q.front()[0];
		int n = q.front()[1];
		int m = q.front()[2];
		ret += BFSPush(h + 1, n, m, q.front());
		ret += BFSPush(h - 1, n, m, q.front());
		ret += BFSPush(h, n+1, m, q.front());
		ret += BFSPush(h, n-1, m, q.front());
		ret += BFSPush(h, n, m+1, q.front());
		ret += BFSPush(h, n, m-1, q.front());
		q.pop();
		answer = cache[h][n][m];
	}
	if (empty + ret < M * N * H)
		return -1;
	return answer-1;
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> M >> N >> H;
	int empty = 0;
	for(int i=0;i<H;++i)
		for(int j=0;j<N;++j)
			for (int k = 0; k < M; ++k) {
				cin >> cache[i][j][k];
				if (cache[i][j][k] == 1)
					q.push({ i,j,k });
				else if(cache[i][j][k] == -1)
					empty++;
			}
	cout<<solve(empty);
	return 0;
}
