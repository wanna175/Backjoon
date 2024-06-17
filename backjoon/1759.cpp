#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
int L, C;
vector<char> arr;
bool isVowels(char c) {
	if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
		return true;
	return false;
}
void backtracking(int v,int c,int idx,int m,string ans) {
	if (isVowels(arr[idx])) v++;
	else c++;
	ans += arr[idx];
	if (m == 1) {
		if (v >= 1 && c >= 2) cout << ans << '\n';
		return;
	}
	for (int i = idx + 1; i < arr.size(); ++i)
		backtracking(v, c, i, m - 1, ans);
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> L >> C;
	for (int i = 0; i < C; ++i) {
		char c;
		cin >> c;
		arr.push_back(c);
	}
	sort(arr.begin(), arr.end());
	for (int i = 0; i < arr.size(); ++i)
		backtracking(0, 0, i, L, "");

	return 0;
}