#include<iostream>
#include<queue>

using namespace std;
int F, S, G;
int isvisited[1000001];
int mv[2];
int BFS() {
	queue<int> Q;
	Q.push(S);
	isvisited[S] = 1;
	
	while (!Q.empty()) {
		int cur = Q.front();
		Q.pop();
		for (int i = 0; i < 2; ++i) {
			int next = cur + mv[i];
			if (next <= 0 || next > F||isvisited[next]!=0) continue;
			isvisited[next] = isvisited[cur] + 1;
			if (next == G)
				return isvisited[cur];
			Q.push(next);
		}
	}
	return -1;
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> F >> S >> G >> mv[0] >> mv[1];
	mv[1] = -mv[1];
	if (S == G) {
		cout << 0;
	}
	else {
		int answer = BFS();
		if (answer == -1) cout << "use the stairs";
		else cout << answer;
	}
	return 0;
}
