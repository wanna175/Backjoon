#include <iostream>
#include <vector>
using namespace std;
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, X, tmp;
	vector<int> answer;
	cin >> N >> X;
	for (int i = 0; i < N; ++i) {
		cin >> tmp;
		if (tmp < X)
			answer.push_back(tmp);
	}
	for (int i = 0; i < answer.size()-1; ++i)
		cout << answer[i]<<' ';
	cout << answer[answer.size()-1];

	return 0;
}