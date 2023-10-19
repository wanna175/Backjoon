#include <iostream>
#include <string>
#include <map>
using namespace std;
map<int, bool> S;
void resetMap(bool val) {
	for (int i = 1; i <= 20; ++i)
		S[i] = val;
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int M,x;
	cin >> M;
	string tmp = "";
	for (int i = 1; i <= 20; ++i)
		S[i] = false;
	for (int i = 0; i < M; ++i) {
		cin >> tmp;
		if (tmp == "all") {
			resetMap(true);
			continue;
		}
		else if (tmp == "empty") {
			resetMap(false);
			continue;
		}
		cin >> x;
		if (tmp == "add")
			S[x] = true;
		else if (tmp == "remove")
			S[x] = false;
		else if (tmp == "check")
			cout << S[x] << '\n';
		else if (tmp == "toggle")
			S[x] = !S[x];
	}
	return 0;
}