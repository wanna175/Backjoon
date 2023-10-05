#include <iostream>
#include <string>
#include <set>
using namespace std;
int solve(set<string>& str) {
	int ret = 0;
	for (set<string>::iterator i = str.begin(); i != str.end(); ++i) {
		bool cmd = true;
		for (set<string>::iterator j = str.begin(); j != str.end(); ++j) {
			if ((*j).find(*i) == 0 && i!=j) {
				cmd = false;
				break;
			}
		}
		if (cmd)
			ret++;
	}
	return ret;
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;
	set<string> str;
	for (int i = 0; i < N; ++i) {
		string tmp;
		cin >> tmp;
		str.insert(tmp);
	}
	cout << solve(str);
	return 0;
}