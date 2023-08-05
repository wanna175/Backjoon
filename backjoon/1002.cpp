#include <iostream>
#include <cmath>
#include <cstdlib>
#include <vector>

using namespace std;

int intersection_of_two_circles(vector<int> circles) {
	int distance = pow(circles[0] - circles[3], 2) + pow(circles[1] - circles[4], 2);
	int cond1 = pow(circles[2] + circles[5], 2);
	int cond2 = pow(circles[2] - circles[5], 2);
	if (distance == 0 && cond2 == 0)
		return -1;
	else if (cond1 > distance && distance > cond2)
		return 2;
	else if (cond1 == distance || distance == cond2)
		return 1;
	else
		return 0;
}
int main(void) {
	int T;
	vector<int> answer;
	cin >> T;
	for (int i = 0; i < T; i++) {
		vector<int> circles(6);
		cin >> circles[0] >> circles[1] >> circles[2] >> circles[3] >> circles[4] >> circles[5];
		answer.push_back(intersection_of_two_circles(circles));
	}
	for (int i = 0; i < T; i++) {
		cout << answer[i] << endl;
	}

	return 0;
}