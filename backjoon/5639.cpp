#include <iostream>
#include <vector>

using namespace std;
void solve(vector<int>& v) {
	vector<int> left;
	vector<int> right;
	int root = v[0];
	if (v.size() == 1) {
		cout << root<<'\n';
		return;
	}
	for (int i = 1; i < v.size(); ++i) {
		if (v[i] < root)
			left.push_back(v[i]);
		else
			right.push_back(v[i]);
	}
	v.clear();
	vector<int>().swap(v);
	if(left.size()>0)
		solve(left);
	if(right.size()>0)
		solve(right);
	cout << root << '\n';
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int tmp;
	vector<int> answer;
	while (cin >> tmp) {
		answer.push_back(tmp);
	}
	solve(answer);
	return 0;
}