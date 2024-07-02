#include<iostream>
#include<map>
#include<cmath>
#include<climits>
using namespace std;
long long N, answer = LLONG_MAX;
int cnt = 0;
map<long long, int> deck;
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> N;
	for (int i = 0; i < N; ++i) {
		long long n;
		cin >> n;
		deck[n]++;
		if (deck[n] == cnt)
			answer = min(answer, n);
		else if (deck[n] > cnt) {
			answer = n;
			cnt = deck[n];
		}
	}

	cout << answer;

	return 0;
}