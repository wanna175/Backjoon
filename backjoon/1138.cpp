#include <iostream>
#include <vector>

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;
	vector<int> arr(N, 0);
	vector<int> answer;
	for (int i = 0; i < N; ++i) {
		int num;
		cin >> num;
		arr[i] = num;
	}
	for (int i = N - 1; i >= 0; --i) {
		int cmd = arr[i];
		answer.insert(answer.begin()+cmd, i + 1);
	}
	for (int i = 0; i < N; ++i)
		cout << answer[i] << ' ';
	return 0;
}