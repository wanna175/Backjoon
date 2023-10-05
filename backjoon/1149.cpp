#include <iostream>
#include <vector>
using namespace std;
//다이나믹 프로그래밍 좋은 예시...
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;
	vector<vector<int>> price(N+1,vector<int>(3,0));
	for (int i = 1; i <= N; ++i) {
		int R, G, B;
		cin >> R >> G >> B;
		price[i][0] = min(price[i - 1][1], price[i - 1][2])+R;
		price[i][1] = min(price[i - 1][0], price[i - 1][2])+G;
		price[i][2] = min(price[i - 1][0], price[i - 1][1])+B;
	}
	cout << min(price[N][0], min(price[N][1], price[N][2]));

	return 0;
}