#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
int number[10] = { 0 };
int digit(int N) {
	int ret = 0;
	if (N == 0)
		return 1;
	while (N >= 1) {
		N /= 10;
		ret++;
	}
	return ret;
}
int pick(vector<int>& num, int digit, int cur,int N) {
	if (digit == -1) {
		return abs(N - cur);
	}
	int ret = 10000000;
	for (int i = 0; i < num.size(); ++i) {
		cur += num[i] * pow(10, digit);
		ret = min(ret,pick(num, digit - 1, cur, N));
		cur -= num[i] * pow(10, digit);
	}
	return ret;
}
int solve(int N) {
	int ret = 10000000;
	vector<int> num;
	for (int i = 0; i < 10; ++i)
		if (number[i] == 0)
			num.push_back(i);
	int dig = digit(N),high=0,low=0,mid=10000000;
	if (num.size() == 0)
		return abs(N - 100);
	if (dig == 1) {
		for (int i = 0; i < dig +1; ++i) {
			if (i == dig && num[0] == 0&&num.size()>1)
				high += num[1] * pow(10, i);
			else
				high += num[0] * pow(10, i);
		}
		for (int i = 0; i < num.size(); ++i)
			ret = min(ret, abs(N - num[i]));
		if (high == 0)
			return min(ret + 1, N+1);
		return min(ret+1,high-N+2);
	}
	if (num.size()==1&&num[0]==0)
		return min(abs(N - 100),N+1);
	//높은 자리수
	for (int i = 0; i < dig+1; ++i) {
		if (i == dig && num[0] == 0)
			high += num[1] * pow(10, i);
		else
			high += num[0] * pow(10, i);
	}
	//낮은 자리수
	for (int i = 0; i < dig - 1; ++i)
		low += num[num.size() - 1] * pow(10, i);
	ret = min(high-N+dig+1, N-low+dig-1);
	//같은 자리수
	for (int i = 0; i < num.size(); ++i) {
		if (num[i] == 0)
			continue;
		mid = min(mid,pick(num, dig - 2, num[i] * pow(10, dig - 1), N));
	}
	return min(abs(N-100),min(mid+dig, ret));
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N,M;
	cin >> N >> M;
	for (int i = 0; i < M; ++i) {
		int tmp;
		cin >> tmp;
		number[tmp]++;
	}
	cout << solve(N);
	return 0;
}