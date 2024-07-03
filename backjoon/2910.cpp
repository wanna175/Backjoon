#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;
int N, C;
map<int, int> m;
map<int, int> prior;
vector<int> v;
bool compare(int a, int b) {
	if(m[a]!=m[b])
		return m[a] > m[b];
	return prior[a] < prior[b];

}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> C;
	int cnt=0;
	for (int i = 0; i < N; ++i) {
		int num;
		cin >> num;
		m[num]++;
		v.push_back(num);
		if (m[num] == 1) prior[num] = cnt++;
	}
	sort(v.begin(), v.end(), compare);
	for (int i : v)
		cout << i << ' ';
	return 0;
}