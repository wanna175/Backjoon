#include<iostream>
#include<deque>
#include<algorithm>
using namespace std;
int T;
int n;
int student[100001];
bool isvisited[100001];
int BFS(int num) {
	deque<int> DQ;
	DQ.push_back(num);
	isvisited[num] = true;
	while (true) {
		int next = student[DQ.back()];
		if (!isvisited[next]) {
			DQ.push_back(next);
			isvisited[next] = true;
			continue;
		}
		int ret = 0;
		while (!DQ.empty()) {
			int cur = DQ.front();
			DQ.pop_front();
			if (next == cur)
				break;
			ret++;
		}
		return ret;
	}
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> T;
	for (int t = 0; t < T; ++t) {
		fill_n(&isvisited[0], 100001, false);
		cin >> n;
		for (int i = 1; i <= n; ++i) {
			cin >> student[i];
			if (i == student[i]) isvisited[i] = true;
		}
		int answer = 0;
		for (int i = 1; i <= n; ++i) {
			if (!isvisited[i])
				answer += BFS(i);
		}
		cout << answer << '\n';
	}
	return 0;
}