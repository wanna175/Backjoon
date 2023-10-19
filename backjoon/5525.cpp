#include <iostream>
#include <string>
using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int N, M,answer=0;
	string S;
	cin >> N >> M >> S;
	int n=0;
	for (int i = 0; i < M; ++i) {
		if (S[i] == 'O')
			continue;
		else {
			while (i+2<M && S[i + 1] == 'O' && S[i + 2] == 'I') {
				n++;
				if (n == N) {
					n--;
					answer++;
				}
				i += 2;
			}
			n = 0;
		}
	}

	cout << answer;
	return 0;
}