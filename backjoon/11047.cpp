#include <iostream>
#include <vector>
using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, K,answer=0;
	cin >> N >> K;
	vector<int> coin(N, 0);
	for (int i = 0; i < N; ++i)
		cin >> coin[i];
	for (int i = coin.size() - 1; i >= 0; --i) {
		answer += K / coin[i];
		K = K % coin[i];
	}
	cout << answer;
	return 0;
}