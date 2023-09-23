#include <iostream>
#include <string>

using namespace std;
int CountFriends(bool** Isfriend, int idx,int N) {
	int ret = 0;
	for (int i = 0; i < N; i++) {
		if (Isfriend[idx][i])
			ret++;
		else if(idx!=i) {
			for (int j = 0; j < N; j++) {
				if (Isfriend[idx][j] && Isfriend[i][j]) {
					ret++;
					break;
				}
			}

		}
	}

	return ret;
}

int main(void) {
	int N;
	cin >> N;
	int answer = 0;
	bool** Isfriend = new bool* [N];
	for (int i = 0; i < N; i++) {
		Isfriend[i] = new bool[N];
		string tmp = "";
		cin >> tmp;
		for (int j = 0; j < N; j++)
			Isfriend[i][j] = (tmp[j] == 'N') ? false : true;
	}
	for (int i = 0; i < N; i++)
		answer = max(answer, CountFriends(Isfriend, i, N));

	cout << answer;
	for (int i = 0; i < N; i++) delete[] Isfriend[i];
	delete[] Isfriend;

	return 0;
}