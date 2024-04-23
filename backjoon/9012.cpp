#include<iostream>
#include<vector>
#include<string>

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int N;
	cin >> N;

	for (int i = 0; i < N; ++i) {
		vector<char> stack;
		bool flag = true;
		string s;
		cin >> s;
		for (auto ch : s) {
			if (ch == '(') {
				stack.push_back(')');
			}
			else {
				if (stack.empty()||stack.back()!=ch) {
					flag = false;
					break;
				}
				stack.pop_back();
			}
		}
		if (!stack.empty() || !flag) cout << "NO\n";
		else cout << "YES\n";
	}
	return 0;
}