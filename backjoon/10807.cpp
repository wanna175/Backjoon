#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	int N,v;
	int arr[101];
	fill(arr, arr + 101, 0);
	cin >> N;
	int answer = 0;
	for (int i = 0; i < N; ++i)
		cin >> arr[i];
	cin >> v;
	for (int i = 0; i < N; ++i)
		if (arr[i] == v)
			answer++;
	cout << answer;
	return 0;
}