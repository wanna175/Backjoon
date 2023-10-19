#include <iostream>
#include <vector>
using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;
	vector<int> answer(T, -1);
	for (int i = 0; i < T; ++i) {
		int M, N, x, y;
		cin >> M >> N >> x >> y;
		int j = x;
		int least_common_multiple = N*M;
		for (int i = 1; i < M; ++i) {
			if ((N * i) % M == 0) {
				least_common_multiple = N * i;
				break;
			}
		}
		while (j<=least_common_multiple) {
			if ((j-y)%N == 0) {
				answer[i] = j;
				break;
			}
			j+=M;
		}
	}
	for(int i=0;i<T;++i)
		cout << answer[i] << '\n';

	return 0;
}