#include<iostream>
#include<queue>
#include<cmath>
using namespace std;
int N, M;
bool isvisted[1000001];
queue<pair<int,int>> Q;
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M;
	for (int i = 0; i < M; ++i) {
		int password;
		cin >> password;
		Q.push({password, 0});
		isvisted[password] = true;
	}
	int answer = 0;
	while (!Q.empty()) {
		int cur = Q.front().first;
		int dis = Q.front().second;
		Q.pop();
		for (int i = 0; i < 20; ++i) {
			int next = cur ^ (1 << i);
			int ndis = dis + 1;
			if (next > N || isvisted[next]) continue;
			isvisted[next] = true;
			Q.push({ next,ndis });
			answer = max(answer, ndis);
		}
	}
	cout << answer;
	return 0;
}