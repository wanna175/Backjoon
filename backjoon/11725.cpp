#include <iostream>
#include <queue>
using namespace std;
int N;
vector<int> d[100001];
vector<int> tree;
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	tree.resize(N + 1, 0);
	for (int i = 0; i < N - 1; ++i) {
		int a, b;
		cin >> a >> b;
		d[a].push_back(b);
		d[b].push_back(a);
	}
	queue<int> q;
	q.push(1);
	while (!q.empty()) {
		int par = q.front();
		q.pop();
		for (int i = 0; i < d[par].size(); ++i) {
			if (tree[d[par][i]] != 0)continue;
			tree[d[par][i]] = par;
			q.push(d[par][i]);
		}
	}
	for (int i = 2; i <= N; ++i)
		cout << tree[i] << '\n';
	return 0;
}