#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int num[50001] = { 0 };
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n,answer=4;
	vector<int> arr;
	cin >> n;
	for (int i = 1; i * i <= n; i++) {
		num[i * i] = 1;
		arr.push_back(i * i);
	}
	if (num[n] == 1) {
		cout << 1;
		return 0;
	}
	for(int i=0;i<arr.size();++i)
		for (int j = 0; j < arr.size(); ++j)
			for (int k = 0; k < arr.size(); ++k) {
				if (arr[j] + arr[k] == n) {
					cout << 2;
					return 0;
				}
				else if (arr[i] + arr[j] + arr[k] == n)
					answer = 3;
			}
	cout << answer;
	return 0;
}