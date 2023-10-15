#include <iostream>
#include <vector>
using namespace std;
int N;
int cache[301][2] = { 0 };
vector<int> stair(301, 0);
int solve(int idx,int mod) {
	if (idx < 2)
		return stair[1];
	if (cache[idx][mod - 1] != 0)
		return cache[idx][mod - 1];
	int ret = stair[idx];
	if (mod == 1) {
		ret +=solve(idx - 1, 2);
		cache[idx][mod - 1] = ret;
		return ret;
	}
	else {
		ret += max(solve(idx - 2, 2), solve(idx - 2, 1));
		return ret;
	}
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N;
	for (int i = 1; i <= N; ++i)
		cin >> stair[i];
	cache[2][1] = stair[2];
	cache[2][0] = stair[1] + stair[2];
	cout << max(solve(N,1),solve(N,2));
	return 0;
}