#include<iostream>
#include<string>
using namespace std;
int N;
string str1 = "\"����Լ��� ������?\"\n";
string str2 = "\"�� ����. �������� �� �� ����⿡ �̼��� ��� ������ ����� ������ �־���.\n";
string str3 = "���� ������� ��� �� ���ο��� ������ ������ �߰�, ��� �����Ӱ� ����� �־���.\n";
string str4 = "���� ���� ��κ� �ǾҴٰ� �ϳ�. �׷��� ��� ��, �� ���ο��� �� ���� ã�ƿͼ� ������.\"\n";
string str5 = "��� �亯�Ͽ���.\n";
string str6 = "\"����Լ��� �ڱ� �ڽ��� ȣ���ϴ� �Լ����\"\n";
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
	cout << "��� �� ��ǻ�Ͱ��а� �л��� ������ �������� ã�ư� ������.\n";
	recursiveFunction(0);
	return 0;
}