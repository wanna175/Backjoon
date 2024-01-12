#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;
void fill_alpha(int arr[], const string& str) {
	fill(arr, arr + 26, 0);
	for (int i = 0; i < str.size(); ++i) {
		arr[str[i] - 'a']++;
	}
}
int solve_arr(int arr[], int arr2[]) {
	int answer = 0;
	for (int i = 0; i < 26; ++i) {
		if (arr[i] != arr2[i])
			answer+=abs(arr[i]-arr2[i]);
	}
	return answer;
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	string str1, str2;
	cin >> str1 >> str2;
	int alpha1[26], alpha2[26];
	fill_alpha(alpha1, str1);
	fill_alpha(alpha2, str2);
	cout << solve_arr(alpha1, alpha2);
	return 0;
}