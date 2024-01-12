#include<iostream>
#include<algorithm>
using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int arr[10];
	fill(arr, arr + 10, 0);
	int N;
	cin >> N;
	while (N!=0) {
		arr[N%10]++;
		N /= 10;
	}
	arr[6] += arr[9];
	arr[6] = arr[6] / 2 + arr[6] % 2;
	int answer=0;
	for (int i = 0; i < 9; ++i) {
		if (answer < arr[i])
			answer = arr[i];
	}
	cout << answer;
	return 0;
}