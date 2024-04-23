#include<iostream>
#include<vector>
#define INF 1000000001
using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	long long answer = 0;
	cin >> N;
	vector<int> stack;
	stack.push_back(INF);
	for (int i = 0; i < N; ++i) {
		int height;
		cin >> height;
		int pop_cnt = 0;
		while (stack.back() <= height) {
			stack.pop_back();
			answer += pop_cnt;
			pop_cnt++;
		}
		answer += pop_cnt * (stack.size() - 1);
		stack.push_back(height);
	}
	answer += (stack.size() - 2) * (stack.size() - 1) / 2;
	cout << answer << '\n';
	return 0;
}