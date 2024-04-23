#include<iostream>
#include<vector>

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	while (true) {
		int N;
		cin >> N;
		if (N == 0)
			break;
		long long answer = 0;
		vector<pair<int, int>> stack;
		stack.push_back({ 0,0 });
		for (int i = 0; i <= N; ++i) {
			int height = 0;
			if(i!=N)
				cin >> height;
			int width = 0;
			while (height < stack.back().first) {
				width += stack.back().second;
				long long area = stack.back().first * (long long)width;
				stack.pop_back();
				if (answer < area) answer = area;
			}
			stack.push_back({ height,width + 1 });
		}

		cout << answer << '\n';
	}
	return 0;
}