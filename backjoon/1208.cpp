#include <iostream>
#include <vector>
#include <map>
using namespace std;
int N, S;
vector<int> arr;
map<int, int> m;
void left(int idx, int cur) {
	if (idx >= N / 2) {
		++m[cur];
		return;
	}
	left(idx + 1, cur);
	left(idx + 1, cur + arr[idx]);
}
long long right(int idx,int cur){
	if (idx >= N) {
		if (m.find(S - cur) != m.end())
			return m[S-cur];
		else
			return 0;
	}
	long long ret = 0;
	ret+=right(idx + 1, cur);
	ret+=right(idx + 1, cur + arr[idx]);
	return ret;
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> S;
	arr.resize(N, 0);
	for (int i = 0; i < N; ++i)
		cin >> arr[i];
	left(0, 0);
	long long ret =  right(N / 2, 0);
	if (S == 0)
		--ret;
	cout << ret;
	return 0;
}