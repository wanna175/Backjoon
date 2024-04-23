#include<iostream>
#include<queue>
#include<string>

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int N;
	cin >> N;
	queue<int> Q;
	for (int i = 0; i < N; ++i) {
		string str;
		cin >> str;
		if (str.compare("push") == 0) {
			int num;
			cin >> num;
			Q.push(num);
		}
		else if (str.compare("pop") == 0) {
			if(!Q.empty()){
				cout << Q.front() << '\n';
				Q.pop();
			}
			else
				cout << -1 << '\n';
		}
		else if (str.compare("size") == 0) {
			cout << Q.size() << '\n';
		}
		else if (str.compare("empty") == 0) {
			if (Q.empty())
				cout << 1 << '\n';
			else
				cout << 0 << '\n';
		}
		else if (str.compare("front") == 0) {
			if (!Q.empty())
				cout << Q.front() << '\n';
			else
				cout << -1 << '\n';
		}
		else if (str.compare("back") == 0) {
			if (!Q.empty())
				cout << Q.back() << '\n';
			else
				cout << -1 << '\n';
		}
	}
	return 0;
}