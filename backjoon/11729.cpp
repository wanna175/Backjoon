#include<iostream>
#include<vector>
using namespace std;
int K = 0;
vector<pair<int, int>> answer;
void hanoi(int n,int cur,int target) {
	if (n == 1) {
		answer.push_back({ cur,target });
		K++;
		return;
	}
	int ntarget = 6 - cur - target;
	hanoi(n - 1, cur, ntarget);
	answer.push_back({ cur,target });
	K++;
	hanoi(n - 1, ntarget, target);
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int N;
	cin >> N;
	hanoi(N, 1,3);
	cout << K << '\n';
	for (auto v : answer)
		cout << v.first << " " << v.second << '\n';

	return 0;
}