#include <iostream>
#include <vector>
using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, K;
	cin >> N >> K;
	vector<int> circle_queue(N+1, 0);

	for (int i = 0; i < N+1; ++i)
		circle_queue[i] = i;
	int cur = 0;
	cout << '<';
	for (int i = 0; i < N; ++i) {
		cur += K;
		while(cur >= circle_queue.size())
			cur = cur - circle_queue.size() + 1;
		cout << circle_queue[cur];
		circle_queue.erase(circle_queue.begin() + cur--);
		if (i != N - 1)
			cout << ", ";
		else
			cout << '>';
	}
	return 0;
}