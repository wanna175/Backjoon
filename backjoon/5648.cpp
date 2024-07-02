#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int N;
vector<long long> vec;
long long reverse(long long n) {
	int num;
	long long answer = 0;
	while (n!=0) {
		num = (int)(n % 10);
		n /= 10;
		answer *= 10;
		if (num == 0) continue;
		answer += num;
	}
	return answer;
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; ++i) {
		long long num;
		cin >> num;
		vec.push_back(reverse(num));
	}
	sort(vec.begin(), vec.end());
	for (long long v : vec)
		cout << v << '\n';
	return 0;
}