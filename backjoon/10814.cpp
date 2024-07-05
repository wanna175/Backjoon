#include<iostream>
#include<algorithm>
#include<map>
#include<vector>
#define pis pair<int,string>
using namespace std;
int N;
vector<pis> vec;
bool compare(pis a,pis b) {
	return a.first < b.first;
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; ++i) {
		int n;
		string str;
		cin >> n >> str;
		vec.push_back({ n,str });
	}
	stable_sort(vec.begin(), vec.end(), compare);
	for (pis i : vec)
		cout << i.first << " " << i.second << '\n';
	return 0;
}