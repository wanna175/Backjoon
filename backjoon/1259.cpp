#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	while (true) {
		string num;
		string rnum;
		cin >> num;
		if (num == "0")
			break;
		rnum = num;
		reverse(rnum.begin(), rnum.end());
		if (num == rnum)
			cout << "yes"<<'\n';
		else
			cout << "no"<<'\n';
	}
	return 0;
}