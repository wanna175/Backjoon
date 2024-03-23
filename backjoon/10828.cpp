#include<iostream>
#include<vector>
#include<string>

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	vector<int> stack;
	int N,num;
	cin >> N;
	string instr;
	for (int i = 0; i < N; ++i) {
		cin >> instr;
		if (instr.compare("push")==0) {
			cin >> num;
			stack.push_back(num);
		}
		else if (instr.compare("pop")==0) {
			if (!stack.empty()) {
				cout << stack.back() << '\n';
				stack.pop_back();
			}
			else
				cout << -1 << '\n';
		}
		else if (instr.compare("size")==0)
			cout << stack.size() << '\n';
		else if (instr.compare("empty")==0) {
			if (stack.empty())
				cout << 1 << '\n';
			else
				cout << 0 << '\n';
		}
		else {
			if (!stack.empty())
				cout << stack.back() << '\n';
			else
				cout << -1 << '\n';
		}
	}
	return 0;
}