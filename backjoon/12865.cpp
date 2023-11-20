#include <iostream>
#include <vector>
#define pii pair<int,int>
using namespace std;
int N, K;
int cache[101][100001] = { 0 };
vector<pii> item;
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> K;
	item.resize(N + 1, { 0,0 });
	int ret = 0;
	for (int i = 1; i <= N; ++i)
		cin >> item[i].first >> item[i].second;
	for(int i=1;i<=N;++i)
		for (int j = 1; j <= K; ++j) {
			if (j >= item[i].first) {
				cache[i][j] = cache[i - 1][j - item[i].first] + item[i].second;
				cache[i][j] = max(cache[i][j], cache[i - 1][j]);
			}
			else
				cache[i][j] = cache[i - 1][j];
			ret = max(cache[i][j], ret);
		}
	cout << ret;
	return 0;
}