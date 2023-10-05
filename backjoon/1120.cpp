#include <iostream>
#include <string>

using namespace std;
int CompareString(int idx,string A, string B) {
	if (idx + A.size() > B.size())
		return A.size();
	int ret = 0;
	for (int i = idx; i < idx + A.size(); ++i)
		if (A[i - idx] != B[i])
			++ret;
	ret = min(ret, CompareString(idx + 1, A, B));
	return ret;
}
int main(void) {
	string A, B;
	cin >> A >> B;
	cout << CompareString(0, A, B);
	return 0;
}