#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
void fill_alpha(int arr[],const string& str) {
	fill(arr, arr + 26, 0);
	for (int i = 0; i < str.size(); ++i) {
		arr[str[i] - 'a']++;
	}
}
bool cmp_arr(int arr[], int arr2[]) {
	for (int i = 0; i < 26; ++i) {
		if (arr[i] != arr2[i])
			return false;
	}
	return true;
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int N;
	cin >> N;
	int alpha1[26];
	int alpha2[26];
	for (int i = 0; i < N; ++i) {
		string str1, str2;
		cin >> str1 >> str2;
		fill_alpha(alpha1, str1);
		fill_alpha(alpha2, str2);
		if (cmp_arr(alpha1, alpha2))
			cout << "Possible" << '\n';
		else
			cout << "Impossible" << '\n';
	}
	return 0;
}