#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	while (true) {
		string s;
		bool flag = true;
		getline(cin, s);
		if (s == ".") break;
		vector<char> stack;
		for (auto ch : s) {
			if (ch == '(') stack.push_back(')');
			else if (ch == '[') stack.push_back(']');
			else if ( ch == ')' || ch == ']') {
				if (!stack.empty() && ch == stack.back()) stack.pop_back();
				else {
					flag = false;
					break;
				}
			}
		}
		if (!stack.empty() || !flag) cout << "no\n";
		else cout << "yes\n";
	}
	return 0;
}