#include<iostream>
#include<vector>
#include<string>
using namespace std;
int N;
int ns[1000];
int d[1000][2]; //max값과, 그 전 원소의 idx.
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; ++i) {
		cin >> ns[i];
		int tmp = -1;//이전 값들중 가장 긴 부분수열 길이
		for (int j = 0; j < i; ++j) {
			if (ns[i] <= ns[j]) continue;
			if (tmp >= d[j][0]) continue;
			tmp = d[j][0];
			d[i][0] = d[j][0] + 1;
			d[i][1] = j;
		}
	}
	
	int ans = -1, idx = -1;
	for (int i = 0; i < N; ++i) {
		if (d[i][0] <= ans) continue;
		ans = d[i][0];
		idx = i;
	}

	string str = "";
	for (int i = 0; i < ans+1; ++i) {
		str = to_string(ns[idx]) + " " + str;
		idx = d[idx][1];
	}

	cout << ans+1 << '\n';
	cout << str;

	return 0;
}