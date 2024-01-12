#include <iostream>
#include <cmath>
#include <memory.h>
using namespace std;
const int s = 4000001;
bool isPrime[s];
int N,ret=0;
void Sieve_of_Eratosthenes() {
	memset(isPrime, true, s);
	isPrime[1] = false;
	int n = 1;
	while (n<=sqrt(N)) {
		++n;
		if (!isPrime[n])
			continue;
		for (int i = 2; n * i <= N; ++i)
			isPrime[n * i] = false;
	}
}

void solve(int left, int right,int cur) {
	if (cur == N)
		++ret;
	if (right > N)
		return;
	if (cur <= N) {//right ÀÎµ¦½º Áõ°¡
		while (true) {
			++right;
			if (isPrime[right]) {
				cur += right;
				break;
			}
		}
	}
	else if(cur > N) {//left ÀÎµ¦½º Áõ°¡
		cur -= left;
		while (true) {
			++left;
			if (isPrime[left]) {
				break;
			}
		}
	}
	solve(left, right, cur);
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	Sieve_of_Eratosthenes();
	solve(2, 2, 2);
	cout << ret;
	return 0;
}