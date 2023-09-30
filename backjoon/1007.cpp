#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <climits>
#include <cmath>
using namespace std;

long long Calculation_resultant_vector(int toPick,int idx,
	int N,vector<pair<int,int>>& pos) {
	if (toPick == 0) {
		long long x = 0, y = 0;
		for (int i = 0; i < N; ++i) {
			x += pos[i].first;
			y += pos[i].second;
		}
		return pow(x, 2) + pow(y, 2);
	}
	long long ret = LLONG_MAX;
	for (int i = idx; i < N-toPick; ++i) {
		pos[i].first = -pos[i].first;
		pos[i].second = -pos[i].second;
		ret = min(ret,Calculation_resultant_vector(toPick - 1, i + 1, N, pos));
		pos[i].first = -pos[i].first;
		pos[i].second = -pos[i].second;
	}
	return ret;
}
int main(void) {
	cout << setprecision(16);
	int T;
	cin >> T;
	vector<pair<int,int>> pos;
	vector<long double> answer;
	for (int i = 0; i < T; ++i) {
		int N;
		cin >> N;
		for (int j = 0; j < N; ++j) {
			int x, y;
			cin >> x >> y;
			pos.push_back(make_pair(x,y));
		}
		long long ret = Calculation_resultant_vector(N / 2, 0, N, pos);
		answer.push_back(sqrt(ret));
		pos.clear();
	}
	for (int i = 0; i < T; ++i)
		cout << answer[i] << endl;
	return 0;
}