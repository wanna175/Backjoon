#include <iostream>
#include <map>
using namespace std;
long long mod = 1000000007;
map<long long, long long> cache;
long long solve(long long n) {
	if (cache[n])return cache[n];
	long long ret;
	if (n % 2 == 0)
		ret = solve(n / 2)*solve(n / 2 - 1)%mod+solve(n/2)*solve(n/2+1)%mod;
	else
		ret = solve((n - 1)/2)*solve((n-1)/2)%mod + solve((n - 1) / 2+1) * solve((n - 1) / 2+1)%mod;
	return cache[n]=ret%mod;
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long long n;
	cin >> n;
	cache[0] = 0;
	cache[1] = 1;
	cache[2] = 1;
	cout<<solve(n);
	return 0;
}