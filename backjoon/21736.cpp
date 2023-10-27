#include <iostream>
#include <string>
using namespace std;
int N, M, answer;
int cache[600][600] = { 0 };
void solve(int y, int x) {
	if (y<0 || x<0 || y>N - 1 || x>M - 1||cache[y][x]==-1)
		return;
	if (cache[y][x] == 2)
		answer++;
	cache[y][x] = -1;
	solve(y + 1, x);
	solve(y - 1, x);
	solve(y, x + 1);
	solve(y, x - 1);
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	answer = 0;
	cin >> N >> M;
	int y=0, x=0;
	for (int i = 0; i < N; ++i) {
		string tmp;
		cin >> tmp;
		for (int j = 0; j < M; ++j) {
			switch (tmp[j])
			{
			case 'X':
				cache[i][j] = -1;
				break;
			case 'P':
				cache[i][j] = 2;
				break;
			case 'I':
				cache[i][j] = 1;
				y = i; x = j;
				break;
			}
		}
	}
	solve(y, x);
	if (answer == 0)
		cout << "TT";
	else
		cout << answer;
	return 0;
}