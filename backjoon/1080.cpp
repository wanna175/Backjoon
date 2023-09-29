#include <iostream>
#include <vector>
#include <string>
using namespace std;
void Cover(int i, int j, vector<vector<int>>& A) {
	for (int I = 0; I < 3; ++I)
		for (int J = 0; J < 3; ++J)
			A[i + I][j + J] = (A[i + I][j + J] == 1) ? 0 : 1;
}
int ConvertMatrix(int i,int j,int current,vector<vector<int>>& A, vector<vector<int>>& B) {
	bool isSame = true, notSame = true;
	if (i + 3 > A.size()) {
		for (int idx = i; idx < A.size(); ++idx)
			for (int k = 0; k < A[0].size(); ++k)
				if (A[idx][k] != B[idx][k])
					return -1;
		return current;
	}
	int ret;
	int next_i = i, next_j = j+1;
	
	if(next_j+3>A[0].size()){
		next_j = 0;
		next_i++;
	}
	if (j+3==A[0].size()) {
		for (int idx = j; idx < A[0].size(); ++idx) {
			if (A[i][idx] != B[i][idx]) {
				isSame = false;
			}
			else {
				notSame = false;
			}
		}
		if (!isSame && !notSame)
			return -1;
	}
	else {
		isSame = (A[i][j] == B[i][j]) ? true : false;
	}

	if(isSame)
		ret = ConvertMatrix(next_i, next_j, current, A, B);
	else {
		Cover(i, j, A);
		ret= ConvertMatrix(next_i, next_j, current + 1, A, B);
	}
	return ret;
}

int main(void) {
	int N, M;
	cin >> N>> M;
	vector<vector<int>> matrixA(N, vector<int>(M, 0));
	vector<vector<int>> matrixB(N, vector<int>(M, 0));
	for (int i = 0; i < N; ++i) {
		string tmp;
		cin >> tmp;
		for (int j = 0; j < M; ++j)
			matrixA[i][j] = (tmp[j] == '0') ? 0 : 1;
	}
	for (int i = 0; i < N; ++i) {
		string tmp;
		cin >> tmp;
		for (int j = 0; j < M; ++j)
			matrixB[i][j] = (tmp[j] == '0') ? 0 : 1;
	}//ÀÔ·Â³¡...
	if (N < 3 || M < 3) {
		for(int i=0;i<N;++i)
			for(int j=0;j<M;++j)
				if (matrixA[i][j] != matrixB[i][j]) {
					cout << -1;
					return 0;
				}
		cout << 0;
		return 0;
	}
	int answer = ConvertMatrix(0, 0, 0, matrixA, matrixB);
	cout << answer;
	return 0;
}
