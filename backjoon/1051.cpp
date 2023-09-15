#include <iostream>
#include <vector>
#include <string>
using namespace std;
bool IsSameNumber(int size, int i, int j, const vector<string>& rect) {
	char val = rect[i][j];
	if (rect[i + size - 1][j] == val && rect[i][j + size - 1] == val && rect[i + size - 1][j + size - 1] == val)
		return true;
	else
		return false;
}
int main(void) {
	int N, M;
	int answer = 1;
	vector<string> rect;
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		string tmp;
		cin >> tmp;
		rect.push_back(tmp);
	}

	for (int size = min(N, M); size > 1; size--) {
		for (int i = 0; i + size - 1 < N; i++) {
			for (int j = 0; j + size - 1 < M; j++) {
				if (IsSameNumber(size, i, j, rect)) {
					answer = size;
					size = 1;
					break;
				}
			}
			if (answer != 1)
				break;
		}
	}
	cout << answer * answer;
	return 0;
}