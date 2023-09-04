#include <iostream>
#include <vector>

using namespace std;
void adjacent_idx(int x, int y, int** pos, int M, int N) {
	if (x < 0 || M - 1 < x || y < 0 || N - 1 < y)
		return;

	if (pos[x][y] == 1) {
		pos[x][y] = 0;
		adjacent_idx(x + 1, y, pos, M, N);
		adjacent_idx(x - 1, y, pos, M, N);
		adjacent_idx(x, y + 1, pos, M, N);
		adjacent_idx(x, y - 1, pos, M, N);
	}
}
int main(void) {
	int T;
	vector<int> total_answer;
	cin >> T;
	for (int i = 0; i < T; i++) {
		int M, N, K;
		int answer = 0;
		cin >> M >> N >> K;
		int** pos = new int* [M];
		for (int j = 0; j < M; j++)
			pos[j] = new int[N] {0};
		//이차원 배열 선언

		for (int j = 0; j < K; j++) {
			int X, Y;
			cin >> X >> Y;
			pos[X][Y] = 1;
		}
		//입력값 다 받음
		for (int j = 0; j < M; j++) {
			for (int k = 0; k < N; k++) {
				if (pos[j][k] == 1) {
					adjacent_idx(j, k, pos, M, N);
					answer++;
				}
			}
		}
		total_answer.push_back(answer);

		//동적할당 해제...
		for (int j = 0; j < M; j++) {
			delete[] pos[j];
		}
		delete[] pos;
	}
	for (int i = 0; i < T; i++) {
		cout << total_answer[i] << endl;
	}
	return 0;
}