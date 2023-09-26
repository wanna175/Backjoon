#include <iostream>
#include <vector>
#include <map>

using namespace std;
vector<int> total_time;
int minbulidingTime(int W, map<int, vector<int>>& _rule, vector<int>& _time) {
	if (total_time[W - 1] != -1)
		return total_time[W - 1];
	
	int ret = 0;
	for (int i = 0; i < _rule[W].size(); ++i) {
		total_time[_rule[W][i]-1] = minbulidingTime(_rule[W][i], _rule, _time);
		ret = max(ret, total_time[_rule[W][i]-1]);
	}
	return ret+_time[W-1];
}

int main(void) {
	int T;
	cin >> T;
	vector<int> answer(T, 0);
	for (int i = 0; i < T; ++i) {
		int N, K, W;
		cin >> N >> K;
		vector<int> _time(N, 0);
		map<int, vector<int>> _rule;
		for (int j = 0; j < N; ++j) {
			int time;
			cin >> time;
			_time[j] += time;
			total_time.push_back(-1);
		}
		for (int j = 0; j < K; ++j) {
			int num1, num2;
			cin >> num1 >> num2;
			_rule[num2].push_back(num1);
		}
		for (int j = 0; j < N; ++j) {
			if (_rule.find(j + 1) == _rule.end())
				total_time[j] = _time[j];
		}
		cin >> W;//ÀÔ·Â³¡
		answer[i] = minbulidingTime(W, _rule, _time);
		total_time.clear();
	}
	for (int i = 0; i < T; ++i) {
		cout << answer[i] << endl;
	}
	return 0;
}