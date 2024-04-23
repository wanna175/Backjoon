#include<iostream>
#include<vector>

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int N;
	cin >> N;
	int answer = 0;
	vector<pair<int, int>> stack;
	stack.push_back({ 0,0 });
	for (int i = 0; i <= N; ++i) {
		int height = 0;
		if (i != N)
			cin >> height;
		int width = 0;
		while (height < stack.back().first) {
			width += stack.back().second;
			int area = stack.back().first * width;
			stack.pop_back();
			if (answer < area) answer = area;
		}
		stack.push_back({ height,width + 1 });
	}

	cout << answer << '\n';
	return 0;
}