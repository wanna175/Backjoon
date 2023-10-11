#include <iostream>
#include <queue>
using namespace std;
int path[100001] = { 0 };
int solve(int N,int K) {
	queue<int> q;
	int ret=-1;
	q.push(N);
	while (q.size()>0) {
		if (q.front() == K) {
			ret = path[q.front()];
			break;
		}
		if (q.front()-1>=0&&path[q.front() - 1] == 0) {
			q.push(q.front() - 1);
			path[q.front() - 1] = path[q.front()] + 1;
		}
		if (q.front() + 1 <= 100000&&path[q.front() + 1] == 0) {
			q.push(q.front() + 1);
			path[q.front() + 1] = path[q.front()] + 1;
		}
		if (q.front() *2 <= 100000&&path[q.front()*2 ] == 0) {
			q.push(q.front()*2);
			path[q.front()*2] = path[q.front()] + 1;
		}
		q.pop();
	}
	return ret;
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, K;
	cin >> N >> K;
	cout << solve(N, K);
	return 0;
}