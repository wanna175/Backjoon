#include <iostream>
#include <vector>
using namespace std;
int arr[12] = { 0 };
void solve(int n) {//나의 풀이=>11까지만 돌리면 되므로 브루트포스사용...
	if (n > 11)
		return;
	if (n != 0)
		arr[n]++;
	solve(n + 1);
	solve(n + 2);
	solve(n + 3);
}
void solve2() {//다른 사람들의 풀이=>규칙을 찾아서 디피사용
	arr[1] = 1;
	arr[2] = 2;
	arr[3] = 4;
	for (int i = 4; i <= 11; ++i)
		arr[i] = arr[i - 1] + arr[i - 2] + arr[i - 3];
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;
	solve(0);
	vector<int> answer(T, 0);
	for (int i = 0; i < T; ++i) {
		int tmp;
		cin >> tmp;
		answer[i]=arr[tmp];
	}
	for (int i = 0; i < T; ++i)
		cout << answer[i] << '\n';
	return 0;
}