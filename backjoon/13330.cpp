#include <iostream>

using namespace std;
int male[7];
int female[7];
int solve(int arr[],int K) {
	int answer = 0;
	for (int i = 1; i < 7; ++i) {
		if (arr[i] > K) {
			answer += arr[i] / K;
			if (arr[i] % K != 0)
				answer += 1;
		}
		else if (arr[i] > 0 && arr[i] <= K) {
			answer++;
		}
	}
	return answer;
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int N,K;
	cin >> N >> K;
	for (int i = 0; i < N; ++i) {
		int S, Y;
		cin >> S >> Y;
		if (S == 0)
			female[Y]++;
		else
			male[Y]++;
	}
	cout << solve(male, K) + solve(female, K);
	
	return 0;
}