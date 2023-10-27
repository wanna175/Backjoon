#include <iostream>
#include <string>
#include <vector>
using namespace std;
int diff(string s1, string s2, string s3) {
	int ret = 8;
	for(int i=0;i<4;++i)
		if ((s1[i] == s2[i]) && (s2[i] == s3[i]))
			ret -= 2;
	return ret;
}
int solve(vector<string>& students) {
	int ret = 8;
	for (int i = 0; i < students.size() - 2; ++i)
		for (int j = i + 1; j < students.size() - 1; ++j)
			for (int k = j + 1; k < students.size(); k++) {
				ret = min(ret, diff(students[i], students[j], students[k]));
				if (ret == 0)
					return 0;
			}
	return ret;
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;
	for (int i = 0; i < T; ++i) {
		int N;
		cin >> N;
		vector<string> students(N, "");
		for (int j = 0; j < N; ++j)
			cin >> students[j];
		cout << solve(students)<<'\n';
	}

	return 0;
}