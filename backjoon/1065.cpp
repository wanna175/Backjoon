#include <iostream>

using namespace std;

int main(void) {
	int N;
	cin >> N;
	if (N < 100) {
		cout << N;
		return 0;
	}
	int hundred = N / 100;
	int ten = N / 10;
	int answer = 99;
	for (int i = 1; i <= hundred; ++i) {
		for (int j = 0; j < 10; ++j) {
			int d = i - j;
			if (j - d >= 0 && j - d < 10)
				if (i != hundred||i*100+j*10+j-d<=N)
					answer++;
		}
	}
	cout << answer;
	return 0;
}