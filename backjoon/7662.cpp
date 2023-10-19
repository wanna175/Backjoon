#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T,k,x;
	cin >> T;
	char ch;
	for (int i = 0; i < T; ++i) {
		multiset<int> q;
		cin >> k;
		for (int j = 0; j < k; ++j) {
			cin >> ch >> x;
			switch (ch) {
			case 'I':
				q.insert(x);
				break;
			case 'D':
				if (q.size() == 0)
					break;
				if (x == -1)
					q.erase(q.begin());
				else
					q.erase(--q.end());
				break;
			}
		}
		if (q.empty())
			cout << "EMPTY" << '\n';
		else {
			cout << *(--q.end()) << ' ' << *(q.begin()) << '\n';
		}
		q.clear();
	}
	return 0;
}