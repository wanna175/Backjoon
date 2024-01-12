#include <iostream>
#include <vector>
using namespace std;
int num[2000] = { 0 };
int N;
bool isPalin[2001][2001] = { false };
void make_Palindrome() {
	for (int i = 1; i <= N; ++i)
		isPalin[i][i] = true;
	for (int i = 1; i < N; ++i)
		if (num[i - 1] == num[i]) isPalin[i][i + 1] = true;
	for (int size = 3; size <= N; ++size) {
		for (int i = 1; i <= N - size + 1; ++i)
			if (num[i - 1] == num[i + size - 2] && isPalin[i + 1][i + size - 2])
				isPalin[i][i + size - 1] = true;
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; ++i)
		cin >> num[i];
	make_Palindrome();
	int M;
	cin >> M;
	for (int i = 1; i <= M; ++i) {
		int s, e;
		cin >> s >> e;
		cout << isPalin[s][e] << '\n';
	}
	return 0;
}