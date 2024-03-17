#include<iostream>
#include<string>
#include <list>
using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
    
	list<char> str;
	string init;
	int M;
	cin >> init >> M;
	for (auto v : init) str.push_back(v);
	list<char>::iterator cursor = str.end();
	cin.ignore();
	for (int i = 0; i < M; ++i) {
		string op;
		getline(cin, op);
		switch (op[0])
		{
		case 'L':
			if(cursor!=str.begin()) cursor--;
			break;
		case 'D':
			if (cursor != str.end()) cursor++;
			break;
		case 'B':
			if (cursor != str.begin()) {
				cursor = str.erase(--cursor);
			}
			break;
		default:
			cursor = str.insert(cursor, op[2]);
			cursor++;
			break;
		}

	}
	for (auto v : str)cout << v;
	return 0;
}