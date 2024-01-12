#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n,x;
	int answer = 0;
	vector<int> sequence;
	map<int, int> dic;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		int t; cin >> t;
		sequence.push_back(t);
	}
	cin >> x;
	for (int i = 0; i < n; ++i) {
		if (dic.find(x - sequence[i]) != dic.end()) {
			answer+= dic[x - sequence[i]]; dic[x - sequence[i]]++;
		}
		else
			dic[sequence[i]] = 1;
	}
	cout << answer;
	return 0;
}