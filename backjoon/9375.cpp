#include <iostream>
#include <map>
using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;
	for (int i = 0; i < T; ++i) {
		int n,answer=1;
		cin >> n;
		string tmp1, tmp2;
		map<string, int> m;
		for (int j = 0; j < n; ++j) {
			cin >> tmp1 >> tmp2;
			if (m.find(tmp2) != m.end())
				m[tmp2]++;
			else
				m[tmp2] = 1;
		}
		for (map<string, int>::iterator it = m.begin(); it != m.end(); ++it)
			answer *= (it->second)+1;
		cout << answer-1 << '\n';
	}
	return 0;
}