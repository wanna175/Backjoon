#include<iostream>
#include<vector>
#define INF 1000001
using namespace std;
int answer[1000000];
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;
	vector<pair<int, int>> stack;
	stack.push_back({INF, -1});
	for (int i = 0; i < N; ++i) {
		int num;
		cin >> num;
		answer[i] = -1;
		while (stack.back().first < num) {
			answer[stack.back().second] = num;
			stack.pop_back();
		}
		stack.push_back({ num,i });
	}
	for (int i = 0; i < N; ++i) cout << answer[i] << " ";
	return 0;
}