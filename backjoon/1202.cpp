#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define pii pair<int,int>
using namespace std;
int N, K;
vector<pii> mv;
vector<int> bags;
long long solve() {
	priority_queue <int> q;
	int b_idx = 0;
	int mv_idx = 0;
	long long ret = 0;
	while (b_idx<K&&mv_idx<N) {
		if (bags[b_idx] >= mv[mv_idx].first) {
			q.push(mv[mv_idx].second);
			++mv_idx;
		}
		else {
			if (q.empty()) {
				++b_idx;
				continue;
			}
			ret += q.top();
			q.pop();
			++b_idx;
		}
	}
	for (int i = b_idx; i < K; ++i) {
		if (q.empty()) break;
		ret += q.top();
		q.pop();
	}
	return ret;
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> K;
	mv.resize(N, {0,0});
	bags.resize(K, 0);
	for (int i = 0; i < N; ++i)
		cin >> mv[i].first >> mv[i].second;
	for (int i = 0; i < K; ++i) {
		cin >> bags[i];
	}
	sort(mv.begin(), mv.end());//무게순 오름차순으로 정렬
	sort(bags.begin(), bags.end());//무게순 오름차순으로 정렬
	cout << solve();
	return 0;
}