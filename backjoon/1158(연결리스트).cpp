#include <iostream>
#include <list>

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, K;
	cin >> N >> K;
	list<int> num;
	for (int i = 0; i < N; ++i) num.push_back(i + 1);
	list<int>::iterator current = num.begin();

	cout << '<';
	for (int i = 0; i < N; ++i) {
		for (int j = 1; j < K; ++j) {
			if (current == --(num.end()))
				current = num.begin();
			else
				current++;
		}
		cout << *current;
		current = num.erase(current);
		if (current == num.end())
			current = num.begin();
		if (i < N - 1)
			cout << ", ";
	}
	cout << '>';
	return 0;
}