#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
int N;
vector<string> arr;
int addNumber(string a) {
	int sum = 0;
	for (int i = 0; i < a.length(); ++i) {
		if ('A' <= a[i] && a[i] <= 'Z') continue;
		sum += (a[i] - '0');
	}
	return sum;
}
bool compare(string a, string b) {
	if (a.length() != b.length())
		return a.length() < b.length();

	int na = addNumber(a);
	int nb = addNumber(b);

	if (na != nb)
		return na< nb;
	
	return a < b;
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; ++i) {
		string str;
		cin >> str;
		arr.push_back(str);
	}

	sort(arr.begin(), arr.end(), compare);
	for (string v : arr)
		cout << v << '\n';
	return 0;
}