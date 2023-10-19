#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;
	map<int,int> m;
	vector<int> vec(N, 0);
	for (int i = 0; i < N; ++i) {
		cin >> vec[i];
		m[vec[i]] = 0;
	}
	map<int, int>::iterator it = m.begin();
	for (int i = 0; i < m.size(); ++i) {
		it->second = i;
		it++;
	}
	for (int i = 0; i < N; ++i) {
		cout << m[vec[i]];
		if (i != N - 1)
			cout << ' ';
	}
	return 0;
}