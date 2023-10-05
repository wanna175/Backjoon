#include <iostream>
#include <memory.h>
#include <cmath>
#include <vector>
using namespace std;
int arr[1000001];
bool isPrime[1000001];
void solve(long long _min,long long _max) {
	memset(isPrime, true, 1000001);
	isPrime[1] = false;
	for (int i = 2; i <= sqrt(1000001); ++i) {
		if (!isPrime[i]) continue;
		for (int j = 2 * i; j <= 1000000; j += i)
			isPrime[j] = false;
	}
	
	vector<long long> squarePrime;
	for (long long i = 2; i <= 1000000; ++i) {
		if (isPrime[i]) {
			long long tmp = i * i;
			if (tmp > _max)
				break;
			squarePrime.push_back(tmp);
		}
	}
	
	for (int i = 0; i < squarePrime.size(); ++i) {
		long long n = _min / squarePrime[i];
		for (long long j = n * squarePrime[i]; j <= _max; j+=squarePrime[i]) {
			if(j>=_min)
				arr[j-_min] = 1;
		}
	}

}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	long long _max, _min;
	cin >> _min >> _max;
	solve(_min, _max);
	long long ret = 0;
	for (long long i = 0; i <= _max - _min; ++i)
		if (arr[i] == 0)
			ret++;
	cout << ret;
	return 0;
}