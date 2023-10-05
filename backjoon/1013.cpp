#include <iostream>
#include <cstring>
#include <vector>

using namespace std;
bool CompareSign(string str) {
	if (str.size() == 0)
		return true;
	if (str.size()==1)
		return false;
	string tmp = str.substr(0, 2);
	string tmp2 = str.substr(2);
	if(tmp=="01"){
		return CompareSign(tmp2);
	}
	else if (tmp == "10") {
		int idx0 = 1, idx1;
		while (idx0+1 < str.size() && str[idx0+1] == '0')
			idx0++;
		if (idx0 == 1)
			return false;
		idx1 = idx0;
		while (idx1 + 1 < str.size() && str[idx1 + 1] == '1')
			idx1++;
		if (idx1 == idx0)
			return false;
		if (idx1 - 1 == idx0)
			return CompareSign(str.substr(idx1 + 1));
		else {
			return CompareSign(str.substr(idx1 + 1))|| CompareSign(str.substr(idx1));
		}
	}
	else {
		return false;
	}

}
int main(void) {
	int T;
	cin >> T;
	vector<string> answer(T, "YES");
	for (int i = 0; i < T; ++i) {
		string tmp;
		cin >> tmp;
		if (!CompareSign(tmp))
			answer[i] = "NO";
	}
	for (int i = 0; i < T; ++i)
		cout << answer[i] << endl;
	return 0;
}
