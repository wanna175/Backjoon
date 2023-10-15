#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;
vector<int> split(string str, char delimiter) {
	vector<int> str_arr;
	istringstream ss(str);
	string buffer;
	while (getline(ss, buffer, delimiter))
		str_arr.emplace_back(stoi(buffer));
	return str_arr;
}
string solve(string vec, string fuc) {
	string ret = "";
	vector<int> arr = split(vec, ',');
	int cnt = 0,first=0,end=arr.size();
	bool reverse = false;
	while (cnt < fuc.size()) {
		if (fuc[cnt] == 'R')
			reverse = !reverse;
		else {
			if (first==end)
				return "error";
			(!reverse) ? ++first : --end;
		}
		++cnt;
	}
	if(reverse){
		for (int i = end-1; i >= first; --i)
			ret += to_string(arr[i]) + ",";
	}
	else {
		for (int i = first; i < end; ++i)
			ret += to_string(arr[i]) + ",";
	}
	if(ret.size()!=0)
		ret.pop_back();
	return ret;
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;
	vector<string> answer(T, "[");
	for (int i = 0; i < T; ++i) {
		string tmp,arr;
		int n;
		cin >> tmp >> n >> arr;
		arr = arr.substr(1, arr.size() - 2);
		string ret = solve(arr, tmp);
		if (ret.compare("error")==0)
			answer[i] = ret;
		else
			answer[i] += ret + "]";
	}
	for (int i = 0; i < T; ++i)
		cout << answer[i] << '\n';
	return 0;
}