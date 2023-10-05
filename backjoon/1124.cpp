#include <iostream>
#include <cmath>
#include <cstring>

bool isPrime[100001];
int isDiv[100001] = { 0 };
using namespace std;
void Sieve_of_Eratosthenes(int n) {//아리스토테네스의 체
	memset(isPrime, true, 100001);
	isPrime[1] = false;
	for (int i = 2; i <= sqrt(n); ++i) {
		if (!isPrime[i]) continue;

		for (int j = 2 * i; j <= n; j += i) {
			isPrime[j] = false;
			if (isDiv[j] == 0)
				isDiv[j] = i;
		}
	}
}
int main(void) {
	int A, B,answer=0;
	cin >> A >> B;
	Sieve_of_Eratosthenes(B);
	for (int i = A; i <= B; ++i) {
		int count = 1;
		int num = i;
		while (!isPrime[num]) {
			num /= isDiv[num];
			count++;
		}
		if (isPrime[count])
			answer++;
	}
	cout << answer;
	return 0;
}