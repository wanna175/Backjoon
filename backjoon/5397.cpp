#include<iostream>
#include<string>
#include<list>

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;
	list<char> answer;
	for (int i = 0; i < N; ++i) {
		answer.clear();
		string input;
		cin >> input;
		list<char>::iterator cursor = answer.begin();
		for (auto v : input) {
			switch (v) {
			case '<':
				if (cursor != answer.begin()) cursor--;
				break;
			case '>':
				if (cursor != answer.end()) cursor++;
				break;
			case '-':
				if (cursor != answer.begin())
					cursor = answer.erase(--cursor);
				break;
			default:
				answer.insert(cursor, v);
				break;
			}
		}
		for (auto v : answer) cout << v;
		cout << '\n';
	}
	return 0;
}