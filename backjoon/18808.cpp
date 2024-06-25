#include<iostream>
#include<algorithm>
#include<map>
using namespace std;
int N, M, K;
int sticker[100][10][10];
map<int,pair<int, int>> stickerMap;
int board[40][40];
int answer;
bool tryAttach0(int y,int x,int idx) {
	for(int i=y,_i=0;_i<stickerMap[idx].first;++i,++_i)
		for (int j = x,_j=0; _j < stickerMap[idx].second; ++j,++_j) {
			if (sticker[idx][_i][_j] == -1 || sticker[idx][_i][_j] == 0) continue;
			if (i >= N || i < 0 || j >= M || j < 0) return false;
			if (board[i][j] == 1) return false;
		}
	for (int i = y, _i = 0; _i < stickerMap[idx].first; ++i, ++_i)
		for (int j = x, _j = 0; _j < stickerMap[idx].second; ++j, ++_j) {
			board[i][j] = (sticker[idx][_i][_j] == 1) ? 1 : board[i][j];
		}
	return true;
}

bool tryAttach90(int y, int x, int idx) {
	for (int i = y, _i = 0; _i <stickerMap[idx].second; ++i, ++_i)
		for (int j = x, _j = stickerMap[idx].first -1; _j >= 0; ++j, --_j) {
			if (sticker[idx][_j][_i] == -1 || sticker[idx][_j][_i] == 0) continue;
			if (i >= N || i < 0 || j >= M || j < 0) return false;
			if (board[i][j] == 1) return false;
		}
	for (int i = y, _i = 0; _i < stickerMap[idx].second; ++i, ++_i)
		for (int j = x, _j = stickerMap[idx].first - 1; _j >= 0; ++j, --_j)
			board[i][j] = (sticker[idx][_j][_i] == 1) ? 1 : board[i][j];
	return true;
}
bool tryAttach180(int y, int x, int idx) {
	for (int i = y, _i = stickerMap[idx].first -1; _i >=0; ++i, --_i)
		for (int j = x, _j = stickerMap[idx].second -1; _j >= 0; ++j, --_j) {
			if (sticker[idx][_i][_j] == -1 || sticker[idx][_i][_j] == 0) continue;
			if (i >= N || i < 0 || j >= M || j < 0) return false;
			if (board[i][j] == 1) return false;
		}
	for (int i = y, _i = stickerMap[idx].first - 1; _i >= 0; ++i, --_i)
		for (int j = x, _j = stickerMap[idx].second - 1; _j >= 0; ++j, --_j)
			board[i][j] = (sticker[idx][_i][_j] == 1) ? 1 : board[i][j];
	return true;
}
bool tryAttach270(int y, int x, int idx) {
	for (int i = y, _i = stickerMap[idx].second -1; _i >=0; ++i, --_i)
		for (int j = x, _j = 0; _j < stickerMap[idx].first; ++j, ++_j) {
			if (sticker[idx][_j][_i] == -1 || sticker[idx][_j][_i] == 0) continue;
			if (i >= N || i < 0 || j >= M || j < 0) return false;
			if (board[i][j] == 1) return false;
		}
	for (int i = y, _i = stickerMap[idx].second - 1; _i >= 0; ++i, --_i)
		for (int j = x, _j = 0; _j < stickerMap[idx].first; ++j, ++_j)
			board[i][j] = (sticker[idx][_j][_i] == 1) ? 1 : board[i][j];
	return true;
}
bool tryAttach(int idx, bool (*fun)(int, int, int)) {
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < M; ++j) {
			if (fun(i, j, idx)) return true;
		}
	return false;
}
void Answer() {
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < M; ++j)
			if (board[i][j] == 1) answer++;
}
void attach(int idx) {
	if (idx >= K) {
		Answer();
		return;
	}
	bool isAttach = false;
	isAttach = tryAttach(idx, tryAttach0);
	isAttach = isAttach ? true : tryAttach(idx, tryAttach90);
	isAttach = isAttach ? true : tryAttach(idx, tryAttach180);
	isAttach = isAttach ? true : tryAttach(idx, tryAttach270);
	//ºÙÀÌ±â.
	attach(idx + 1);
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	fill_n(&sticker[0][0][0], 10000, -1);
	cin >> N >> M >> K;
	for (int i = 0; i < K; ++i) {
		int y, x;
		cin >> y >> x;
		stickerMap[i] = { y,x };
		for (int j = 0; j < y; ++j)
			for (int k = 0; k < x; ++k)
				cin >> sticker[i][j][k];
	}
	attach(0);
	cout << answer;
	return 0;
}