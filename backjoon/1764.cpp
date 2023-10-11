#include <iostream>
#include <string>
#include <map>
using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N, M, ret = 0;
	map<string, int> arr;
	cin >> N >> M;
	for (int i = 0; i < N; ++i) {
		string tmp;
		cin >> tmp;
		arr[tmp] = 0;
	}
	for(int i=0;i<M;++i){
		string tmp;
		cin >> tmp;
		if (arr.find(tmp) != arr.end()) {
			ret++;
			arr[tmp]++;
		}
	}
	cout << ret << '\n';
	for (map<string, int>::iterator it = arr.begin(); it != arr.end(); ++it) {
		if (it->second != 0)
			cout << it->first << '\n';
	}
	return 0;
}