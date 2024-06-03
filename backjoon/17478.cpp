#include<iostream>
#include<string>
using namespace std;
int N;
string str1 = "\"재귀함수가 뭔가요?\"\n";
string str2 = "\"잘 들어보게. 옛날옛날 한 산 꼭대기에 이세상 모든 지식을 통달한 선인이 있었어.\n";
string str3 = "마을 사람들은 모두 그 선인에게 수많은 질문을 했고, 모두 지혜롭게 대답해 주었지.\n";
string str4 = "그의 답은 대부분 옳았다고 하네. 그런데 어느 날, 그 선인에게 한 선비가 찾아와서 물었어.\"\n";
string str5 = "라고 답변하였지.\n";
string str6 = "\"재귀함수는 자기 자신을 호출하는 함수라네\"\n";
void recursiveFunction(int n) {
	string t = "";
	string tmp = "____";
	for (int i = 0; i < n; ++i)
		t += tmp;
	if (n == N) {
		cout << t + str1;
		cout << t + str6;
		cout << t + str5;
		return;
	}
	
	cout << t + str1 + t + str2 + t + str3 + t + str4;
	recursiveFunction(n + 1);
	cout << t + str5;
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	cout << "어느 한 컴퓨터공학과 학생이 유명한 교수님을 찾아가 물었다.\n";
	recursiveFunction(0);
	return 0;
}