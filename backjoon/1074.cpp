#include <iostream>
#include <cmath>
using namespace std;
int countZArr(int row, int col, int size) {
	if (size == 1) {
		if (row == 0 && col == 0)
			return 1;
		else if (row == 0 && col == 1)
			return 2;
		else if (row == 1 && col == 0)
			return 3;
		else
			return 4;
	}
	size--;
	int idx = pow(2, size);
	if (idx > row && idx > col)
		return countZArr(row, col, size);
	else if (idx > row && idx <= col)
		return pow(idx,2) + countZArr(row, col - idx, size);
	else if (idx <= row && idx > col)
		return pow(idx,2) * 2 + countZArr(row - idx, col, size);
	else
		return pow(idx,2) * 3 + countZArr(row - idx, col - idx, size);
}
int main(void) {
	int N, row, col;//가로 세로
	cin >> N >> row >> col;
	cout << countZArr(row, col, N) - 1;
	return 0;
}