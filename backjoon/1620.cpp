#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M;
	cin >> N >> M;
	vector<string> pokemon(N+1,"");
	map<string, int> pokemon_num;
	vector<string> answer(M, "");
	for (int i = 1; i <= N; ++i) {
		cin >> pokemon[i];
		pokemon_num[pokemon[i]] = i;
	}
	for (int i = 0; i < M; ++i)
		cin >> answer[i];
	for (int i = 0; i < M; ++i) {
		if (isdigit(answer[i][0])) {
			int tmp = stoi(answer[i]);
			cout<< pokemon[tmp]<<'\n';
		}
		else {
			cout<<pokemon_num[answer[i]]<<'\n';
		}
	}
	return 0;
}