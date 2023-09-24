#include <iostream>
#include <string>
#include <map>
using namespace std;
map<char, pair<int, int>> _move 
= { {'R',make_pair(1,0)},
	{'L',make_pair(-1,0)},
	{'T',make_pair(0,1)},
	{'B',make_pair(0,-1)} };
bool outOfRange(int x, int y) {
	if ((0 <= x && x < 8) && (0 <= y && y < 8))
		return false;
	return true;
}
int main(void) {
	pair<int, int> pos1, pos2;
	int N;
	string tmp1,tmp2;
	cin >> tmp1 >> tmp2 >> N;
	pos1 = make_pair(tmp1[0] - 'A', tmp1[1] - '1');
	pos2 = make_pair(tmp2[0] - 'A', tmp2[1] - '1');
	
	for (int i = 0; i < N; i++) {
		string tmp = "";
		cin >> tmp;
		int x = 0, y = 0;
		for (int j = 0; j < tmp.size(); j++) {
			x += _move[tmp[j]].first;
			y += _move[tmp[j]].second;
		}
		if (!outOfRange(pos1.first + x, pos1.second + y)) {
			if ((pos1.first + x == pos2.first) && (pos1.second + y == pos2.second)) {
				if (!outOfRange(pos2.first + x, pos2.second + y)) {
					pos1.first += x;
					pos1.second += y;
					pos2.first += x;
					pos2.second += y;
				}
			}
			else {
				pos1.first += x;
				pos1.second += y;
			}
		}
	}
	string answer1 = "";
	string answer2 = "";
	answer1 += (pos1.first + 'A');
	answer1 += (pos1.second + '1');
	answer2 += (pos2.first + 'A');
	answer2 += (pos2.second + '1');
	cout << answer1 << endl;
	cout << answer2;
	return 0;
}