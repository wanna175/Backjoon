#include<iostream>
#include<stack>
#include<string>

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	string str;
	cin >> str;
	stack<pair<char,int>> S;
	S.push({ '*',-1});
	int answer[30] = { 0 };
	for (auto ch : str) {
		if (ch == '(' || ch == '[') {
			S.push({ ch,1+S.top().second });
		}
		else if ((ch == ')'&&S.top().first=='(')|| (ch == ']' && S.top().first == '[')) {
			int idx = S.top().second;
			S.pop();
			int num = (ch == ')') ? 2 : 3;
			answer[idx] += (answer[idx+1] != 0) ? answer[idx + 1] * num : num;
			answer[idx + 1] = 0;
		}
		else {
			answer[0] = 0;
			break;
		}
	}
	if (S.size() != 1) answer[0] = 0;
	cout << answer[0];
	return 0;
}