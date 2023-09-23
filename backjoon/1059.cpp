#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
	int L;
	cin >> L;
	vector<int> S;
	for (int i = 0; i < L; i++) {
		int tmp;
		cin >> tmp;
		S.push_back(tmp);
		sort(S.begin(), S.end());
	}
	int n;
	cin >> n;
	int answer = 0;
	int ldx=-1 , rdx = -1;
	for (int i = 0; i < L; i++) {
		if (n == S[i]) {
			cout << answer;
			return answer;
		}
		else if (S[i] < n)
			ldx = i;
		else if (S[i] > n) {
			rdx = i;
			break;
		}
	}

	rdx = S[rdx] - 1;
	ldx = (ldx == -1) ? 1 : S[ldx]+1;
	answer += (n - ldx) * (rdx - n) + rdx - ldx;
	cout << answer;
	return 0;
}