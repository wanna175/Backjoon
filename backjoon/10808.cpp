#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	string s;
	int alpha[26];
	fill(alpha, alpha + 26, 0);
	cin >> s;
	for (int i = 0; i < s.size(); ++i)
		alpha[s[i] - 'a']++;
	for (int i = 0; i < 26; ++i)
		cout << alpha[i] << ' ';
	return 0;
}