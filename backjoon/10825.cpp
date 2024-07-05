#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;
struct student {
	string name;
	int kor;
	int eng;
	int math;
};
typedef struct student student_t;
int N;
vector<student_t> v;
bool compare(const student_t& a,const student_t& b) {
	if (a.kor != b.kor)
		return a.kor > b.kor;
	else if (a.eng != b.eng)
		return a.eng < b.eng;
	else if (a.math != b.math)
		return a.math > b.math;
	else
		return a.name < b.name;
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; ++i) {
		student_t s;
		cin >> s.name>>s.kor>>s.eng>>s.math;
		v.push_back(s);
	}
	sort(v.begin(), v.end(), compare);
	for (student_t n : v)
		cout << n.name << '\n';
	return 0;
}