#include <iostream>
#include <vector>
#include <map>
using namespace std;
int V,first=0,Value=0;
map<int, vector<int>> graph;
int solve(int num, int cur,vector<bool>& path) {//트리의 지름
	path[num]=true;
	int ret=0;
	for (int i = 0; i<graph[num].size(); i+=2) {
		if (!path[graph[num][i]]) {
			ret = max(ret, solve(graph[num][i], cur + graph[num][i + 1], path));
		}
	}
	path[num] = false;
	if (ret == 0) {
		if (cur > Value) {
			Value = cur;
			first = num;
		}
		return cur;
	}
	
	return ret;
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> V;
	vector<bool> path(V + 1, false);
	for (int i = 1; i <= V; ++i) {
		int v,cnt=-1;
		cin >> v;
		while (true) {
			++cnt;
			int num;
			cin >> num;
			
			if (num != -1)
				graph[v].push_back(num);
			else break;
		}
	}
	solve(1, 0, path);
	cout << solve(first, 0, path);
	return 0;
}