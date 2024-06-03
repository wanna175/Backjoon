#include<iostream>
#include<queue>
#define MAX 500001
using namespace std;
int N, K;
int board[MAX];
int brother[MAX];
int dx[3] = { 1,-1,0 };
int BFS(int Time) {
	queue<pair<int,int>> Q;
	Q.push({N,0});
	while (!Q.empty()) {
		int cur = Q.front().first;
		int ct = Q.front().second;
		if (ct >= Time) break;
		Q.pop();
		for (int i = 0; i < 3; ++i) {
			int next = cur + dx[i];
			int nt = ct + 1;
			if (i == 2) { 
				next *= 2;
			}
			if (next < 0 || next >= MAX) continue;
			if (board[next] == nt)  continue;//중복방지
			board[next] = nt;
			if (brother[next]-nt>=0&&(brother[next]-nt)%2==0) {

			}
			if (brother[next] == nt)
				return nt;
			Q.push({ next,nt });
		}
	}
	return -1;
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> K;
	if (N == K) {
		cout << 0;
		return 0;
	}

	int Time = 1;
	while (K+Time < MAX) {
		K += Time;
		brother[K] = Time;
		Time++;
	}//시간당 동생의 위치를 기록한다.
	//time이상으로 실행하면 -1
	int answer = BFS(Time);
	cout << answer;
	return 0;
}