#include<iostream>

using namespace std;
int N;
int T[16];
int P[16];
int total_pay = 0;
void backtracking(int date, int pay) {
	if (date > N) {
		total_pay = (total_pay < pay) ? pay : total_pay;
		return;
	}
	backtracking(date + 1, pay);
	if (date + T[date] <= N+1) backtracking(date + T[date], pay + P[date]);
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	for (int i = 1; i <= N; ++i)
		cin >> T[i] >> P[i];
	backtracking(1, 0);
	cout << total_pay;
	return 0;
}