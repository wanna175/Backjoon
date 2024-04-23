#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int N;
	cin >> N;
	int answer = 0;
	for (int i = 0; i < N; ++i) {
		vector<char> stack;
		string s;
		cin >> s;
		for (auto ch : s) {
			if (!stack.empty() && ch == stack.back())
				stack.pop_back();
			else
				stack.push_back(ch);
		}
		if (stack.empty()) answer++;
	}
	cout << answer;
	return 0;
}