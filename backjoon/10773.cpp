#include<iostream>
#include<vector>

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int K;
	vector<int> stack;
	int answer=0;
	cin >> K;
	for (int i = 0; i < K; ++i) {
		int num;
		cin >> num;
		if (num == 0) {
			answer -= stack.back();
			stack.pop_back();
		}
		else {
			stack.push_back(num);
			answer += num;
		}
	}
	cout << answer;
	return 0;
}