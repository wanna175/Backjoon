#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
int main(void) {
	int T;
	vector<int> answer;
	cin >> T;
	for (int i = 0; i < T; i++) {
		vector<int> pos_arr(4);
		vector<vector<int>> planetary_systems;
		int planetary_system_num;
		cin >> pos_arr[0] >> pos_arr[1] >> pos_arr[2] >> pos_arr[3];
		cin >> planetary_system_num;
		for (int j = 0; j < planetary_system_num; j++) {
			vector<int> circle(3);
			cin >> circle[0] >> circle[1] >> circle[2];
			planetary_systems.push_back(circle);
		}
		int num = 0;
		for (int j = 0; j < planetary_system_num; j++) {
			bool cond1 = pow(planetary_systems[j][0] - pos_arr[0], 2) + pow(planetary_systems[j][1] - pos_arr[1], 2) < pow(planetary_systems[j][2], 2);
			bool cond2 = pow(planetary_systems[j][0] - pos_arr[2], 2) + pow(planetary_systems[j][1] - pos_arr[3], 2) < pow(planetary_systems[j][2], 2);
			if ((cond1 && cond2) || (!cond1 && !cond2))
				continue;
			else
				num++;
		}
		answer.push_back(num);
	}
	for (int i = 0; i < T; i++) {
		cout << answer[i] << endl;
	}
	return 0;
}