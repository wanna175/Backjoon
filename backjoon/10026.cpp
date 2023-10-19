#include <iostream>
#include <string>
using namespace std;
int N;
int picture[100][100] = { 0 };
int RGpicture[100][100] = { 0 };
int solve(int y,int x,int cur,int vec[100][100]) {
	if (y<0 || x<0 || y>N - 1 || x>N - 1 
		|| vec[y][x] != cur||cur==-1)
		return 0;
	vec[y][x] = -1;
	solve(y + 1, x, cur,vec);
	solve(y - 1, x, cur,vec);
	solve(y, x + 1, cur,vec);
	solve(y, x - 1, cur,vec);
	return 1;
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	int answer = 0, RGanswer = 0;
	for (int i = 0; i < N; ++i) {
		string tmp;
		cin >> tmp;
		for (int j = 0; j < N; ++j) {
			if (tmp[j] == 'G')
				picture[i][j] = 1;
			else if (tmp[j] == 'B') {
				RGpicture[i][j] = 1;
				picture[i][j] = 2;
			}
		}
	}
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			answer += solve(i, j, picture[i][j], picture);
			RGanswer+=solve(i, j, RGpicture[i][j], RGpicture);
		}
	}
	cout << answer << ' ' << RGanswer;

	return 0;
}