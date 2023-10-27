#include <iostream>
#include <vector>
using namespace std;

int N, M, K;
int parents[51];
vector<int> know;
vector<vector<int>> v(50);

int Find(int x) {
	int ret;
	if (parents[x]<0)
		ret= x;
	else {
		ret = Find(parents[x]);
		parents[x] = ret;
	}
	return ret;
}
void Union(int x, int y) {
	x = Find(x);
	y = Find(y);

	if (x == y)
		return;
	if (parents[x] < parents[y]) {
		parents[x] += parents[y];
		parents[y] = x;
	}
	else {
		parents[y] += parents[x];
		parents[x] = y;
	}
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M >> K;

	for (int i = 0; i < K; ++i) {
		int t;
		cin >> t;
		know.push_back(t);
	}
	for (int i = 1; i <= N; ++i) parents[i] = -1;

	for (int i = 0; i < M; ++i) {
		int cnt;
		cin >> cnt;
		int parent;
		int child;
		cin >> parent;
		v[i].push_back(parent);
		for (int j = 1; j < cnt; ++j) {
			cin >> child;
			Union(parent, child);
			v[i].push_back(child);
		}
	}
	for (auto& list : v) {
		bool flag = false;
		for (auto& person : list) {
			if (flag) break;
			for (auto& t : know) {
				if (Find(person) == Find(t)) {
					flag = true;
					break;
				}
			}
		}
		if (flag) M--;
	}
	cout << M;
}