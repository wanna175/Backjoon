#include<iostream>
#include<vector>

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	vector<int> stack;
	vector<char> answer;
	int N,cur = 1;
	cin >> N;
	for (int i = 0; i < N; ++i) {
		int num;
		cin >> num;
		while (cur <= num) {
			stack.push_back(cur++);
			answer.push_back('+');
		}
		if (stack.back()!=num) {
			cout << "NO\n";
			return 0;
		}
		answer.push_back('-');
		stack.pop_back();
	}
	for (auto v : answer) cout << v << '\n';
	return 0;
}