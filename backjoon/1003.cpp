#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;
unordered_map<int, pair<int, int>> p_map;

pair<int, int> solution(int num) {
	int idx;
	int size = p_map.size();
	if (num > size - 1) {
		for (int i = size; i <= num; i++) {
			pair<int, int> pp;
			pp.first = p_map[i - 2].first + p_map[i - 1].first;
			pp.second = p_map[i - 2].second + p_map[i - 1].second;
			p_map.insert({ i,pp });
		}
	}
	return p_map[num];
}
int main(void) {
	int T;
	vector<pair<int, int>> answer;
	p_map.insert({ 0, make_pair(1, 0) });
	p_map.insert({ 1, make_pair(0, 1) });
	cin >> T;
	for (int i = 0; i < T; i++) {
		int num;
		int p0 = 0;
		int p1 = 0;
		cin >> num;
		answer.push_back(solution(num));
	}
	for (int i = 0; i < T; i++) {
		cout << answer[i].first << " " << answer[i].second << endl;
	}
	return 0;
}