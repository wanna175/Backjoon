#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>
using namespace std;
long double Round_parallelogram(vector<pair<int, int>>& pos, int v) {
	int round1 = -1, round2 = -1;
	for (int i = 0; i < 3; ++i) {
		if (i != v) {
			int r = pow(pos[v].first - pos[i].first, 2) +
				pow(pos[v].second - pos[i].second, 2);
			r *= 4;
			(round1 == -1) ? round1 = r : round2 = r;
		}
	}
	return sqrt((long double)round1) + sqrt((long double)round2);
}
int main(void) {
	cout << setprecision(16);
	vector<pair<int, int>> pos;
	for (int i = 0; i < 3; ++i) {
		int x, y;
		cin >> x >> y;
		pos.push_back(make_pair(x, y));
	}
	int dy = (pos[0].second - pos[1].second);
	int dx = (pos[0].first - pos[1].first);
	
	int dy2 = (pos[0].second - pos[2].second);
	int dx2 = (pos[0].first - pos[2].first);

	if (dy * dx2 == dx * dy2) {
		cout << -1;
		return 0;
	}
	
	long double minRound, maxRound;
	minRound = maxRound = Round_parallelogram(pos, 0);
	for (int i = 1; i < 3; ++i) {
		long double round = Round_parallelogram(pos, i);
		minRound = min(minRound, round);
		maxRound = max(maxRound, round);
	}
	cout << maxRound - minRound;
	return 0;
}