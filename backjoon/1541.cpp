#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;
vector<string> Split(string str, char delimiter) {
	vector<string> str_arr;
	istringstream ss(str);
	string buffer;
	while (getline(ss, buffer, delimiter)) {
		str_arr.emplace_back(buffer);
	}
	return str_arr;
}
int solve(string str) {
	int ret = 0;
	vector<string> str_arr = Split(str, '-');
	vector<int> ret_arr(str_arr.size(), 0);
	for (int i = 0; i < str_arr.size(); ++i) {
		vector<string> tmp_arr = Split(str_arr[i], '+');
		for (int j = 0; j < tmp_arr.size(); ++j)
			ret_arr[i] += stoi(tmp_arr[j]);
	}
	for (int i = 1; i < ret_arr.size(); ++i) {
		ret += ret_arr[i];
	}
	ret = ret_arr[0] - ret;
	return ret;
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	string str;
	cin >> str;
	cout << solve(str);
	return 0;
}