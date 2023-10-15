#include <iostream>
#include <vector>
using namespace std;
long long M;
int solve(vector<int>& arr, int left,int right) {
	int mid = (left + right) / 2;
	long long ret=0;
	for (int i = 0; i < arr.size(); ++i)
		ret += (arr[i] > mid) ? arr[i] - mid : 0;
	if (left == right && ret >= M)
		return left;
	else if (left == right && ret < M)
		return left - 1;
	if (ret > M)
		return solve(arr, mid+1, right);
	else
		return solve(arr, left, mid);
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N >> M;
	vector<int> arr(N, 0);
	for (int i = 0; i < N; ++i)
		cin >> arr[i];
	cout << solve(arr, 0, 1000000000);
	return 0;
}