#include <iostream>
#include <vector>

using namespace std;
int N, M;
int graph[1001][1001] = { 0 };
bool DFS(vector<bool>& arr,int i) {
	if (arr[i])
		return false;
	arr[i] = true;
	for (int j = 1; j <= N; ++j)
		if (graph[i][j] == 1)
			DFS(arr, j);
	return true;
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int x, y,answer=0;
	cin >> N >> M;
	vector<bool> arr(N + 1, false);
	for (int i = 0; i < M; ++i) {
		cin >> x >> y;
		graph[x][y]++;
		graph[y][x]++;
	}
	for (int i = 1; i <= N; ++i)
		answer += (DFS(arr, i)) ? 1 : 0;
	cout << answer;
	return 0;
}