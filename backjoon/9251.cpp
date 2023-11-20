#include<iostream>
#include<string>
using namespace std;
int cache[1001][1001] = { 0 };
int solve(string s1, string s2) {
	for (int i = 0; i < s1.size(); ++i) {
		for (int j = 0; j < s2.size(); ++j) {
			if (s1[i] == s2[j])
				cache[i + 1][j + 1] = cache[i][j] + 1;
			else
				cache[i + 1][j + 1] = max(cache[i][j + 1], cache[i + 1][j]);
		}
	}
	int ret = 0;
	for (int i = 1; i <= s2.size(); ++i)
		ret = max(ret, cache[s1.size()][i]);
	return ret;
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string s1, s2;
	cin >> s1 >> s2;
	cout << solve(s1, s2);
	return 0;
}