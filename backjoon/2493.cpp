#include<iostream>
#include<vector>
#define INF 100000001
using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int N;
	vector<pair<int,int>> stack;
	stack.push_back({ INF,0 });
	vector<int> answer;
	int prev_height = 0;
	cin >> N;
	for (int i = 0; i < N; ++i) {
		int height;
		cin >> height;
		if (prev_height > height) {
			stack.push_back({ prev_height,i });
			answer.push_back(i);
		}
		else {
			while (stack.back().first < height) {
				stack.pop_back();
			}
			answer.push_back(stack.back().second);
		}
		prev_height = height;
	}
	for (auto v : answer)cout << v << " ";
	return 0;
}