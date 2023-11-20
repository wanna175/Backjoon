#include <iostream>
#include<string>
#include<vector>
using namespace std;
string str,b;
void solve() {
	vector<int> cache;
	string stack="";
	string answer = "";
	int idx=-1;
	for (int i = 0; i < str.size(); ++i) {
		if (idx != -1&&str[i] == b[idx]) {
		stack.push_back(str[i]);
		++idx;
		}
		else if (str[i] == b[0]) {
			stack.push_back(str[i]);
			cache.push_back(idx);
			idx = 1;
		}
		else {
			answer += stack;
			answer.push_back(str[i]);
			stack = "";
			cache.clear();
			idx = -1;
		}
		if (idx == b.size()) {
			for(int j=0;j<b.size();++j)
				stack.pop_back();
			idx = cache.back();
			cache.pop_back();
		}
	}
	answer += stack;
	if (answer.size() == 0)
		cout << "FRULA";
	else
		cout << answer;
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> str>>b;
	solve();
	return 0;
}