#include<iostream>
#include<vector>
#define INF 2147483649
using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int N;
	long long answer = 0;
	cin >> N;
	vector<unsigned int> stack;
	stack.push_back(INF);
	for (int i = 0; i <= N; ++i) {
		unsigned int num;
		if (i == N)
			num = INF;
		else
			cin >> num;

		long long pop_cnt = 0;
		unsigned int top = stack.back();
		while (top < num) {
			stack.pop_back();
			pop_cnt++;
			if (top != stack.back()) {
				answer += pop_cnt * 2 + pop_cnt * (pop_cnt - 1) / 2;
				if (i == N) answer -= pop_cnt;
				if (stack.back() == INF) answer -= pop_cnt;
				pop_cnt = 0;
				top = stack.back();
			}
		}
		stack.push_back(num);
	}
	cout << answer;
	return 0;
}