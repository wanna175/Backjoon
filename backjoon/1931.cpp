#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
bool Compare(pair<int, int> p1, pair<int, int> p2) {
	if (p1.second > p2.second)
		return true;
	else if (p1.second == p2.second) {
		return p1.first > p2.first;
	}
	else
		return false;
		
}
int solve(vector<pair<int, int>>& arr,int end,int cur,int ret) {
	while (cur>=0) {
		if (arr[cur].first >= end)
			break;
		else
			cur--;
	}
	if (cur == -1)
		return ret;
	end = arr[cur].second;
	return solve(arr, end, cur-1, ret + 1);

}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;
	vector<pair<int, int>> arr;
	for (int i = 0; i < N; ++i) {
		int start, end;
		cin >> start >> end;
		arr.push_back(make_pair(start, end));
	}
	sort(arr.begin(), arr.end(), Compare);
	cout << solve(arr, 0, arr.size()-1,0);
	
	return 0;
}