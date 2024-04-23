#include<iostream>
#include<stack>
#include<string>

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	string str;
	cin >> str;
	stack<char> S;
	bool flag = false;
	int answer = 0;
	for (auto ch : str) {
		if (ch == '(') {
			S.push(ch);
			flag = false;
		}
		else {
			S.pop();
			if (!flag) {
				answer += S.size();
				flag = true;
			}
			else
				answer++;
		}
	}
	cout << answer;
	return 0;
}