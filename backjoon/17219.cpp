#include <iostream>
#include <map>
#include <string>
using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;
	map<string, string> m;
	for (int i = 0; i < N; ++i) {
		string tmp1, tmp2;
		cin >> tmp1 >> tmp2;
		m[tmp1] = tmp2;
	}
	for (int i = 0; i < M; ++i) {
		string tmp1;
		cin >> tmp1;
		cout << m[tmp1] << '\n';
	}
	return 0;
}
