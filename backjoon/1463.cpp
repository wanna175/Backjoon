#include <iostream>
using namespace std;
int arr[1000001] = { 0 };
void solve(int N) {
	int ret = 2;
	arr[0] = 999999;
	while (ret <= N) {
		int div2=0, div3=0;
		if (ret % 3 == 0)
			div3 = ret / 3;
		if (ret % 2 == 0)
			div2 = ret / 2;
		arr[ret] = min(arr[ret - 1], min(arr[div2], arr[div3]))+1;
		++ret;
	}
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;
	solve(N);
	cout << arr[N];
	return 0;
}