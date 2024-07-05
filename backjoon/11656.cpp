#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
vector<string> arr;
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	string str;
	cin >> str;
	for (int i = 0; i < str.length(); ++i)
		arr.push_back(str.substr(i));
	sort(arr.begin(), arr.end());
	for (string s : arr)
		cout << s << '\n';
	return 0;
}