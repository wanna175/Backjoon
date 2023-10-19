#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N,answer=0,cnt;
	cin >> N;
	vector<int> time(N,0);
	for (int i = 0; i < N; ++i) {
		cin >> time[i];
	}
	sort(time.begin(), time.end());
	cnt = N;
	for (int i = 0; i < N; ++i)
		answer += time[i] * (cnt--);
	cout << answer;
	return 0;
}