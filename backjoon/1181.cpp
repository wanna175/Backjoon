#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
vector<string> s;
bool Compare(string a, string b) {
	if (a.size() == b.size())
		return a < b;
	return a.size()<b.size();
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int N;
	string tmp="";
	cin >> N;
	s.resize(N, "");
	for (int i = 0; i < N; ++i)
		cin >> s[i];
	sort(s.begin(), s.end(), Compare);
	tmp = s[0];
	cout << tmp << '\n';
	for (int i = 1; i < N; ++i) {
		if (s[i] == tmp) continue;
		cout << s[i] << '\n';
		tmp = s[i];
	}
	return 0;
}