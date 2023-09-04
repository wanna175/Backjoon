#include <iostream>
#include <vector>
#include <string>

using namespace std;
int SumArr(int _i, int _j, int** Barr, int** Warr) {
	int Bsum = 0;
	int Wsum = 0;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			Bsum += Barr[_i + i][_j + j];
			Wsum += Warr[_i + i][_j + j];
		}
	}
	if (Wsum > Bsum)
		return Bsum;
	else
		return Wsum;
}
int main(void) {
	int answer = 65;
	int N, M;
	cin >> N >> M;
	int** Barr = new int* [N];
	int** Warr = new int* [N];
	for (int i = 0; i < N; i++) {
		Barr[i] = new int[M] {0};
		Warr[i] = new int[M] {0};
	}//이차원 배열 할당
	vector<string> panel;
	for (int i = 0; i < N; i++) {
		string temp;
		cin >> temp;
		panel.push_back(temp);
	}//입력 받음...

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if ((i + j) % 2 == 0) {
				if (panel[i][j] == 'B') {
					Warr[i][j]++;
				}
				else {
					Barr[i][j]++;
				}
			}
			else {
				if (panel[i][j] == 'B') {
					Barr[i][j]++;
				}
				else {
					Warr[i][j]++;
				}
			}
		}
	}//Warr,Barr셋팅...

	for (int i = 0; i <= N - 8; i++) {
		for (int j = 0; j <= M - 8; j++) {
			int sum = SumArr(i, j, Barr, Warr);
			if (answer > sum)
				answer = sum;
		}
	}
	cout << answer;

	for (int i = 0; i < N; i++) {
		delete[] Warr[i];
		delete[] Barr[i];
	}
	delete[] Warr;
	delete[] Barr;
	return 0;
}