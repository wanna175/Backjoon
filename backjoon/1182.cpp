#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N,S;
vector<int> arr;
int DFS(int idx,int cur,int size) {
	if (idx >= N)
		return (cur == S&&size>0) ? 1 : 0;
	int ret = 0;
	ret += DFS(idx + 1, cur,size);
	ret += DFS(idx + 1, cur + arr[idx],size+1);
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
	sort(arr.begin(), arr.end());
	cout << DFS(0, 0,0);
	return 0;
}