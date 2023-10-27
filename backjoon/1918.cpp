#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	map<char, int> m;
	m['+'] = 1;
	m['-'] = 1;
	m['*'] = 2;
	m['/'] = 2;

	string str;
	vector<char> op;
	string answer = "";
	cin >> str;
	for (int i = 0; i < str.size(); ++i) {
		if (isalpha(str[i]))
			answer.push_back(str[i]);
		else {
			if (op.size() == 0)
				op.push_back(str[i]);
			else if (str[i] == '(')
				op.push_back(str[i]);
			else if (str[i] == ')') {
				while (op.back() != '(') {
					answer.push_back(op.back());
					op.pop_back();
				}
				op.pop_back();
			}
			else {
				char cur = op.back();
				while (cur != '(' && m[cur] >= m[str[i]]) {
					answer.push_back(cur);
					op.pop_back();
					if (op.empty())
						break;
					cur = op.back();
				}
				op.push_back(str[i]);
			}
		}
	}
	while (!op.empty()) {
		answer.push_back(op.back());
		op.pop_back();
	}
	cout << answer;
	return 0;
}